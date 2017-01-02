//
// Created by liu on 2016/12/22.
//

#include "Category.h"

namespace TCUIEdit { namespace property_browser
{
    Category::Category(Browser *browser, const QString &name)
            : Row(browser, name)
    {
        m_type = TYPE_CATEGORY;
        m_valueItem->setEditable(false);
    }


}}