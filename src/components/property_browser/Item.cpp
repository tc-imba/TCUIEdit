//
// Created by liu on 16-12-26.
//

#include "Item.h"

namespace TCUIEdit { namespace property_browser
{

    Item::Item(Row *row, const QString &text) : QStandardItem(text)
    {
        m_row = row;
    }

    Row *Item::row()
    {
        return m_row;
    }

}}