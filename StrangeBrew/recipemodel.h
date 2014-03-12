#ifndef RECIPEMODEL_H
#define RECIPEMODEL_H

#include <QAbstractTableModel>
#include "BasicRecipe.h"
#include "sbstringutils.h"

class RecipeModel : public QAbstractTableModel
{
    Q_OBJECT
    QList<basicRecipe> *m_data;// = NULL;
public:
    explicit RecipeModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;
    int columnCount(const QModelIndex &) const;
    int rowCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void dataList(QList<basicRecipe> *data);
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
signals:

public slots:

};

#endif // RECIPEMODEL_H
