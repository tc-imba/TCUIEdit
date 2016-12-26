//
// Created by liu on 2016/12/21.
//

#pragma once

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
    public:
        Base(property_browser::Browser *browser, core::ui::Base *ui);

        virtual void refresh();

    protected slots:

        virtual void nameEdited(TCUIEdit::property_browser::Row *row);

    };
}}



