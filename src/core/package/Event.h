//
// Created by liu on 2016/12/16.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Event

namespace TCUIEdit { namespace Core { namespace Package
{
    class Event : public Base
    {
    protected:
        UI::Event* lastUI;
    public:
        Event(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}


