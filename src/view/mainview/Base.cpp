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

    void Base::examineName(property_browser::Row *row)
    {
        auto list = m_uiBase->examineName();
        if (list.length() > 0)
        {
            QString str;
            QTextStream ss(&str);
            ss << list.length() << " Redefinition Error(s) in";
            auto item = row->addText("Error", str, "");
            item->nameItem()->setForeground(QColor(Qt::red));
            item->valueItem()->setForeground(QColor(Qt::red));
            for (auto it:list)
            {
                item = row->addText(it->package()->name(), it->typeName(), "");
                item->setData(it);
                item->nameItem()->setForeground(QColor(Qt::red));
                item->valueItem()->setForeground(QColor(Qt::red));
                m_browser->expand(row->valueItem()->index());
            }
        }
        else
        {
            row->removeChildren();
        }
    }

    void Base::nameEdited(TCUIEdit::property_browser::Row *row)
    {
#ifdef QT_DEBUG
        qDebug() << "Name Edited" << row->name() << row->valueItem()->text();
#endif
        row->setName(row->valueItem()->text());
        m_uiBase->setName(row->name());
        this->examineName(row);
    }
}}
