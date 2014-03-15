#include "mashmodel.h"

MashModel::MashModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_data = NULL;
}

Qt::ItemFlags MashModel::flags(const QModelIndex &index) const {

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    if (index.column() >= 0 && index.column() <= 2) {
        // Checkboxes
        Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        flags |= Qt::ItemIsUserCheckable;
        flags |= Qt::ItemIsEditable;
        flags |= Qt::ItemIsEnabled;
        flags |= Qt::ItemIsSelectable;
        return flags;
    }
    if (index.column() == 9)
        return QAbstractTableModel::flags(index) ^ Qt::ItemIsEditable;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

int MashModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    if (m_data != NULL) {
        return m_data->getStepSize();
    }
    return 0;
}

int MashModel::columnCount(const QModelIndex &) const
{
    return 10;
}

QVariant MashModel::data(const QModelIndex &index, int role) const {
    //"Type", "Method", "Start Temp", "End Temp",
    //"Ramp Min", "Step Min", "Weight", "In", "Out", "Temp"

    int i = index.row();

    if (role == Qt::ToolTipRole) {
        return SBStringUtils::multiLineToolTip(120, m_data->getStepDirections(i));
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();


    switch (index.column()) {
    case 0:
        return m_data->getStepType(i);
    case 1:
        return m_data->getStepMethod(i);
    case 2:
        return QString::number(m_data->getStepStartTemp(i), 'f', 1);
    case 3:
        return QString::number(m_data->getStepEndTemp(i), 'f', 1);
    case 4:
        return m_data->getStepRampMin(i);
    case 5:
        return m_data->getStepMin(i);
    case 6:
        return QString::number(m_data->getStepWeight(i), 'f', 0);
    case 7:
        return QString::number(m_data->getStepInVol(i), 'f', 1);
    case 8:
        return QString::number(m_data->getStepOutVol(i), 'f', 1);
    case 9:
        return QString::number(m_data->getStepTemp(i), 'f', 1);
    default:
        return QVariant();
   };
}

QVariant MashModel::headerData(int section, Qt::Orientation orientation, int role) const {
    //"Type", "Method", "Start Temp", "End Temp",
    //"Ramp Min", "Step Min", "Weight", "In", "Out", "Temp"
     if (orientation != Qt::Horizontal) return QVariant();
     if (role != Qt::DisplayRole) return QVariant();
     switch (section) {
     case 0:
         return "Type";
     case 1:
         return "Method";
     case 2:
         return "Start Temp";
     case 3:
         return "End Temp";
     case 4:
         return "Ramp Min";
     case 5:
         return "Step Min";
     case 6:
         return "Weight";
     case 7:
         return "In";
     case 8:
         return "Out";
     case 9:
         return "Temp";
     default:
         return QVariant();
     }
 }

void MashModel::dataList(Mash *mashPtr) {
    // Delete existing rows first
    beginResetModel();
    m_data = mashPtr;
    endResetModel();

}

bool MashModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    if (role != Qt::EditRole)
        return false;

    int i = index.row();
        //"Type", "Method", "Start Temp", "End Temp",
        //"Ramp Min", "Step Min", "Weight", "In", "Out", "Temp"

        if (index.column() == 0) {

            if (value.toString().compare(SPARGE) == 0 ) {
                qDebug() << "Sparge step selected";
            }

            QModelIndex typeIndex = index.sibling(index.row(), 1);
            qDebug() << data(typeIndex, Qt::DisplayRole).toString();


            // check if value is valid
            QString cSpargeStep = data(typeIndex, Qt::DisplayRole).toString();

            if (value.toString().compare(SPARGE) == 0 // is the  new selection value a sparge?
                && !mash_spargeMethods.contains(cSpargeStep, // if so, is the second column a valid sparge step?
                                                    Qt::CaseInsensitive))
            {
                // we have a sparge step and we're moving off it, give a warning if needed
                QSettings opts("Doug Edey", "StrangeBrew");
                if (opts.value("Application/timid", "True").toString().compare("True") == 0) {
                    QMessageBox::StandardButton reply;
                    QString message = "Changing the type of mash to " + value.toString() + " will change the method of this step."
                                        + "Do you wish to continue?";
                    reply = QMessageBox::question(0,
                                                "Change Type?",
                                                message,
                                                QMessageBox::Yes | QMessageBox::No);

                    if (reply == QMessageBox::Yes) {
                        m_data->setStepType(i, value.toString());
                        m_data->setStepMethod(i, mash_spargeMethods.at(0));
                    } else {
                        return false;
                    }
            }
        }
    }

     bool convertOK;
     switch (index.column()) {
     case 0:
         m_data->setStepType(i, value.toString());
         break;
     case 1:
        m_data->setStepMethod(i, value.toString());
        break;
     case 2:
         m_data->setStepStartTemp(i, value.toDouble(&convertOK));
         break;
     case 3:
         m_data->setStepEndTemp(i, value.toDouble(&convertOK));
         break;
     case 4:
         m_data->setStepRampMin(i, value.toInt(&convertOK));
         break;
     case 5:
         m_data->setStepMin(i, value.toInt(&convertOK));
         break;
     case 6:
         m_data->setStepWeight(i, value.toDouble(&convertOK));
         break;

     }

     // Should alert if convertOK is bad.

     if (m_data->getStepSize() > 0) {
        std::sort(m_data->steps.begin(), m_data->steps.end(), MashStep::lessThan);
     }

     qDebug() << "Replaced row at " << i;
     qDebug() << m_data->getStepStartTemp(i);

     emit dataChanged(index, index);
     return true;
}

bool MashModel::insertRow(int row, const QModelIndex &parent) {
     beginInsertRows(parent, row, row);
     m_data->addStep();
     endInsertRows();
     return true;
}


bool MashModel::removeRow(int row, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row);
    m_data->delStep(row);
    endRemoveRows();
    return true;
}
