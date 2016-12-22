//
// Created by liu on 2016/12/21.
//

#ifndef TCUIEDIT_UIMAINVIEW_CATEGORY_H
#define TCUIEDIT_UIMAINVIEW_CATEGORY_H

#include "UIMainView_Base.h"
#include "../../core/base/UIBase_Category.h"

namespace TCUIEdit
{
    class UIMainView_Category : public UIMainView_Base
    {
    protected:
        UIBase_Category *ui;
    public:
        UIMainView_Category(UIPropertyBrowser *browser, UIBase *ui);

        void refresh();
    };

};

#endif //TCUIEDIT_UIMAINVIEW_CATEGORY_H
