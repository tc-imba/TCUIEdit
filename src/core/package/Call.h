//
// Created by sunyi on 2016/12/22.
//

#pragma once
#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Event

namespace TCUIEdit { namespace Core { namespace Package
{
    class Call : public Base
    {
    protected:
        UI::Call* lastUI;
    public:
        Call(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}

