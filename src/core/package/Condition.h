//
// Created by sunyi on 2016/12/22.
//

#pragma once
#include "Function.h"

#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Condition

namespace TCUIEdit { namespace core { namespace package
{
    class Condition : public Function
    {
    public:
        Condition(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
