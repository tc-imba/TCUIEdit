//
// Created by liu on 2016/12/22.
//

#include "WEString.h"

namespace TCUIEdit { namespace core { namespace ui
{

    WEString::WEString(package::Package *package)
    {
        m_pkg = package;
    }

    const QString &WEString::name() const
    {
        return m_name;
    }

    const QString &WEString::value() const
    {
        return m_value;
    }

    package::Package *WEString::package() const
    {
        return m_pkg;
    }

}}}
