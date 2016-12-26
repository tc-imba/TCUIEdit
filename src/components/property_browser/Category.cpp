//
// Created by liu on 2016/12/22.
//

#include "Category.h"

namespace TCUIEdit { namespace property_browser
{
    Category::Category(Browser *browser, const QString &name)
            : Item(browser, name)
    {
        m_valueItem->setEditable(false);
    }


}}