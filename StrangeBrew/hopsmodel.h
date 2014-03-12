#ifndef HOPSMODEL_H
#define HOPSMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <QList>

#include "database.h"
#include "hop.h"

class HopsModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<Hop*> *m_data;
public:
    explicit HopsModel(QObject *parent = 0) :
        QAbstractTableModel(parent)
    {
        m_data = NULL;
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    void append(int i, Hop &hop);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    //Hop &getHop(const int index);
    void dataList(QList<Hop*> *hopList);
    bool removeRow(int row, const QModelIndex &parent=QModelIndex());
    bool insertRow(int row, const QModelIndex &parent=QModelIndex());
signals:

public slots:

};

#endif // HOPSMODEL_H
