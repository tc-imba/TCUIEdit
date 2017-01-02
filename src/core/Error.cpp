//
// Created by liu on 17-1-2.
//

#include <QColor>
#include "Error.h"

namespace TCUIEdit { namespace core
{
    const char *Error::TYPE_NAME[Error::TYPE_NUM] = {"", "Error", "Warning", "Tip"};

    const Qt::GlobalColor Error::TYPE_COLOR[Error::TYPE_NUM] = {Qt::black, Qt::red, Qt::darkYellow, Qt::black};

    Error::Error(TYPE type)
    {
        m_type = type;
    }

    Error::Error(const QString &name, TYPE type)
    {
        m_name = name;
        m_type = type;
    }

    const QString &Error::name() const
    {
        return m_name;
    }

    Error::TYPE Error::type() const
    {
        return m_type;
    }

    const QList<Error::Item> &Error::list() const
    {
        return m_list;
    }

    void Error::addItem(const QString &name, const QString &value, ui::Base *ui)
    {
        Item item;
        item.name = name;
        item.value = value;
        item.ui = ui;
        m_list.push_back(item);
    }

    QColor Error::color() const
    {
        if (m_type >= 0 && m_type < Error::TYPE_NUM)
        {
            return QColor(Error::TYPE_COLOR[m_type]);
        }
        return QColor(Error::TYPE_COLOR[0]);
    }

    const char *Error::typeName() const
    {
        if (m_type >= 0 && m_type < Error::TYPE_NUM)
        {
            return Error::TYPE_NAME[m_type];
        }
        return "UNKNOWN_TYPE";
    }
}}
