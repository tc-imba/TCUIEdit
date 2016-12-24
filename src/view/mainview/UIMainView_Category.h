//
// Created by liu on 2016/12/21.
//

#pragma once

#include "UIMainView_Base.h"
#include "../../core/ui/Category.h"

namespace TCUIEdit
{
    class UIMainView_Category : public UIMainView_Base
    {
    protected:
        UI::Category *ui;
    public:
        UIMainView_Category(property_browser::Browser *browser, UI::Base *ui);

        void refresh();
    };

};


