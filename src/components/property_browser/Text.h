//
// Created by liu on 16-12-26.
//

#pragma once

#include "Item.h"

namespace TCUIEdit { namespace property_browser
{
    class Text : public Item
    {
    public:
        Text(Browser *browser, const QString &name, const QString &value = "");
    };

}}
