//
// Created by liu on 2016/12/21.
//

#include "UIMainView.h"

namespace TCUIEdit
{

    UIMainView::UIMainView(property_browser::Browser *browser)
    {
        this->browser = browser;
        this->base = NULL;
    }

    void UIMainView::displayUI(ui::Base *ui)
    {
        if (!this->base) delete this->base;
        switch (ui->type())
        {
        case ui::Base::TRIGGER_CATEGORY:
            this->base = new UIMainView_Category(this->browser, ui);
            break;
        default:
            break;
        }
    }

};
