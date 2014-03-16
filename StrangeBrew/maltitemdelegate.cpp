#include "maltitemdelegate.h"

MaltItemDelegate::MaltItemDelegate(QTableView *parent) :
    QStyledItemDelegate(parent)
{
        parent_view = parent;
}

QSize MaltItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.column() <= 2) {
        qDebug() << "Setting column " << index.column() << " size " << option.rect.size().height();
        return QSize(6, option.rect.size().height());
    }

    return option.rect.size();
}

QRect MaltItemDelegate::CheckBoxRect(const QStyleOptionViewItem &view_item_style_options, const QRect check_box_rect) const {

    QStyleOptionButton check_box_style_option;

    //check_box_style_option |= Qt::AlignHCenter;
    //QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &check_box_style_option);
    QPoint check_box_point(view_item_style_options.rect.x() + view_item_style_options.rect.width() / 2 - check_box_rect.width() / 2,
                           view_item_style_options.rect.y() + view_item_style_options.rect.height() / 2 -
                           check_box_rect.height() / 2);
    return QRect(check_box_point, check_box_rect.size());
}

void MaltItemDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
      QStyleOptionViewItem viewItemOption(option);

      if (index.column() >= 0 && index.column() <= 2) {
          int value = index.model()->data(index, Qt::DisplayRole).toInt();

          QStyleOptionButton check_box_style_option;
          check_box_style_option.state |= QStyle::State_Enabled;
          if (value == 1) {
              check_box_style_option.state |= QStyle::State_On;
          } else {
              check_box_style_option.state |= QStyle::State_Off;
          }


            QRect check_box_rect = parent_view->visualRect(index);
          check_box_style_option.rect = MaltItemDelegate::CheckBoxRect(option, check_box_rect);
         // check_box_style_option.rect.setLeft(option.rect.x() + option.rect.width()/2 - check_box_style_option.rect.width()/2);


//          const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;
//          QRect newRect = QStyle::alignedRect(option.direction, Qt::AlignCenter,
//                                              QSize(option.decorationSize.width() + 5,option.decorationSize.height()),
//                                              QRect(option.rect.x() + textMargin, option.rect.y(),
//                                                    option.rect.width() - (2 * textMargin), option.rect.height()));
//          check_box_style_option.rect = newRect;


          QApplication::style()->drawControl(QStyle::CE_CheckBox, &check_box_style_option, painter);
      } else {
        QStyledItemDelegate::paint(painter, viewItemOption, index);
      }
}

bool MaltItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option,
                             const QModelIndex &index)
{
    Q_ASSERT(event);
    Q_ASSERT(model);

    // make sure that the item is checkable
    Qt::ItemFlags flags = model->flags(index);
    if (!(flags & Qt::ItemIsUserCheckable) || !(flags & Qt::ItemIsEnabled))
        return false;

    // make sure that we have a check state
    QVariant value = index.data(Qt::CheckStateRole);
    if (!value.isValid())
        return false;

    // make sure that we have the right event type
    if (event->type() == QEvent::MouseButtonRelease) {
        //const int textMargin = QApplication::style()->pixelMetric(QStyle::PM_FocusFrameHMargin) + 1;
        QRect check_box_rect = parent_view->visualRect(index);
        QRect checkRect = MaltItemDelegate::CheckBoxRect(option, check_box_rect);
        if (!checkRect.contains(static_cast<QMouseEvent*>(event)->pos()))
            return false;

    } else if (event->type() == QEvent::KeyPress) {
        if (static_cast<QKeyEvent*>(event)->key() != Qt::Key_Space&& static_cast<QKeyEvent*>(event)->key() != Qt::Key_Select)
            return false;
    } else {
        return false;
    }

    Qt::CheckState state = (static_cast<Qt::CheckState>(value.toInt()) == Qt::Checked
                            ? Qt::Unchecked : Qt::Checked);
    return model->setData(index, state, Qt::CheckStateRole);
}


QWidget *MaltItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    // Combobox only in columns 3 & 5 for the Hops model
    if (index.column() == 3 || index.column() == 5) {
        QComboBox *cb = new QComboBox(parent);
        if (index.column() == 3) {
            Q_FOREACH(Fermentable *f, Database::fermDB) {
                cb->addItem(f->getName());
            }
        }

        if (index.column() == 5) {
            // Weight type
            cb->addItem(CONVERTER_OZ);
            cb->addItem(CONVERTER_G);
            cb->addItem(CONVERTER_LB);
            cb->addItem(CONVERTER_KG);
        }
        return cb;
    }

    // Use checkbox for columns 0,1,2
    if (index.column() >= 0 && index.column() <= 2) {
        QCheckBox *cb = new QCheckBox(parent);
        return cb;
    }

    if (index.column() == 6) {
        // PPPG, so 3 DP
        QDoubleSpinBox *sb = new QDoubleSpinBox(parent);
        sb->setDecimals(3);
        return sb;
    }

    return QStyledItemDelegate::createEditor(parent, option, index);

}

void MaltItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // are we in a combo box?
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        QString currentText = index.data(Qt::EditRole).toString();
        int cbIndex = cb->findText(currentText);

        // if we're valid, adjust the selected value
        if (cbIndex > -1) {
            cb->setCurrentIndex(cbIndex);
        }
    } else if (index.column() >=0 && index.column() <= 2) {
        QCheckBox *cb = qobject_cast<QCheckBox *>(editor);
        cb->setChecked(index.data(Qt::EditRole).toBool());
    } else if (index.column() == 6) {
        // PPPG, so 3 DP
        QDoubleSpinBox *sb = qobject_cast<QDoubleSpinBox *>(editor);
        sb->setDecimals(3);
        sb->setValue(index.data(Qt::EditRole).toDouble());
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }

}

void MaltItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    if (QComboBox *cb = qobject_cast<QComboBox *>(editor)) {
        // get the current value to match it up
        model->setData(index, cb->currentText());
    } else if (index.column() >=0 && index.column() <= 2) {
        QCheckBox *cb = qobject_cast<QCheckBox *>(editor);
        model->setData(index, cb->isChecked());
    } else if (index.column() == 6) {
        // PPPG, so 3 DP
        QDoubleSpinBox *sb = qobject_cast<QDoubleSpinBox *>(editor);
        sb->setDecimals(3);
        model->setData(index, sb->value());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

}

QString MaltItemDelegate::displayText(const QVariant &value, const QLocale &locale) const {
    Q_UNUSED(locale);
    return value.toString();
}
