//
// Created by sunyi on 2016/12/29.
//

#include "Param.h"

namespace TCUIEdit { namespace mainview
{
    Param::Param(TCUIEdit::property_browser::Browser *browser, core::ui::Base *ui)
            : Base(browser, ui)
    {
        m_ui = (core::ui::Param *) ui;
        this->refresh();
    }

    void Param::refresh()
    {
        Base::refresh();
        auto parent = m_browser->aliasRow("Property");

        auto row = parent->addEditor("Display", m_ui->display(true));
        row->nameItem()->setData("编辑器中显示的名字（可以为WE_STRING）", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));
        row = parent->addText("Display (in Editor)", m_ui->display(false), "DisplayName");
        row->nameItem()->setData("编辑器中最终显示的名字", Qt::ToolTipRole);

        row = parent->addEditor("Version", m_ui->version());
        row->nameItem()->setData("第一个可运行游戏版本", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));

        row = parent->addEditor("Variable Type", m_ui->variableType());
        row->nameItem()->setData("变量名", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));

        row = parent->addEditor("Script Name", m_ui->script());
        row->nameItem()->setData("jass代码", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));

    }
}}