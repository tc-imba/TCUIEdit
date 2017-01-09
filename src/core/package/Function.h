//
// Created by liu on 17-1-9.
//

#pragma once

#include "Base.h"

#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Function

namespace TCUIEdit { namespace core { namespace package
{

    class Function : public Base
    {
    protected:
        ui::Function *m_lastUI;

        void _addLine(QPair<QString, QStringList> pair);

    public:
        Function(Package *package);

        virtual ~Function() = 0;

        TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        TCUIEDIT_UIPACKAGE_CAST_DATA

        virtual void readLine(QString &str) = 0;
    };

}}}

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
