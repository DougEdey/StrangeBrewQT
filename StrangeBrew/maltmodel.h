#ifndef MALTMODEL_H
#define MALTMODEL_H

#include <QAbstractTableModel>

#include "fermentable.h"
#include "database.h"

class MaltModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<Fermentable> *m_data = NULL;
    QString type;
public:
    explicit MaltModel(QObject *parent = 0, QString type = "") :
        QAbstractTableModel(parent)
    {
        this->type = type;
    }

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void dataList(QList<Fermentable> *maltList);
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    bool removeRow(int row, const QModelIndex &parent=QModelIndex());
    bool insertRow(int row, const QModelIndex &parent=QModelIndex());
signals:

public slots:

};

#endif // MALTMODEL_H
