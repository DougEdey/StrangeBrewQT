#include "fermmodel.h"

FermModel::FermModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_data = NULL;
}

Qt::ItemFlags FermModel::flags(const QModelIndex &index) const {

    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

void FermModel::dataList(QList<FermentStep> *newData) {
    beginResetModel();
    m_data = newData;
    endResetModel();
}

int FermModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent); // All the columns are the same
    return 3;
}

int FermModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent) // All the rows are the same
    if (m_data == NULL) {
        return 0;
    }

    return m_data->size();
}

QVariant FermModel::headerData(int section, Qt::Orientation orientation, int role) const {
    // Type, Days, Temp
    if (orientation != Qt::Horizontal) return QVariant();

    if (role != Qt::DisplayRole) return QVariant();

    switch (section) {
    case 0:
        return "Type";
    case 1:
        return "Days";
    case 2:
        return "Temp";
    }

    return QVariant();
}

QVariant FermModel::data(const QModelIndex &index, int role) const {
    //Return temp units with the temp when displaying the content
    int i = index.row();

    if (role == Qt::ToolTipRole) {
        return QVariant();
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    FermentStep f = m_data->at(i);
    switch (index.column()) {
    case 0:
        return f.getType();
    case 1:
        return f.getTime();
    case 2: {
        if (role == Qt::EditRole) {
            return f.getTemp();
        }
        return QString::number(f.getTemp(), 'f', 0) + f.getTempU();
    }
    }

    return QVariant();
}

bool FermModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    if (role != Qt::EditRole)
        return false;

    int i = index.row();
    FermentStep f = m_data->at(i);
    switch (index.column()) {
    case 0:
        f.setType(value.toString());
        break;
    case 1:
        f.setTime(value.toInt());
        break;
    case 2:
        f.setTemp(value.toDouble());
        break;
    }

    m_data->replace(i, f);
    if (m_data->size() > 0) {
        // We Want this in Descending order (first hops at the top)
       std::sort(m_data->begin(), m_data->end(), FermentStep::lessThan);
    }

    QModelIndex from = index.sibling(0, 0);
    QModelIndex to = index.sibling(m_data->size(), columnCount(index));

    emit dataChanged(from, to);
    return true;
}


bool FermModel::insertRow(int row, const QModelIndex &parent) {
     beginInsertRows(parent, row, row);
     FermentStep f;
     m_data->append(f);
     endInsertRows();
     return true;
}


bool FermModel::removeRow(int row, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row);
    m_data->removeAt(row);
    endRemoveRows();
    return true;
}
