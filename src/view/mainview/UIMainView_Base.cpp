//
// Created by liu on 2016/12/21.
//

#include "UIMainView_Base.h"

namespace TCUIEdit
{
    UIMainView_Base::UIMainView_Base(UIPropertyBrowser *browser)
    {
        this->browser = browser;
        this->browser->init();
    }
};
