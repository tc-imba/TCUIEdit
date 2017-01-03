//
// Created by liu on 2016/12/21.
//

#include <QtWidgets/QAction>
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
        this->connect(m_menuOpen, SIGNAL(triggered()), this, SLOT(onMenuOpenClicked()));
        m_menu->addAction(m_menuOpen);
        m_menuRedirect = new QAction(m_menu);
        m_menuRedirect->setText("Redirect - 跳转到");
        this->connect(m_menuRedirect, SIGNAL(triggered()), this, SLOT(onMenuRedirectClicked()));
        m_menu->addAction(m_menuRedirect);
        m_menuCopy = new QAction(m_menu);
        m_menuCopy->setText("Copy - 复制");
        this->connect(m_menuCopy, SIGNAL(triggered()), this, SLOT(onMenuCopyClicked()));
        m_menu->addAction(m_menuCopy);

        m_currentRow = NULL;
    }

    Base::~Base()
    {
        delete m_menu;
    }

    void Base::refresh()
    {
        m_browser->init();

        this->connect(m_browser, SIGNAL(rightClicked(TCUIEdit::property_browser::Row * )),
                      this, SLOT(onRightClicked(TCUIEdit::property_browser::Row * )));

        auto parent = m_browser->addCategory("Property");
        auto row = parent->addEditor("Name", m_uiBase->name());
        row->nameItem()->setData("本条UI的名字", Qt::ToolTipRole);
        this->showError(row, m_uiBase->examineName());
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                      this, SLOT(onNameEdited(TCUIEdit::property_browser::Row * )));

    }

    void Base::showError(property_browser::Row *row, const core::Error &error)
    {
        row->removeChildren();
        auto list = error.list();
        if (error.type() == core::Error::TYPE_NONE)return;
        auto color = error.color();
        QString str;
        QTextStream stream(&str);
        if (list.length() == 0)
        {
            stream << error.name() << " " << error.typeName();
        }
        else if (list.length() == 1)
        {
            stream << "1 " << error.name() << " " << error.typeName();
        }
        else
        {
            stream << list.length() << " " << error.name() << " " << error.typeName() << "s";
        }
        auto newRow = row->addText(error.typeName(), str, "");
        newRow->nameItem()->setForeground(color);
        newRow->valueItem()->setForeground(color);
        for (auto it:list)
        {
            newRow = row->addText(it.name, it.value, "");
            newRow->setData((qlonglong) it.ui);
            newRow->nameItem()->setForeground(color);
            newRow->valueItem()->setForeground(color);
        }
        m_browser->expand(row->valueItem()->index());
    }

    int Base::showErrorDialog(const core::Error &error)
    {
        if (error.type() == core::Error::TYPE_NONE)return QDialog::Accepted;
        QDialog dialog;

        return dialog.exec();
    }

    void Base::updateDisplay(property_browser::Row *row)
    {
        row->setValue(m_uiBase->display(false));
        row->valueItem()->setText(row->value());
    }

    void Base::onNameEdited(TCUIEdit::property_browser::Row *row)
    {
        m_uiBase->setName(row->valueItem()->text());
        auto result = this->showErrorDialog(m_uiBase->examineName());
        if (result == QDialog::Rejected)
        {
            this->disconnect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                             this, SLOT(onNameEdited(TCUIEdit::property_browser::Row * )));
            row->valueItem()->setText(row->value());
            this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                          this, SLOT(onNameEdited(TCUIEdit::property_browser::Row * )));
            m_uiBase->setName(row->value());
        }
        else
        {
            row->setValue(m_uiBase->name());
        }
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
            if (row->data().toLongLong())
            {
                m_menuOpen->setEnabled(true);
                m_menuRedirect->setEnabled(true);
            }
            else
            {
                m_menuOpen->setEnabled(false);
                m_menuRedirect->setEnabled(false);
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
        qDebug() << "Copy";
    }

}}
