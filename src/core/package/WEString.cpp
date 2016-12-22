//
// Created by liu on 2016/12/10.
//

#include "WEString.h"
#include "Project.h"
#include "Exception.h"

#define _HASH this->_pkg->getProject()->getWEStringMap()

namespace TCUIEdit { namespace Core { namespace Package
{

    WEString::WEString(Package *package)
    {
        this->_pkg = package;
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
        auto weString = new UI::WEString(this->_pkg);
        weString->name = name;
        weString->value = value;
        _HASH->insert(name, weString);
        this->data.push_back(weString);
    }

    void WEString::remove(UI::WEString *weString)
    {
        if (weString == NULL)
        {
            throw ExceptionNotFound();
        }
        _HASH->remove(weString->getName(), weString);
        this->data.removeAll(weString);
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
            value = it.value()->getValue();
            if (list.contains(value))break;
        }
        return value;
    }

    Package *WEString::getPackage() const
    {
        return this->_pkg;
    }
}}}
