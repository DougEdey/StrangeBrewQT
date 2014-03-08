#ifndef FERMITEMDELEGATE_H
#define FERMITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>
#include <QSpinBox>

#include "fermentstep.h"

class FermItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit FermItemDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
signals:

public slots:

};

#endif // FERMITEMDELEGATE_H
