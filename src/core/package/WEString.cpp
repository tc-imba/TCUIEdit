//
// Created by liu on 2016/12/10.
//

#include "WEString.h"
#include "Project.h"
#include "Exception.h"

#define _HASH m_pkg->project()->getWEStringMap()

namespace TCUIEdit { namespace core { namespace package
{

    WEString::WEString(Package *package)
    {
        m_pkg = package;
    }

    void WEString::readLine(const QString &line)
    {
        auto pos = line.indexOf('=');
        if (pos == -1 || pos == line.length() - 1)
        {
            throw ExceptionFormatError();
        }
        auto name = line.left(pos);
        auto value = line.mid(pos + 1);
        auto len = value.length();
        if (len >= 2)
        {
            if (value[0] == '"' && value[len - 1] == '"')value = value.mid(1, len - 2);
        }
        this->add(name, value);
    }

    void WEString::add(const QString &name, const QString &value)
    {
        auto weString = new ui::WEString(m_pkg);
        weString->m_name = name;
        weString->m_value = value;
        _HASH->insert(name, weString);
        m_data.push_back(weString);
    }

    void WEString::remove(ui::WEString *weString)
    {
        if (weString == NULL)
        {
            throw ExceptionNotFound();
        }
        _HASH->remove(weString->name(), weString);
        m_data.removeAll(weString);
        delete weString;
    }

    const QString WEString::getValue(const QString &name) const
    {
        QStringList list;
        QString value = name;
        while (value.left(8) == "WESTRING")
        {
            auto it = _HASH->find(value);
            if (it == _HASH->end())break;
            list.push_back(value);
            value = it.value()->value();
            if (list.contains(value))break;
        }
        return value;
    }

    Package *WEString::package() const
    {
        return m_pkg;
    }
}}}
