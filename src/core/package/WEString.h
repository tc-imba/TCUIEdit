//
// Created by liu on 2016/12/10.
//

#pragma once

#include "../core.h"
#include "../ui/WEString.h"
#include "Package.h"
#include <QMultiHash>
#include <QList>

namespace TCUIEdit { namespace core { namespace package
{

    class WEString
    {
    protected:
        QList<ui::WEString *> m_data;
        Package *m_pkg;
    public:
        WEString(Package *package);

        void readLine(const QString &line);

        void add(const QString &name = "", const QString &value = "");

        void remove(ui::WEString *weString);

        const QString getValue(const QString &name) const;

        Package *package() const;
    };

}}}



