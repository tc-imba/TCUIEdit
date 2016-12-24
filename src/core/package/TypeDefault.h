//
// Created by liu on 2016/12/11.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::TypeDefault

namespace TCUIEdit { namespace core { namespace package
{
    class TypeDefault : public Base
    {
    public:
        TypeDefault(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
}}}


