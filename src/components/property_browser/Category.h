//
// Created by liu on 2016/12/22.
//

#pragma once

#include "Row.h"

namespace TCUIEdit { namespace property_browser
{
    class Category : public Row
    {
    Q_OBJECT
    public:
        Category(Browser *browser, const QString &name);

    };
}}


