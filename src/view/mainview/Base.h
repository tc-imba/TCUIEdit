//
// Created by liu on 2016/12/21.
//

#pragma once

#include <QColor>
#include <QTextStream>
#include <QMenu>

#include "../../core/core.h"
#include "../../core/ui/all.h"
#include "../../core/package/Package.h"
#include "../../core/Project.h"
#include "../../components/property_browser/Browser.h"
#include "../../components/property_browser/Editor.h"

//using namespace TCUIEdit::core;

namespace TCUIEdit { namespace mainview
{
    class Base : public QObject
    {
    Q_OBJECT
    protected:
        property_browser::Browser *m_browser;
        core::ui::Base *m_uiBase;

        QMenu *m_menu;
        QAction *m_menuCopy, *m_menuOpen, *m_memuRedirect;
        property_browser::Row *m_currentRow;

    public:
        Base(property_browser::Browser *browser, core::ui::Base *ui);

        virtual ~Base();

        virtual void refresh();

        virtual void examineName(property_browser::Row *row);

        virtual void updateDisplay(property_browser::Row *row);

    protected slots:

        virtual void onNameEdited(TCUIEdit::property_browser::Row *row);

        virtual void onDisplayEdited(TCUIEdit::property_browser::Row *row);

        virtual void onRightClicked(TCUIEdit::property_browser::Row *row);

        virtual void onMenuOpenClicked();

        virtual void onMenuRedirectClicked();

        virtual void onMenuCopyClicked();

    };
}}



