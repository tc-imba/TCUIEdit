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

        auto parent = m_browser->addCategory("Property");
        auto item = parent->addEditor("Name", m_ui->name());

        this->connect(item, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                      this, SLOT(nameEdited(TCUIEdit::property_browser::Row * )));

        parent->addEditor("Display", m_ui->display(true));
        parent->addText("Display (in Editor)", m_ui->display(false), "DisplayName");
        parent->addEditor("Icon", m_ui->icon());
        parent->addEditor("Display Flag", m_ui->displayFlag());

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
                        item = parent->addText(itPkg->name(), itUI->name(), "");
                        item->setData(itUI);
                    }
                }
            }
        }

        m_browser->expandToDepth(0);
    }

}}
