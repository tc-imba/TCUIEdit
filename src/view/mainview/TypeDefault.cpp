//
// Created by sunyi on 2016/12/29.
//
#include "TypeDefault.h"

namespace TCUIEdit { namespace mainview
{
    TypeDefault::TypeDefault(TCUIEdit::property_browser::Browser *browser, core::ui::Base *ui)
            : Base(browser, ui)
    {
        m_ui = (core::ui::TypeDefault *) ui;
        this->refresh();
    }

    void TypeDefault::refresh()
    {
        Base::refresh();
        auto parent = m_browser->aliasRow("Property");

        auto row = parent->addEditor("script", m_ui->script());
        row->nameItem()->setData("jass代码", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));

    }
}}

