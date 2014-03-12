#include "hopitemdelegate.h"

HopItemDelegate::HopItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget* HopItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    QComboBox *cb = new QComboBox(parent);
    if (index.column() == 0) {
        Q_FOREACH(Hop *h, Database::hopsDB) {
            cb->addItem(h->getName());
        }
    } else if (index.column() == 1) {
        cb->addItem(HOP_PELLET);
        cb->addItem(HOP_LEAF);
        cb->addItem(HOP_PLUG);
    } else if (index.column() == 4) {
        // Weight type
        cb->addItem(CONVERTER_OZ);
        cb->addItem(CONVERTER_G);
        cb->addItem(CONVERTER_LB);
        cb->addItem(CONVERTER_KG);
    } else if (index.column() == 5) {
        // Addition type
        cb->addItem(HOP_MASH);
        cb->addItem(HOP_FWH);
        cb->addItem(HOP_BOIL);
        cb->addItem(HOP_DRY);
    } else {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
    return cb;
}

void HopItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // are we in a combo box?
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        QString currentText = index.data(Qt::EditRole).toString();
        int cbIndex = cb->findText(currentText);

        // if we're valid, adjust the selected value
        if (cbIndex > -1) {
            cb->setCurrentIndex(cbIndex);
        }
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }

}

void HopItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        model->setData(index, cb->currentText());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}
