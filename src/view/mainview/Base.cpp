//
// Created by liu on 2016/12/21.
//

#include "Base.h"

namespace TCUIEdit { namespace mainview
{
    Base::Base(property_browser::Browser *browser, core::ui::Base *ui)
    {
        m_uiBase = ui;
        m_browser = browser;
        m_browser->init();
    }

    void Base::refresh()
    {

    }

    void Base::nameEdited(TCUIEdit::property_browser::Row *row)
    {
#ifdef QT_DEBUG
        qDebug() << "Name Edited" << row->name() << row->valueItem()->text();
#endif
        m_uiBase->setName(row->valueItem()->text());
    }
}}
