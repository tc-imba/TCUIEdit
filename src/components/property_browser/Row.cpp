//
// Created by liu on 2016/12/21.
//

#include "Row.h"
#include "Browser.h"
#include "Editor.h"
#include "Text.h"

namespace TCUIEdit { namespace property_browser
{
    Row::Row(Browser *browser, const QString &name, const QString &value)
    {
        m_data = NULL;
        m_browser = browser;
        m_name = name;
        m_nameItem = new Item(this, m_name);
        m_nameItem->setEditable(false);
        m_value = value;
        m_valueItem = new Item(this, m_value);
    }

    QList<QStandardItem *> Row::formRow()
    {
        return QList<QStandardItem *>() << m_nameItem << m_valueItem;
    }

    const QString &Row::name()
    {
        return m_name;
    }

    const QString &Row::value()
    {
        return m_value;
    }

    Item *Row::nameItem()
    {
        return m_nameItem;
    }

    Item *Row::valueItem()
    {
        return m_valueItem;
    }

    void *Row::data()
    {
        return m_data;
    }

    void Row::setData(void *data)
    {
        m_data = data;
    }

    const QString& Row::alias()
    {
        return m_alias;
    }

    Row *Row::addEditor(const QString &name, const QString &value, const QString &alias)
    {
        auto item = new Editor(m_browser, name, value);
        m_browser->addAlias(item, alias);
        m_nameItem->appendRow(item->formRow());
        return item;
    }

    Row *Row::addEditor(const QString &name, const QString &value)
    {
        return this->addEditor(name, value, name);
    }

    Row *Row::addText(const QString &name, const QString &value, const QString &alias)
    {
        auto item = new Text(m_browser, name, value);
        m_browser->addAlias(item, alias);
        m_nameItem->appendRow(item->formRow());
        return item;
    }

    Row *Row::addText(const QString &name, const QString &value)
    {
        return this->addText(name, value, name);
    }

    void Row::emitEditSignal()
    {

    }
}}