//
// Created by liu on 2016/12/14.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Param

namespace TCUIEdit { namespace Core { namespace Package
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


