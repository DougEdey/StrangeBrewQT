#include "recipemodel.h"

RecipeModel::RecipeModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_data = NULL;
}

bool RecipeModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return true;
}

Qt::ItemFlags RecipeModel::flags(const QModelIndex &index) const {
    Q_UNUSED(index);
    // All items are not editable, but are selectable
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int RecipeModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    if (m_data != NULL) {
        return m_data->count();
    }
    return 0;
}

int RecipeModel::columnCount(const QModelIndex &) const
{
    // when iterations do stuff, we'll return 4
    return 3;
}

QVariant RecipeModel::data(const QModelIndex &index, int role) const {

    if (role == Qt::ToolTipRole) {
        return SBStringUtils::multiLineToolTip(120, QString(m_data->at(index.row()).id));
    }

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    basicRecipe b = m_data->at(index.row());

    switch (index.column()) {
    case 0: return b.title;
    case 1: return b.style;
    case 2: return b.brewer;
    case 3: return b.iteration;
    }

    return QVariant();
}

QVariant RecipeModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
         return QVariant();
    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section) {
    case 0: return "Title";
    case 1: return "Style";
    case 2: return "Brewer";
    case 3: return "Iteration";
    }

    return QVariant();
}


void RecipeModel::dataList(QList<basicRecipe> *data) {
    beginResetModel();
    m_data = data;
    endResetModel();
}
