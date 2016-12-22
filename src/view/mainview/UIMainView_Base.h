//
// Created by liu on 2016/12/21.
//

#ifndef TCUIEDIT_UIMAINVIEW_BASE_H
#define TCUIEDIT_UIMAINVIEW_BASE_H

#include "../../core/UICore.h"
#include "../../core/base/base.h"
#include "../../components/property_browser/UIPropertyBrowser.h"

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


#endif //TCUIEDIT_UIMAINVIEW_BASE_H
