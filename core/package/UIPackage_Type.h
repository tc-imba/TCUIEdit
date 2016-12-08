//
// Created by liu on 2016/12/8.
//

#ifndef TCUIEDIT_UIPACKAGE_TYPE_H
#define TCUIEDIT_UIPACKAGE_TYPE_H

#include  "../UICore.h"
#include "UIPackage_Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase_Type

namespace TCUIEdit
{
    class UIPackage_Type : public UIPackage_Base
    {

    protected:
        //QVector<UIBase_Type *> data;
    public:
        UIPackage_Type(UIPackage *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);

        //void readComment(QString &str, COMMENT_TYPE cType);
    };

};


#endif //TCUIEDIT_UIPACKAGE_TYPE_H
