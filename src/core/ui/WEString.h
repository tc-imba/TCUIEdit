//
// Created by liu on 2016/12/22.
//

#pragma once

#include "../core.h"

namespace TCUIEdit { namespace Core { namespace UI
{

    class WEString
    {
    protected:
        QString name, value;
        Package::Package *_pkg;
    public:
        friend class Package::WEString;

        WEString(Package::Package *package);

        const QString &getName() const;

        const QString &getValue() const;

        Package::Package *getPackage() const;

    };

}}}


