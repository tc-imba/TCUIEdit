//
// Created by liu on 2016/12/21.
//

#pragma once

#include "../../core/core.h"
#include "../../core/ui/Base.h"
#include "../../components/property_browser/Browser.h"

using namespace TCUIEdit::core;

namespace TCUIEdit
{
    class UIMainView_Base
    {
    protected:
        property_browser::Browser *m_browser;

        void _refresh();

    public:
        UIMainView_Base(property_browser::Browser *browser);

        virtual void refresh() = 0;
    };
};



