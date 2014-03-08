#include "notesmodel.h"

NotesModel::NotesModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int NotesModel::rowCount(const QModelIndex &parent) const {
    if (m_data != NULL) {
        //qDebug() << "Note row Count " << m_data->count();
        return m_data->count();
    }
    return 0;
}

QVariant NotesModel::data(const QModelIndex &index, int role) const {
    //qDebug() << Qt::DisplayRole << " Data called " << role;
    Note s = m_data->at(index.row());
    if (role == Qt::ToolTipRole) {
        return s.getType() + " : " + s.getDate().toString();
    }

    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    return s.getType();
}

void NotesModel::dataList(QList<Note> *NoteList) {
    beginResetModel();
    m_data = NoteList;
    endResetModel();
}

bool NotesModel::insertRow(int row, const QModelIndex &parent) {
     beginInsertRows(QModelIndex(), row, row);
     Note m;
     m_data->append(m);
     endInsertRows();
     return true;
}


bool NotesModel::removeRow(int row, const QModelIndex &parent) {
    beginRemoveRows(QModelIndex(), row, row);
    m_data->removeAt(row);
    endRemoveRows();
    return true;
}
