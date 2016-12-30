//
// Created by liu on 2016/12/21.
//

#include "MainView.h"

namespace TCUIEdit { namespace mainview
{

    MainView::MainView(property_browser::Browser *browser)
    {
        this->browser = browser;
        this->base = NULL;
    }

    void MainView::displayUI(core::ui::Base *ui)
    {
        if (!this->base) delete this->base;
        switch (ui->type())
        {
        case core::ui::Base::TRIGGER_CATEGORY:this->base = new Category(this->browser, ui);
            break;
        case core::ui::Base::TRIGGER_TYPE:this->base = new Type(this->browser, ui);
            break;
        case core::ui::Base::TRIGGER_TYPE_DEFAULT:this->base = new TypeDefault(this->browser, ui);
            break;
        case core::ui::Base::TRIGGER_PARAM:this->base = new Param(this->browser, ui);
            break;
        case core::ui::Base::TRIGGER_EVENT:

            break;
        default:break;
        }
    }

}}
