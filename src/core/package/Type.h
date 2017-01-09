//
// Created by liu on 2016/12/8.
//

#pragma once

#include "Base.h"

#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Type

namespace TCUIEdit { namespace core { namespace package
{
    class Type : public Base
    {

    protected:
        //QVector<ui::Type *> data;
    public:
        Type(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);

        //void readComment(QString &str, COMMENT_TYPE cType);
    };

}}}

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
