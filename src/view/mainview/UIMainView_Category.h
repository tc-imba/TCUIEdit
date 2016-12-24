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
        ui::Category *ui;
    public:
        UIMainView_Category(UIPropertyBrowser *browser, ui::Base *ui);

        void refresh();
    };

};


