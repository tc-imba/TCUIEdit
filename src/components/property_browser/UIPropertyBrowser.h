//
// Created by liu on 2016/12/21.
//

#ifndef TCUIEDIT_UIPROPERTYBROWSER_H
#define TCUIEDIT_UIPROPERTYBROWSER_H

#include <QtWidgets/QTreeView>
#include "UIPropertyBrowserModel.h"
#include "UIPropertyBrowser.h"

namespace TCUIEdit
{

    class UIPropertyBrowser : protected QTreeView
    {
    protected:
        UIPropertyBrowserModel *model;
    public:
        UIPropertyBrowser(QWidget *parent = Q_NULLPTR);

        ~UIPropertyBrowser();

        void addCategory();

    };

};

#endif //TCUIEDIT_UIPROPERTYBROWSER_H
