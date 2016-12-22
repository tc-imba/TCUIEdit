//
// Created by sunyi on 2016/12/22.
//

#ifndef TCUIEDIT_UIPACKAGE_ACTION_H
#define TCUIEDIT_UIPACKAGE_ACTION_H
#include "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_Action

namespace TCUIEdit
{
    class UIPackage_Action : public UIPackage_Base
    {
    protected:
        action* lastUI;
    public:
        UIPackage_Action(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
};
#endif //TCUIEDIT_UIPACKAGE_ACTION_H
