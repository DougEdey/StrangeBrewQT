#ifndef MASHMODEL_H
#define MASHMODEL_H

#include <QAbstractTableModel>
#include <QMessageBox>
#include <QTableView>

#include <mash.h>
#include <brewcalcs.h>

class MashModel : public QAbstractTableModel
{
    Q_OBJECT
    Mash *m_data = NULL;
public:
    explicit MashModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void dataList(Mash *mashPtr);
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRow(int row, const QModelIndex &parent=QModelIndex());
    bool removeRow(int row, const QModelIndex &parent=QModelIndex());
signals:

public slots:

};

#endif // MASHMODEL_H
