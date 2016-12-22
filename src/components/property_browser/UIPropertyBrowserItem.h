//
// Created by liu on 2016/12/21.
//

#ifndef TCUIEDIT_UIPROPERTYBROWSERITEM_H
#define TCUIEDIT_UIPROPERTYBROWSERITEM_H

#include <QtGui/QStandardItem>

namespace TCUIEdit
{
    class UIPropertyBrowserItem: public QStandardItem
    {
    public:
        UIPropertyBrowserItem(const QString &text);
    };

};

#endif //TCUIEDIT_UIPROPERTYBROWSERITEM_H
