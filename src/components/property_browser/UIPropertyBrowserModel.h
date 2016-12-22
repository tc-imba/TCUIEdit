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
    Q_OBJECT
    public:
        UIPropertyBrowserModel(QObject *parent = Q_NULLPTR);

        void reset();
    };
};

#endif //TCUIEDIT_UIPROPERTYBROWSERMODEL_H
