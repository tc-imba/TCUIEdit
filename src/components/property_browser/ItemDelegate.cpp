//
// Created by liu on 17-1-2.
//

#include <QComboBox>
#include "ItemDelegate.h"
#include "List.h"

namespace TCUIEdit { namespace property_browser
{

    ItemDelegate::ItemDelegate(Browser *parent) : QStyledItemDelegate(parent)
    {
        m_browser = parent;
    }

    QWidget *ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
    {

        auto item = (Item *) m_browser->model()->itemFromIndex(index);
        auto row = item->row();
        qDebug() << "createEditor" << row->name();
        switch (row->type())
        {
        case Row::TYPE_EDITOR:
        {
            return QStyledItemDelegate::createEditor(parent, option, index);
        }
        case Row::TYPE_LIST:
        {
            auto editor = new QComboBox(parent);
            editor->addItems(((List *) row)->list());
            return editor;
        }
        default:
            break;
        }

        /*QSpinBox *editor = new QSpinBox(parent);

        editor->setMinimum(0);

        editor->setMaximum(100);

        */

    }

}}