#include "miscmodel.h"

Qt::ItemFlags MiscModel::flags(const QModelIndex &index) const {

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

int MiscModel::columnCount(const QModelIndex &) const {
    return 6;
}

int MiscModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    if (m_data != NULL) {
        return m_data->count();
    }
    return 0;
}

QVariant MiscModel::data(const QModelIndex &index, int role) const {

    Misc *m = m_data->at(index.row());

    if (role == Qt::ToolTipRole) {
        return SBStringUtils::multiLineToolTip(120, m->getComments());
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    switch (index.column()) {
    case 0:
        return m->getName();
    case 1:
        return m->getAmount();
    case 2:
        return m->getUnits();
    case 3:
        return m->getCostPerU();
    case 4:
        return m->getStage();
    case 5:
        return m->getTime();

    }

    return QVariant();
}

QVariant MiscModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    switch (section) {
    case 0:
        return "Name";
    case 1:
        return "Amount";
    case 2:
        return "Units";
    case 3:
        return "Cost/u";
    case 4:
        return "Stage";
    case 5:
        return "Time";
    }

    return QVariant();
}

bool MiscModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(role);
    Misc *m = m_data->at(index.row());

    qDebug() << index.row() << ":" << index.column() << " " << value.toString();

    switch (index.column()) {
    case 0: {
        // Find the misc item with this name
        // If the name has changed
        if (value.toString().compare(m->toString()) != 0) {
            Misc *newMisc = Database::findMisc(value.toString());
            if (newMisc == Database::miscDB.last()) {
                return false;
            }
            m->setName(value.toString());
            m->setCost((*newMisc).getCostPerU());
            m->setComments((*newMisc).getComments());
        }
        break;
    }
    case 1:
        m->setAmount(value.toDouble());
        break;
    case 2:
        m->setUnits(value.toString());
        break;
    case 3:
        m->setCost(value.toDouble());
        break;
    case 4:
        qDebug() << "Setting stage: " << value.toString();
        m->setStage(value.toString());
        break;
    case 5:
        m->setTime(value.toInt());
        break;
    }

    m_data->replace(index.row(), m);
    if (m_data->size() > 0) {
        std::sort(m_data->begin(), m_data->end(), Misc::lessThan);
    }
    emit dataChanged(index, index);
    return true;
}

void MiscModel::dataList(QList<Misc*> *miscList)
{
    beginResetModel();
    m_data = miscList;
    endResetModel();

}

bool MiscModel::insertRow(int row, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row);
    Misc *m = new Misc();
    m_data->append(m);
    endInsertRows();
    return true;
}


bool MiscModel::removeRow(int row, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row);
    m_data->removeAt(row);
    endRemoveRows();
    return true;
}
