//
// Created by liu on 2016/12/16.
//

#ifndef TCUIEDIT_UIPACKAGE_EVENT_H
#define TCUIEDIT_UIPACKAGE_EVENT_H

#include  "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_Event

namespace TCUIEdit
{
    class UIPackage_Event : public UIPackage_Base
    {
    protected:
        UIBase_Event* lastUI;
    public:
        UIPackage_Event(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
};

#endif //TCUIEDIT_UIPACKAGE_EVENT_H
