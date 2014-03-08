#ifndef NEWINGRDELEGATE_H
#define NEWINGRDELEGATE_H

#include <QStyledItemDelegate>
#include <QApplication>
#include <QMouseEvent>
#include <QCheckBox>
#include <QTableView>

class NewIngrDelegate : public QStyledItemDelegate
{
    Q_OBJECT
     QTableView *parent_view;
public:
    explicit NewIngrDelegate(QTableView *parent = 0);

     QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options, const QRect check_box_rect) const;
     void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
     bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
     QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
     void setEditorData(QWidget *editor, const QModelIndex &index) const;
     void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
     QString displayText(const QVariant &value, const QLocale &locale) const;
signals:

public slots:

};

#endif // NEWINGRDELEGATE_H
