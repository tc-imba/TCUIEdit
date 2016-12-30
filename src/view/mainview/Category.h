//
// Created by liu on 2016/12/21.
//

#pragma once

#include "Base.h"
#include "../../core/ui/Category.h"

namespace TCUIEdit { namespace mainview
{
    class Category : public Base
    {
    Q_OBJECT
    protected:
        core::ui::Category *m_ui;
    public:
        Category(property_browser::Browser *browser, core::ui::Base *ui);

        void refresh();

    protected slots:
        void onNameEdited(TCUIEdit::property_browser::Row *row);
    };

}}


