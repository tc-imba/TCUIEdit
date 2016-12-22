//
// Created by liu on 2016/12/22.
//

#ifndef TCUIEDIT_UIPROPERTYBROWSERMODEL_H
#define TCUIEDIT_UIPROPERTYBROWSERMODEL_H

#include <QtGui/QStandardItemModel>

namespace TCUIEdit
{
    class UIPropertyBrowserModel : public QStandardItemModel
    {
    public:
        UIPropertyBrowserModel(QObject *parent = Q_NULLPTR);
    };
};

#endif //TCUIEDIT_UIPROPERTYBROWSERMODEL_H
