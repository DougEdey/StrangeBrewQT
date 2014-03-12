#ifndef NOTESMODEL_H
#define NOTESMODEL_H

#include <QAbstractListModel>
#include <QString>
#include <QDebug>

#include "note.h"

class NotesModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Note> *m_data;
public:
    explicit NotesModel(QObject *parent = 0);

    void dataList(QList<Note> *NoteList);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    bool insertRow(int row, const QModelIndex &parent=QModelIndex());
    bool removeRow(int row, const QModelIndex &parent=QModelIndex());
signals:

public slots:

};

#endif // NOTESMODEL_H
