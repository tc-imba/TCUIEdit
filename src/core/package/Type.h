//
// Created by liu on 2016/12/8.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Type

namespace TCUIEdit { namespace Core { namespace Package
{
    class Type : public Base
    {

    protected:
        //QVector<UI::Type *> data;
    public:
        Type(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);

        //void readComment(QString &str, COMMENT_TYPE cType);
    };

}}}



