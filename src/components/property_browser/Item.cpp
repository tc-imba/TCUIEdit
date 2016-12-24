//
// Created by liu on 2016/12/21.
//

#include "Item.h"

namespace TCUIEdit { namespace property_browser
{
    Item::Item(const QString &name, const QString &value)
    {
        m_name = name;
        m_nameItem = new QStandardItem(m_name);
        m_nameItem->setEditable(false);
        m_value = value;
        m_valueItem = new QStandardItem(m_value);
    }

    QList<QStandardItem *> Item::formRow()
    {
        return QList<QStandardItem *>() << m_nameItem << m_valueItem;
    }

    QStandardItem* Item::nameItem()
    {
        return m_nameItem;
    }

    QStandardItem* Item::valueItem()
    {
        return m_valueItem;
    }
}}