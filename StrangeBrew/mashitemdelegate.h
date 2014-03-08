#ifndef MASHITEMDELEGATE_H
#define MASHITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QStyledItemDelegate>
#include <QComboBox>
#include <QTableView>

#include "mash.h"

class MashItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    QTableView *parent_item;
public:
    explicit MashItemDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    QString displayText(const QVariant &value, const QLocale &locale) const;
signals:

public slots:

};

#endif // MASHITEMDELEGATE_H
