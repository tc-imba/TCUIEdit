//
// Created by liu on 2016/12/21.
//

#include "UIMainView_Base.h"

namespace TCUIEdit
{
    UIMainView_Base::UIMainView_Base(property_browser::Browser *browser)
    {
        m_browser = browser;
        m_browser->init();
    }

    void UIMainView_Base::refresh()
    {

    }
};
