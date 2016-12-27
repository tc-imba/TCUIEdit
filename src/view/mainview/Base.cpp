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

        m_menu = new QMenu();

        m_menuOpen = new QAction(m_menu);
        m_menuOpen->setText("Open - 在新窗口打开");
        m_menu->addAction(m_menuOpen);
        m_memuRedirect = new QAction(m_menu);
        m_memuRedirect->setText("Redirect - 跳转到");
        m_menu->addAction(m_memuRedirect);
        m_menuCopy = new QAction(m_menu);
        m_menuCopy->setText("Copy - 复制");
        m_menu->addAction(m_menuCopy);

        m_currentRow = NULL;
    }

    Base::~Base()
    {
        delete m_menu;
    }

    void Base::refresh()
    {
        this->connect(m_browser, SIGNAL(rightClicked(TCUIEdit::property_browser::Row * )),
                      this, SLOT(onRightClicked(TCUIEdit::property_browser::Row * )));

        auto parent = m_browser->addCategory("Property");
        auto row = parent->addEditor("Name", m_uiBase->name());
        row->nameItem()->setData("本条UI的名字", Qt::ToolTipRole);
        this->examineName(row);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                      this, SLOT(onNameEdited(TCUIEdit::property_browser::Row * )));

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

    void Base::updateDisplay(property_browser::Row *row)
    {
        row->setValue(m_uiBase->display(false));
        row->valueItem()->setText(row->value());
    }

    void Base::onNameEdited(TCUIEdit::property_browser::Row *row)
    {
        row->setValue(row->valueItem()->text());
        m_uiBase->setName(row->value());
        this->examineName(row);
    }

    void Base::onDisplayEdited(TCUIEdit::property_browser::Row *row)
    {
        row->setValue(row->valueItem()->text());
        m_uiBase->setDisplay(row->value());
        auto displayRow = m_browser->aliasRow("DisplayName");
        if (displayRow)
        {
            this->updateDisplay(displayRow);
        }
    }

    void Base::onRightClicked(TCUIEdit::property_browser::Row *row)
    {
        if (row)
        {
            m_currentRow = row;
            if (row->data())
            {
                m_menuOpen->setEnabled(true);
                m_memuRedirect->setEnabled(true);
            }
            else
            {
                m_menuOpen->setEnabled(false);
                m_memuRedirect->setEnabled(false);
            }
            m_menu->exec(QCursor::pos());
        }
    }

    void Base::onMenuOpenClicked()
    {

    }

    void Base::onMenuRedirectClicked()
    {

    }

    void Base::onMenuCopyClicked()
    {

    }

}}
