#include "maltmodel.h"

Qt::ItemFlags MaltModel::flags(const QModelIndex &index) const {

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    if (type == "percent") {
        // In a percent model
        if (index.column() == 3) {
            return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
        }

        return QAbstractTableModel::flags(index) ^ Qt::ItemIsEditable;
    }

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

int MaltModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    if (m_data != NULL) {
        return m_data->count();
    }
    return 0;
}

int MaltModel::columnCount(const QModelIndex &) const
{
    if (type == "percent") {
     return 4;
    }
    return 10;
}

QVariant MaltModel::data(const QModelIndex &index, int role) const {
    //"S", "M", "Malt", "Amount", "Units", "Points",
    //           "Lov", "Cost/U", "%"
    if (role == Qt::ToolTipRole) {
        return SBStringUtils::multiLineToolTip(120, m_data->at(index.row())->getDescription());
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    Fermentable *f = m_data->at(index.row());

    if (type == "percent") {
        switch (index.column()) {
        case 0: return f->getName();
        case 1: return f->getPppg();
        case 2: return f->getLov();
        case 3: return f->getPercent();
        }
    }

    switch (index.column()) {
    case 0: {
        return f->getMashed();
    }
    case 1:
        return f->getSteep();
    case 2:
        return f->ferments();
    case 3:
        return f->getName();
    case 4:
        return QString::number(f->getAmount(), 'f', 2);
    case 5:
        return f->getUnitsAbrv();
    case 6:
        return f->getPppg();
    case 7:
        return f->getLov();
    case 8:
        return f->getCostPerU();
    case 9:
        return QString::number(f->getPercent(), 'f', 2);
    default:
        return QVariant();
   };
}

QVariant MaltModel::headerData(int section, Qt::Orientation orientation, int role) const {
     if (orientation != Qt::Horizontal) return QVariant();
     if (role != Qt::DisplayRole) return QVariant();

     if (type == "percent") {
         switch (section) {
         case 0: return "Name";
         case 1: return "PPPG";
         case 2: return "Lov";
         case 3: return "%";
         }
     }

     switch (section) {
     case 0:
         return "M";
     case 1:
         return "S";
     case 2:
         return "F";
     case 3:
         return "Name";
     case 4:
         return "Amount";
     case 5:
         return "Units";
     case 6:
         return "PPPG";
     case 7:
         return "Lov";
     case 8:
         return "Cost/U";
     case 9:
         return "Percent";
     default:
         return QVariant();
     }
 }

void MaltModel::dataList(QList<Fermentable*> *maltList) {
    beginResetModel();
    m_data = maltList;
    endResetModel();
}

bool MaltModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(role);

    Fermentable *f = m_data->at(index.row());

    if (type == "percent") {
        switch (index.column()) {
        case 0:
        case 1:
        case 2:
        break;
        case 3:
            f->setPercent(value.toDouble());
        }
    } else {

        switch (index.column()) {
        case 0:
            f->setMashed(value.toBool());
        case 1:
            // changed the mashed
            f->setSteep(value.toBool());
            break;
        case 2:
            f->ferments(value.toBool());
            break;
        case 3: {
            // Changed the name
            Fermentable *newMalt = Database::findFermentable(value.toString());
            if (newMalt != NULL) {
                qDebug() << "Old Hop: " << f->getName();
                qDebug() << "New Hop: " << newMalt->getName();
                f->setName(newMalt->getName());
                f->setPppg(newMalt->getPppg());
                f->setLov(newMalt->getLov());
                f->setMashed(newMalt->getMashed());
                f->setSteep(newMalt->getSteep());
                f->ferments(newMalt->ferments());
                f->setCost(newMalt->getCostPerU());
            }
            break;
        }

        case 4:
            f->setAmount(value.toDouble());
            break;
        case 5:
            f->setUnits(value.toString());
            break;
        case 6:
            f->setPppg(value.toDouble());
            break;
        case 7:
            f->setLov(value.toInt());
            break;
        case 8:
            f->setCost(value.toDouble());
            break;
        case 9:
            //h.setCost(value.toDouble());
            break;
        }
    }

    m_data->replace(index.row(), f);

    if (m_data->size() > 0) {
        std::sort(m_data->begin(), m_data->end(), Fermentable::lessThan);
    }

    qDebug() << "Replaced row at " << index.row();
    qDebug() << m_data->at(index.row())->getName();
    emit dataChanged(index, index);
    return true;
}

bool MaltModel::insertRow(int row, const QModelIndex &parent) {
    Q_UNUSED(parent);
     beginInsertRows(QModelIndex(), row, row);
     Fermentable *m = new Fermentable();
     m_data->append(m);
     endInsertRows();
     return true;
}


bool MaltModel::removeRow(int row, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginRemoveRows(parent, row, row);
    m_data->removeAt(row);
    endRemoveRows();
    return true;
}
