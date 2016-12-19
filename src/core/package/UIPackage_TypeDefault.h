//
// Created by liu on 2016/12/11.
//

#ifndef TCUIEDIT_UIPACKAGE_TYPEDEFAULT_H
#define TCUIEDIT_UIPACKAGE_TYPEDEFAULT_H

#include "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_TypeDefault

namespace TCUIEdit
{
    class UIPackage_TypeDefault : public UIPackage_Base
    {
    public:
        UIPackage_TypeDefault(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);
    };
};

#endif //TCUIEDIT_UIPACKAGE_TYPEDEFAULT_H
