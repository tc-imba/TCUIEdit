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

using namespace TCUIEdit::core;

namespace TCUIEdit
{
    class UIMainView_Base : public QObject
    {
    Q_OBJECT
    protected:
        property_browser::Browser *m_browser;

    public:
        UIMainView_Base(property_browser::Browser *browser);

        virtual void refresh();

    protected slots:

        virtual void nameEdited(TCUIEdit::property_browser::Row *row);

    };
};



