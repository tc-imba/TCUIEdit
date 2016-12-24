//
// Created by liu on 2016/12/21.
//

#include "UIMainView_Category.h"

namespace TCUIEdit
{

    UIMainView_Category::UIMainView_Category(property_browser::Browser *browser, UI::Base *ui)
            : UIMainView_Base(browser)
    {
        this->ui = (UI::Category *) ui;
        this->refresh();
    }

    void UIMainView_Category::refresh()
    {
        this->_refresh();
        auto parent = m_browser->addCategory("Property");

    }

};
