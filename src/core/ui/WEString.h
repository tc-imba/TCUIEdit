//
// Created by liu on 2016/12/22.
//

#pragma once

#include "../core.h"

namespace TCUIEdit { namespace core { namespace ui
{

    class WEString
    {
    protected:
        QString m_name, m_value;
        package::Package *m_pkg;
    public:
        friend class package::WEString;

        WEString(package::Package *package);

        ~WEString();

        const QString &name() const;

        const QString &value() const;

        package::Package *package() const;

    };

}}}


