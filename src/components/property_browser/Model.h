//
// Created by liu on 2016/12/22.
//

#pragma once

#include "common.h"

namespace TCUIEdit { namespace property_browser
{
    class Model : public QStandardItemModel
    {
    Q_OBJECT
    public:
        Model(QObject *parent = Q_NULLPTR);

        void reset();
    };
}}


