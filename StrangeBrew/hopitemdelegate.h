#ifndef HOPITEMDELEGATE_H
#define HOPITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>

#include "database.h"

class HopItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit HopItemDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
signals:

public slots:

};

#endif // HOPITEMDELEGATE_H
