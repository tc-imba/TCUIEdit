//
// Created by liu on 2016/12/5.
//

#pragma once

#include "../core.h"
#include "../Exception.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UI::Base
#define TCUIEDIT_UIPACKAGE_OPERATOR_INDEX TCUIEDIT_UIPACKAGE_BASE_NAME *operator[](unsigned int index){return this->data.size()>index?(TCUIEDIT_UIPACKAGE_BASE_NAME*)(this->data[index]):NULL;}
#define TCUIEDIT_UIPACKAGE_CAST_DATA static TCUIEDIT_UIPACKAGE_BASE_NAME *castData(UI::Base* baseType){return (TCUIEDIT_UIPACKAGE_BASE_NAME*)(baseType);}

namespace TCUIEdit { namespace Core { namespace Package
{
    class Base
    {
    protected:

        QList<UI::Base *> data;

        QPair<QString, QStringList> preprocessLine(QString &str);

        Package *_pkg;

    public:

        Base(Package *package);

        virtual void readLine(QString &str) = 0;

        QList<UI::Base *> getData()
        { return this->data; }

        void readComment(QString &str);
    };
}}}



