//
// Created by liu on 16-12-26.
//

#pragma once

#include "common.h"

namespace TCUIEdit { namespace property_browser
{

    class Item : public QStandardItem
    {
    protected:
        Row *m_row;
    public:
        Item(Row *row, const QString &text);

        Row *row();
    };

}}
