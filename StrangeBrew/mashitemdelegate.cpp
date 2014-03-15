#include "mashitemdelegate.h"

MashItemDelegate::MashItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
    parent_item = qobject_cast<QTableView*>(parent);
}

QWidget *MashItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    // Combobox only in columns 0 & 1 for the Hops model
    if (index.column() == 0 || index.column() == 1) {
        // Cast locally since we may need to know the value of other columns (0/1
        QComboBox *cb = new QComboBox(parent);

        if (index.column() == 0) {
            cb->addItems(mash_types);
        }

        if (index.column() == 1) {
            QModelIndex parentIndex = index.sibling(index.row(), 0);
            // Weight type
            qDebug() << "Setting method editor to " << parent_item->model()->data(parentIndex).toString();
            if (parent_item->model()->data(parentIndex).toString().compare(SPARGE) != 0) {
                cb->addItems(mash_methods);
            } else {
                cb->addItems(mash_spargeMethods);
            }
        }
        return cb;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);

}

void MashItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // are we in a combo box?
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        QString currentText = index.data(Qt::EditRole).toString();
        int cbIndex = cb->findText(currentText);

        qDebug() << "Looking for " << currentText << ". Found " << cbIndex;
        // if we're valid, adjust the selected value
        if (cbIndex == -1) {
            return;
        }

        cb->setCurrentIndex(cbIndex);
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }

}

void MashItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        model->setData(index, cb->currentText());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

}

QString MashItemDelegate::displayText(const QVariant &value, const QLocale &locale) const {
    Q_UNUSED(locale);
    return value.toString();
}
