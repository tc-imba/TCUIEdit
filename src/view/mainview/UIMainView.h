//
// Created by liu on 2016/12/21.
//

#ifndef TCUIEDIT_UIMAINVIEW_H
#define TCUIEDIT_UIMAINVIEW_H

#include "UIMainView_Base.h"
#include "UIMainView_Category.h"

namespace TCUIEdit
{
    class UIMainView
    {
    protected:
        UIPropertyBrowser *browser;

        UIMainView_Base *base;

    public:
        UIMainView(UIPropertyBrowser *browser);

        void displayUI(UIBase* ui);

        void displayPackageBase(UIPackage_Base* pkgBase);

        void displayPackage(UIPackage* pkg);

    };
};


#endif //TCUIEDIT_UIMAINVIEW_H
