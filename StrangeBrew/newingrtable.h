#ifndef NEWINGRTABLE_H
#define NEWINGRTABLE_H

#include <QAbstractTableModel>
#include <QDebug>
#include <fermentable.h>
#include <misc.h>
#include <hop.h>
#include <yeast.h>
#include <typeinfo>

class NewIngrTable : public QAbstractTableModel
{
    Q_OBJECT
    QList<Ingredient*> *m_data;
    std::vector<bool> *m_enabled;
public:
    explicit NewIngrTable(QObject *parent = 0);

signals:

public slots:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void dataList(QList<Ingredient *> *data, std::vector<bool> *bList);
};

#endif // NEWINGRTABLE_H
