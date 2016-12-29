//
// Created by liu on 2016/12/21.
//

#include "Category.h"

namespace TCUIEdit { namespace mainview
{

    Category::Category(property_browser::Browser *browser, core::ui::Base *ui)
            : Base(browser, ui)
    {
        m_ui = (core::ui::Category *) ui;
        this->refresh();
    }

    void Category::refresh()
    {
        Base::refresh();

        auto parent = m_browser->aliasRow("Property");

        auto row = parent->addEditor("Display", m_ui->display(true));
        row->nameItem()->setData("编辑器中显示的名字（可以为WE_STRING）", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                      this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));
        row = parent->addText("Display (in Editor)", m_ui->display(false), "DisplayName");
        row->nameItem()->setData("编辑器中最终显示的名字", Qt::ToolTipRole);


        row = parent->addEditor("Icon", m_ui->icon());
        row->nameItem()->setData("编辑器中显示的图标", Qt::ToolTipRole);

        row = parent->addEditor("Display Flag", m_ui->displayFlag());
        row->nameItem()->setData("编辑器中是否显示该类", Qt::ToolTipRole);



        QString typeNames[4] = {"Events", "Condition", "Action", "Call"};
        core::ui::Base::TYPE types[4] = {core::ui::Base::TRIGGER_EVENT,
                                         core::ui::Base::TRIGGER_CONDITION,
                                         core::ui::Base::TRIGGER_ACTION,
                                         core::ui::Base::TRIGGER_CALL};

        for (int i = 0; i < 4; i++)
        {
            parent = m_browser->addCategory(typeNames[i]);
            for (auto itPkg:*(m_ui->package()->project()->packages()))
            {
                for (auto itUI:itPkg->base(types[i])->data())
                {
                    if (m_ui->name() == ((core::ui::Function *) itUI)->category())
                    {
                        row = parent->addText(itPkg->name(), itUI->name(), "");
                        row->setData(itUI);
                    }
                }
            }
        }

        m_browser->expandToDepth(0);
    }

}}
