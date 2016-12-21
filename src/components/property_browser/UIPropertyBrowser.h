//
// Created by liu on 2016/12/21.
//

#ifndef TCUIEDIT_UIPROPERTYBROWSER_H
#define TCUIEDIT_UIPROPERTYBROWSER_H

#include <QtWidgets/QTreeView>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>

namespace TCUIEdit
{

    class UIPropertyBrowser : protected QTreeView
    {
    protected:
        QStandardItemModel *model;
    public:
        UIPropertyBrowser(QWidget *parent = Q_NULLPTR);
        ~UIPropertyBrowser();

    };

};

#endif //TCUIEDIT_UIPROPERTYBROWSER_H
