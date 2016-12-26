//
// Created by liu on 16-12-26.
//

#pragma once

#include "Row.h"

namespace TCUIEdit { namespace property_browser
{
    class Text : public Row
    {
    Q_OBJECT
    public:
        Text(Browser *browser, const QString &name, const QString &value = "");
    };

}}
