//
// Created by liu on 2016/12/14.
//

#ifndef TCUIEDIT_UIPACKAGE_PARAM_H
#define TCUIEDIT_UIPACKAGE_PARAM_H

#include "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_Param

namespace TCUIEdit
{
    class UIPackage_Param : public UIPackage_Base
    {
    public:
        UIPackage_Param(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
};

#endif //TCUIEDIT_UIPACKAGE_PARAM_H
