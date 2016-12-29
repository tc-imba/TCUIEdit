//
// Created by sunyi on 2016/12/29.
//


#pragma once

#include "Base.h"
#include "../../core/ui/TypeDefault.h"

namespace TCUIEdit { namespace mainview
{
    class TypeDefault : public Base
    {
    Q_OBJECT
    protected:
        core::ui::TypeDefault *m_ui;
    public:
        TypeDefault(TCUIEdit::property_browser::Browser *browser, core::ui::Base *ui);

        void refresh();
    };

}}
