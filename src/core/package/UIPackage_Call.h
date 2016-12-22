//
// Created by sunyi on 2016/12/22.
//

#ifndef TCUIEDIT_UIPACKAGE_CALL_H
#define TCUIEDIT_UIPACKAGE_CALL_H
#include "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_Event

namespace TCUIEdit
{
    class UIPackage_Call : public UIPackage_Base
    {
    protected:
        UIBase_Call* lastUI;
    public:
        UIPackage_Call(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
};
#endif //TCUIEDIT_UIPACKAGE_CALL_H
