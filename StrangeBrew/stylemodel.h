#ifndef STYLEMODEL_H
#define STYLEMODEL_H

#include <QAbstractListModel>
#include <QDebug>
#include "style.h"

class StyleModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Style> *m_data = NULL;
public:
    explicit StyleModel(QObject *parent = 0);

    //void setData(QList<Style> styleList);
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    void dataList(QList<Style> *styleList);
signals:

public slots:

};

#endif // STYLEMODEL_H
