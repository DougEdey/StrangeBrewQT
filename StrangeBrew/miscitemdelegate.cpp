#include "miscitemdelegate.h"



QWidget *MiscItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // Combo Box is only in columns 0 and 2
    if (index.column() == 0) {
        QComboBox *cb = new QComboBox(parent);

        Q_FOREACH(Misc *item, Database::miscDB) {
            cb->addItem(item->getName());
        }

        return cb;
    }

    if (index.column() == 2) {
        QComboBox *cb = new QComboBox(parent);

        cb->addItem(CONVERTER_TSP);
        cb->addItem(CONVERTER_TBSP);
        cb->addItem(CONVERTER_G);
        cb->addItem(CONVERTER_OZ);
        cb->addItem(CONVERTER_KG);
        cb->addItem(CONVERTER_LB);

        return cb;
    }

    if (index.column() == 4) {
        QComboBox *cb = new QComboBox(parent);

        cb->addItem(MISC_MASH);
        cb->addItem(MISC_BOIL);
        cb->addItem(MISC_PRIMARY);
        cb->addItem(MISC_SECONDARY);
        cb->addItem(MISC_KEG);
        cb->addItem(MISC_BOTTLE);

        return cb;
    }
    // nothing special
    return QStyledItemDelegate::createEditor(parent, option, index);
}


void MiscItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
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

void MiscItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        model->setData(index, cb->currentText());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

}

void MiscItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &viewItemOption, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, viewItemOption, index);
}

QString MiscItemDelegate::displayText(const QVariant &value, const QLocale &locale) const {
    Q_UNUSED(locale);
    return value.toString();
}
