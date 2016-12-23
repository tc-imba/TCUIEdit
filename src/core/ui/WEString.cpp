//
// Created by liu on 2016/12/22.
//

#include "WEString.h"

namespace TCUIEdit { namespace Core { namespace UI
{

    WEString::WEString(Package::Package *package)
    {
        this->_pkg = package;
    }

    const QString &WEString::getName() const
    {
        return this->name;
    }

    const QString &WEString::getValue() const
    {
        return this->value;
    }

    Package::Package *WEString::getPackage() const
    {
        return this->_pkg;
    }

}}}
