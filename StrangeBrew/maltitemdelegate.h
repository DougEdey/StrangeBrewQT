#ifndef MALTITEMDELEGATE_H
#define MALTITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QCheckBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QMouseEvent>
#include <QTableView>
#include "database.h"
#include "maltmodel.h"

class MaltItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    QTableView *parent_view;
public:
    explicit MaltItemDelegate(QTableView *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    QString displayText(const QVariant &value, const QLocale &locale) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &viewItemOption, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
    QRect CheckBoxRect(const QStyleOptionViewItem &view_item_style_options, const QRect check_box_rect) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:

public slots:
};


#endif // MALTITEMDELEGATE__H
