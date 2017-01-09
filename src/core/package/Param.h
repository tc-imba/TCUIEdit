//
// Created by liu on 2016/12/14.
//

#pragma once

#include "Base.h"

#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Param

namespace TCUIEdit { namespace core { namespace package
{
    class Param : public Base
    {
    public:
        Param(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}

#undef TCUIEDIT_UIPACKAGE_BASE_NAME

