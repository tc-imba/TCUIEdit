//
// Created by sunyi on 2016/12/22.
//

#pragma once
#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Condition

namespace TCUIEdit { namespace Core { namespace Package
{
    class Condition : public Base
    {
    protected:
        UI::Condition* lastUI;
    public:
        Condition(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}

