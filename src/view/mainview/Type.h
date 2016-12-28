//
// Created by sunyi on 2016/12/29.
//

#ifndef TCUIEDIT_TYPE_H
#define TCUIEDIT_TYPE_H
#pragma once
#include "Base.h"
#include "../../core/ui/Type.h"
namespace TCUIEdit{namespace mainview
    {
        class Type:public Base
        {
           Q_OBJECT
        protected:
            core::ui::Type *m_ui;
        public:
            Type(property_browser::Browser *browser,core::ui::Base *ui);
            void refresh();
        };
    }}
#endif //TCUIEDIT_TYPE_H
