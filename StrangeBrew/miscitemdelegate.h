#ifndef MISCITEMDELEGATE_H
#define MISCITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QTableView>
#include <QComboBox>

#include "database.h"
#include "misc.h"

class MiscItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    QTableView *parent_view;
public:
    explicit MiscItemDelegate(QTableView *parent = 0) :
        QStyledItemDelegate(parent)
    {
        parent_view = parent;
    }
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &viewItemOption, const QModelIndex &index) const;
    //bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
    //QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options, const QRect check_box_rect) const;

    QString displayText(const QVariant &value, const QLocale &locale) const;
signals:

public slots:

};

#endif // MISCITEMDELEGATE_H
