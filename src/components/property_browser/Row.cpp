//
// Created by liu on 2016/12/21.
//

#include "Row.h"
#include "Browser.h"
#include "Editor.h"
#include "Text.h"
#include "List.h"

namespace TCUIEdit { namespace property_browser
{
    Row::Row(Browser *browser, const QString &name, const QString &value)
    {
        m_type = TYPE_TEXT;
        m_data = NULL;
        m_browser = browser;
        m_name = name;
        m_nameItem = new Item(this, m_name);
        m_nameItem->setEditable(false);
        m_value = value;
        m_valueItem = new Item(this, m_value);
    }

    Row::~Row()
    {

    }

    QList<QStandardItem *> Row::formRow()
    {
        return QList<QStandardItem *>() << m_nameItem << m_valueItem;
    }

    Row::TYPE Row::type()
    {
        return m_type;
    }

    const QString &Row::name()
    {
        return m_name;
    }

    const QString &Row::value()
    {
        return m_value;
    }

    void Row::setName(const QString &name)
    {
        m_name = name;
    }

    void Row::setValue(const QString &value)
    {
        m_value = value;
    }

    Item *Row::nameItem()
    {
        return m_nameItem;
    }

    Item *Row::valueItem()
    {
        return m_valueItem;
    }

    QVariant Row::data(int role) const
    {
        return m_nameItem->data(role);
    }

    void Row::setData(const QVariant &value, int role)
    {
        m_nameItem->setData(value, role);
    }

    const QString &Row::alias()
    {
        return m_alias;
    }

    Row *Row::addRow(TYPE type, const QString &name, const QString &value, const QString &alias)
    {
        Row *item;
        switch (type)
        {
        case TYPE_EDITOR:
            item = new Editor(m_browser, name, value);
            break;
        case TYPE_LIST:
            item = new List(m_browser, name, value);
            break;
        case TYPE_TEXT:
        default:
            item = new Text(m_browser, name, value);
            break;
        }
        m_browser->addAlias(item, alias);
        m_nameItem->appendRow(item->formRow());
        return item;
    }


    Row *Row::addEditor(const QString &name, const QString &value, const QString &alias)
    {
        return this->addRow(TYPE_EDITOR, name, value, alias);
    }

    Row *Row::addEditor(const QString &name, const QString &value)
    {
        return this->addEditor(name, value, name);
    }

    Row *Row::addText(const QString &name, const QString &value, const QString &alias)
    {
        return this->addRow(TYPE_TEXT, name, value, alias);
    }

    Row *Row::addText(const QString &name, const QString &value)
    {
        return this->addText(name, value, name);
    }

    Row *Row::addList(const QString &name, const QString &value, const QStringList &list, const QString &alias)
    {
        auto row = (List *) this->addRow(TYPE_LIST, name, value, alias);
        row->setList(list);
        return row;
    }

    Row *Row::addList(const QString &name, const QString &value, const QStringList &list)
    {
        return this->addList(name, value, list, name);
    }


    void Row::removeChildren()
    {
        while (auto item = (Item *) m_nameItem->child(0, 0))
        {
            auto row = item->row();
            row->removeChildren();
            m_browser->model()->removeRow(0, m_nameItem->index());
            delete row;
        }
    }

    void Row::emitEditSignal()
    {

    }
}}