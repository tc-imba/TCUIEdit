//
// Created by liu on 2016/12/22.
//

#pragma once

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


