//
// Created by liu on 2016/12/21.
//

#pragma once

#include "UIMainView_Base.h"
#include "UIMainView_Category.h"

namespace TCUIEdit
{
    class UIMainView
    {
    protected:
        property_browser::Browser *browser;

        UIMainView_Base *base;

    public:
        UIMainView(property_browser::Browser *browser);

        void displayUI(ui::Base* ui);

        void displayPackageBase(ui::Base* pkgBase);

        void displayPackage(package::Package* pkg);

    };
};



