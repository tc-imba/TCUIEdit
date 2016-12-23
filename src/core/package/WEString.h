//
// Created by liu on 2016/12/10.
//

#pragma once

#include "../core.h"
#include "../ui/WEString.h"
#include "Package.h"
#include <QMultiHash>
#include <QList>

namespace TCUIEdit { namespace Core { namespace Package
{

    class WEString
    {
    protected:
        QList<UI::WEString *> data;
        Package *_pkg;
    public:
        WEString(Package *package);

        void readLine(const QString &line);

        void add(const QString &name = "", const QString &value = "");

        void remove(UI::WEString *weString);

        const QString getValue(const QString &name) const;

        Package *getPackage() const;
    };

}}}



