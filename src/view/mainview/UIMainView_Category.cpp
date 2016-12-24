//
// Created by liu on 2016/12/21.
//

#include "UIMainView_Category.h"

namespace TCUIEdit
{

    UIMainView_Category::UIMainView_Category(UIPropertyBrowser *browser, UI::Base *ui)
            : UIMainView_Base(browser)
    {
        this->ui = (UI::Category *) ui;
        this->refresh();
    }

    void UIMainView_Category::refresh()
    {
        this->browser->addCategory("Properties");
    }

};
