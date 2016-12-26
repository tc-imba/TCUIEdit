//
// Created by liu on 2016/12/21.
//

#pragma once

#include "Base.h"
#include "Category.h"

namespace TCUIEdit { namespace mainview
{
    class MainView
    {
    protected:
        property_browser::Browser *browser;

        Base *base;

    public:
        MainView(property_browser::Browser *browser);

        void displayUI(core::ui::Base *ui);

        void displayPackageBase(core::ui::Base *pkgBase);

        void displayPackage(core::package::Package *pkg);

    };
}}



