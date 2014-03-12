#ifndef FERMMODEL_H
#define FERMMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "fermentstep.h"

class FermModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<FermentStep> *m_data;
public:
    explicit FermModel(QObject *parent = 0);

    void dataList(QList<FermentStep> *newData);
    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRow(int row, const QModelIndex &parent=QModelIndex());
    bool removeRow(int row, const QModelIndex &parent=QModelIndex());
    Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

public slots:

};

#endif // FERMMODEL_H
