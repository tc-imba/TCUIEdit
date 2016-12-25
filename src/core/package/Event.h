//
// Created by liu on 2016/12/16.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Event

namespace TCUIEdit { namespace core { namespace package
{
    class Event : public Base
    {
    protected:
        ui::Event* m_lastUI;
    public:
        Event(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}


