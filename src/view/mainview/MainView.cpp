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
        case core::ui::Base::TRIGGER_CATEGORY:
            this->base = new Category(this->browser, ui);
            break;
        default:
            break;
        }
    }

}}
