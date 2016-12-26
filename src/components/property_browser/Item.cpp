//
// Created by liu on 2016/12/21.
//

#include "Item.h"
#include "Browser.h"
#include "Editor.h"
#include "Text.h"

namespace TCUIEdit { namespace property_browser
{
    Item::Item(Browser *browser, const QString &name, const QString &value)
    {
        m_data = NULL;
        m_browser = browser;
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

    QStandardItem *Item::nameItem()
    {
        return m_nameItem;
    }

    QStandardItem *Item::valueItem()
    {
        return m_valueItem;
    }

    void *Item::data()
    {
        return m_data;
    }

    void Item::setData(void *data)
    {
        m_data = data;
    }

    Item *Item::addEditor(const QString &name, const QString &value, const QString &alias)
    {
        auto item = new Editor(m_browser, name, value);
        m_browser->addAlias(item, alias);
        m_nameItem->appendRow(item->formRow());
        return item;
    }

    Item *Item::addEditor(const QString &name, const QString &value)
    {
        return this->addEditor(name, value, name);
    }

    Item *Item::addText(const QString &name, const QString &value, const QString &alias)
    {
        auto item = new Text(m_browser, name, value);
        m_browser->addAlias(item, alias);
        m_nameItem->appendRow(item->formRow());
        return item;
    }

    Item *Item::addText(const QString &name, const QString &value)
    {
        return this->addText(name, value, name);
    }
}}