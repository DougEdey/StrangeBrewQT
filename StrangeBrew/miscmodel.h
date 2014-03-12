#ifndef MISCMODEL_H
#define MISCMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include "database.h"
#include "misc.h"

class MiscModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<Misc*> *m_data;

public:
    explicit MiscModel(QObject *parent = 0) :
        QAbstractTableModel(parent)
    {
        m_data = NULL;
    }

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void dataList(QList<Misc*> *miscList);
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    bool removeRow(int row, const QModelIndex &parent=QModelIndex());
    bool insertRow(int row, const QModelIndex &parent=QModelIndex());

signals:

public slots:

};

#endif // MISCMODEL_H
