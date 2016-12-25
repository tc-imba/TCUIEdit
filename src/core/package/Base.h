//
// Created by liu on 2016/12/5.
//

#pragma once

#include "../core.h"
#include "../Exception.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME ui::Base
#define TCUIEDIT_UIPACKAGE_OPERATOR_INDEX TCUIEDIT_UIPACKAGE_BASE_NAME *operator[](unsigned int index){return m_data.size()>index?(TCUIEDIT_UIPACKAGE_BASE_NAME*)(m_data[index]):NULL;}
#define TCUIEDIT_UIPACKAGE_CAST_DATA static TCUIEDIT_UIPACKAGE_BASE_NAME *castData(ui::Base* baseType){return (TCUIEDIT_UIPACKAGE_BASE_NAME*)(baseType);}

namespace TCUIEdit { namespace core { namespace package
{
    class Base
    {
    protected:

        QList<ui::Base *> m_data;

        QPair<QString, QStringList> _preprocessLine(QString &str);

        Package *m_pkg;

    public:

        Base(Package *package);

        virtual void readLine(QString &str) = 0;

        QList<ui::Base *> data();

        void readComment(QString &str);
    };
}}}



