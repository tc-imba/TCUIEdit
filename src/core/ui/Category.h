//
// Created by liu on 2016/12/5.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace Core { namespace UI
{
    //***************************************************************************
    // [TriggerCategories]
    // Defines categories for organizing trigger functions
    // Key: Arbitrary category identifier

    // Value 0: Display text
    // Value 1: Icon image file
    // Value 2: Optional flag (defaults to 0) indicating to disable display of category name


    class Category : public Base
    {

    protected:
        QString icon, displayFlag;
    public:
        Category(Package::Package *package, QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

    };
}}}



