//
// Created by liu on 2016/12/21.
//

#pragma once

#include <QColor>
#include <QTextStream>
#include <QMenu>
#include <QMessageBox>

#include "../../core/core.h"
#include "../../core/Error.h"
#include "../../core/ui/all.h"
#include "../../core/package/Package.h"
#include "../../core/Project.h"
#include "../../components/property_browser/Browser.h"
#include "../../components/property_browser/Editor.h"

#include "../chaindialog/ChainDialog.h"

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
        QAction *m_menuCopy, *m_menuOpen, *m_menuRedirect;
        property_browser::Row *m_currentRow;

    public:
        Base(property_browser::Browser *browser, core::ui::Base *ui);

        virtual ~Base();

        virtual void refresh();

        void showError(property_browser::Row *row, const core::Error &error);

        int showErrorDialog(const core::Error &error);

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



