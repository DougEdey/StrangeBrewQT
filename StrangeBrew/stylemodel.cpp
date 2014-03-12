#include "stylemodel.h"

StyleModel::StyleModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_data = NULL;
}

int StyleModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    if (m_data != NULL) {
        //qDebug() << "Style Count " << m_data->count();
        return m_data->count();
    }
    return 0;
}

QVariant StyleModel::data(const QModelIndex &index, int role) const {
    //qDebug() << Qt::DisplayRole << " Data called " << role;
    if (role == Qt::ToolTipRole) {
        Style *s = m_data->at(index.row());
        return s->getDescription();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    return m_data->at(index.row())->getName();
}

void StyleModel::dataList(QList<Style*> *styleList) {
    beginResetModel();
    m_data = styleList;
    endResetModel();

}
