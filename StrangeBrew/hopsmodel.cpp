#include "hopsmodel.h"

Qt::ItemFlags HopsModel::flags(const QModelIndex &index) const {

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

int HopsModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);

    if (m_data != NULL) {
        return m_data->count();
    }
    return 0;
}

int HopsModel::columnCount(const QModelIndex &) const
{
    return 9;
}

//Hop &HopsModel::getHop(const int index) {
//    return m_data.at(index);
//}

QVariant HopsModel::data(const QModelIndex &index, int role) const {

    if (role == Qt::ToolTipRole) {
        return SBStringUtils::multiLineToolTip(120, m_data->at(index.row())->getDescription());
    }
    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    Hop *hop = m_data->at(index.row());


    switch (index.column()) {
    case 0:
        return hop->getName();
    case 1:
        return hop->getType();
    case 2:
        return hop->getAlpha();
    case 3:
        return QString::number(hop->getAmount(), 'f', 2);
    case 4:
        return hop->getUnitsAbrv();
    case 5:
        return hop->getAdd();
    case 6:
        return hop->getMinutes();
    case 7:
        return QString::number(hop->getIBU(), 'f', 2);
    case 8:
        return hop->getCostPerU();
    default:
        return QVariant();
   };
}

QVariant HopsModel::headerData(int section, Qt::Orientation orientation, int role) const {
     if (orientation != Qt::Horizontal) return QVariant();
     if (role != Qt::DisplayRole) return QVariant();
     switch (section) {
     case 0:
         return "Name";
     case 1:
         return "Form";
     case 2:
         return "Alpha";
     case 3:
         return "Amount";
     case 4:
         return "Units";
     case 5:
         return "Add";
     case 6:
         return "Min";
     case 7:
         return "IBU";
     case 8:
         return "Cost/u";
     default:
         return QVariant();
     }
 }

void HopsModel::dataList(QList<Hop*> *hopList) {
    // Delete existing rows first
    beginResetModel();
    m_data = hopList;
    endResetModel();

}

bool HopsModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(role);

     Hop *h = m_data->at(index.row());

     QString currentText = value.toString();
     switch (index.column()) {
     case 0: {
         // Changed the name
         Hop *newHop = Database::findHop(currentText);
         if (newHop != NULL) {
             qDebug() << "Old Hop: " << h->getName();
             qDebug() << "New Hop: " << newHop->getName();
            h->setName(newHop->getName());
            h->setAlpha(newHop->getAlpha());
            h->setCost(newHop->getCostPerU());
         }
         break;
     }
     case 1:
        // changed the type
        h->setType(value.toString());
        break;
     case 2:
         h->setAlpha(value.toDouble());
         break;
     case 3:
         h->setAmount(value.toDouble());
         break;
     case 4:
         h->setUnits(value.toString());
         break;
     case 5:
         h->setAdd(value.toString());
         break;
     case 6:
         h->setMinutes(value.toInt());
         break;
     case 7:
         // No change
         break;
     case 8:
         h->setCost(value.toDouble());
         break;
     }

     m_data->replace(index.row(), h);

     if (m_data->size() > 0) {
         // We Want this in Descending order (first hops at the top)
        std::sort(m_data->begin(), m_data->end(), Hop::moreThan);
     }

     QModelIndex from = this->createIndex(0, 0);
     QModelIndex to = this->createIndex(m_data->size(), columnCount(index));

     emit dataChanged(from, to);
     return true;
 }


bool HopsModel::insertRow(int row, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row);
    Hop *h = new Hop();
    m_data->append(h);
    endInsertRows();
    return true;
}


bool HopsModel::removeRow(int row, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row);
    m_data->removeAt(row);
    endRemoveRows();
    return true;
}

