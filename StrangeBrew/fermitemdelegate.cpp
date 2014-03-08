#include "fermitemdelegate.h"

FermItemDelegate::FermItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}


QWidget *FermItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    // Combobox only in columns 0 & 1 for the Hops model
    if (index.column() == 0) {
        // Cast locally since we may need to know the value of other columns (0/1
        QComboBox *cb = new QComboBox(parent);

        cb->addItems(ferment_types);

        return cb;
    } else {
        QSpinBox *sb = new QSpinBox(parent);
        return sb;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);

}


void FermItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
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


void FermItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        model->setData(index, cb->currentText());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

}
