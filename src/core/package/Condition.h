//
// Created by sunyi on 2016/12/22.
//

#pragma once
#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Condition

namespace TCUIEdit { namespace core { namespace package
{
    class Condition : public Base
    {
    protected:
        ui::Condition* m_lastUI;
    public:
        Condition(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}

