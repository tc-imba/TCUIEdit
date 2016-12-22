//
// Created by liu on 2016/12/5.
//

#pragma once

#include "Base.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Category

namespace TCUIEdit { namespace Core { namespace Package
{
    class Category : public Base
    {

    protected:
        // QVector<UI::Category *> data;
    public:
        Category(Package *package);

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        void readLine(QString &str);

        //void readComment(QString &str, COMMENT_TYPE cType);
    };

}}}



