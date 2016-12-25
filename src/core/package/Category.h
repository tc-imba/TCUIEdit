//
// Created by liu on 2016/12/5.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Category

namespace TCUIEdit { namespace core { namespace package
{
    class Category : public Base
    {

    protected:
        // QVector<ui::Category *> data;
    public:
        Category(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);

        //void readComment(QString &str, COMMENT_TYPE cType);
    };

}}}



