//
// Created by liu on 2016/12/5.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
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
        QString m_icon, m_displayFlag;
    public:
        Category(package::Package *package, QPair<QString, QStringList> pair);

        const QString &icon() const;

        void setIcon(const QString& icon);

        const QString &displayFlag();

        const QString formDisplay() const;



    };
}}}



