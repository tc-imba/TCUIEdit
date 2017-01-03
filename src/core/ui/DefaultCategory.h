//
// Created by liu on 17-1-3.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
{
    // Defines categories to be automatically added to new maps
    class DefaultCategory : public Base
    {
    public:
        DefaultCategory(package::Package *package, QPair<QString, QStringList> pair);

        ~DefaultCategory();

        const QString formDisplay() const;
    };
}}}

