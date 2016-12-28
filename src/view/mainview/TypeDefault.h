//
// Created by sunyi on 2016/12/29.
//

#ifndef TCUIEDIT_TYPEDEFAULT_H
#define TCUIEDIT_TYPEDEFAULT_H
#pragma once
#include "Base.h"
#include "../../core/ui/TypeDefault.h"
namespace TCUIEdit{namespace mainview
    {
        class TypeDefault:public Base
        {
            Q_OBJECT
        protected:
            core::ui::TypeDefault *m_ui;
        public:
            TypeDefault(TCUIEdit::property_browser::Browser *browser,core::ui::Base *ui);
            void refresh();
        };
        
    }}
#endif //TCUIEDIT_TYPEDEFAULT_H
