//
// Created by liu on 2016/12/10.
//

#include "UIPackage_WEString.h"
#include "../UIProject.h"
#include "../UIException.h"

#define _HASH this->_pkg->getProject()->getWEStringMap()

namespace TCUIEdit
{

    UIPackage_WEString::UIPackage_WEString(UIPackage *package)
    {
        this->_pkg = package;
    }

    void UIPackage_WEString::readLine(const QString &line)
    {
        auto pos = line.indexOf('=');
        if (pos == -1 || pos == line.length() - 1)
        {
            throw UIExceptionFormatError();
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

    void UIPackage_WEString::add(const QString &name, const QString &value)
    {
        auto weString = new WEString(this->_pkg);
        weString->name = name;
        weString->value = value;
        _HASH.insert(name, weString);
        this->data.push_back(weString);
    }

    void UIPackage_WEString::remove(WEString *weString)
    {
        if (weString == NULL)
        {
            throw UIExceptionNotFound();
        }
        _HASH.remove(weString->getName(), weString);
        this->data.removeAll(weString);
        delete weString;
    }

    const QString UIPackage_WEString::getValue(const QString &name) const
    {
        QStringList list;
        QString value = name;
        while (value.left(8) == "WESTRING")
        {
            auto it = _HASH.find(value);
            if (it == _HASH.end())break;
            list.push_back(value);
            value = it.value()->getValue();
            if (list.contains(value))break;
        }
        return value;
    }

};
