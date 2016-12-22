//
// Created by liu on 2016/12/21.
//

#pragma once

#include "../../core/core.h"
#include "../../core/ui/base.h"
#include "../../components/property_browser/UIPropertyBrowser.h"

using namespace TCUIEdit::Core;

namespace TCUIEdit
{
    class UIMainView_Base
    {
    protected:
        UIPropertyBrowser *browser;
    public:
        UIMainView_Base(UIPropertyBrowser *browser);

        virtual void refresh() = 0;
    };
};



