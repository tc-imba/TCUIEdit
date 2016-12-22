//
// Created by sunyi on 2016/12/22.
//

#ifndef TCUIEDIT_UIPACKAGE_CONDITION_H
#define TCUIEDIT_UIPACKAGE_CONDITION_H
#include "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_Condition

namespace TCUIEdit
{
    class UIPackage_Condition : public UIPackage_Base
    {
    protected:
        UIBase_Condition* lastUI;
    public:
        UIPackage_Condition(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
};
#endif //TCUIEDIT_UIPACKAGE_CONDITION_H
