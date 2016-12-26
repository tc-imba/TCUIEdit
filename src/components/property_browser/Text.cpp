//
// Created by liu on 16-12-26.
//

#include "Text.h"
#include "Browser.h"

namespace TCUIEdit { namespace property_browser
{

    Text::Text(Browser *browser, const QString &name, const QString &value)
            : Item(browser, name, value)
    {
        m_valueItem->setEditable(false);
    }

}}