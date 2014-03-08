#include "newingrtable.h"

NewIngrTable::NewIngrTable(QObject *parent) :
    QAbstractTableModel(parent)
{
    qDebug() << "Creating new ingredient table";
}

void NewIngrTable::dataList(QList<Ingredient*> *data, std::vector<bool> *bList) {
    if (data == NULL) {
        qDebug() << "Null Data list";
        return;
    }
    beginInsertRows(QModelIndex(), 0, data->size()-1);
    this->m_enabled = bList;//.resize(data->size(), true);
    qDebug() << "Enabled: " << m_enabled->size();
    this->m_data = data;
    endInsertRows();

}

int NewIngrTable::rowCount(const QModelIndex &parent) const
{
    if (m_data != NULL) {
        return m_data->size();
    }
    return 0;
}

int NewIngrTable::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant NewIngrTable::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            qDebug() << index.row() << " Enabled " << &m_enabled << " Value: " << m_enabled->at(index.row());
            return QVariant(m_enabled->at(index.row()));
        case 1:
            return m_data->at(index.row())->getName();
        }
    }


    if (role != Qt::ToolTipRole) {
        return QVariant();
    }

    qDebug() << typeid(m_data->at(index.row())).name();
    /*const Hop *h = dynamic_cast<const Hop*>(i);
    // Do we have a hop?
    if (h != NULL) {
       return h->toString();
    }

    const Fermentable *f = dynamic_cast<const Fermentable*>(i);
    // Do we have a hop?
    if (f != NULL) {
        return f->toString();
    }

    const Misc *misc = dynamic_cast<const Misc*>(i);
    // Do we have a hop?
    if (misc != NULL) {
        return misc->toString();
    }

    const Yeast *y = dynamic_cast<const Yeast*>(i);
    // Do we have a hop?
    if (y != NULL) {
        return y->toString();
    }
*/
    return QVariant();
}

bool NewIngrTable::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column() != 0) {
        return false;
    }

    // we have the bool value

    m_enabled->at(index.row()) = value.toBool();
    emit dataChanged(index, index);
    return true;
}

QVariant NewIngrTable::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (orientation != Qt::Horizontal) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    switch (section) {
    case 0:
        return "Save";
    case 1:
        return "Name";
    }

    return QVariant();
}

Qt::ItemFlags NewIngrTable::flags(const QModelIndex &index) const
{
    if (index.column() == 0) {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }

    return Qt::ItemIsEnabled;
}
