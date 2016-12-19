//
// Created by liu on 2016/12/5.
//

#ifndef TCUIEDIT_UIPACKAGE_BASE_H
#define TCUIEDIT_UIPACKAGE_BASE_H

#include <QList>
#include <QPair>
#include "../UICore.h"
#include "../UIException.h"

#undef TCUIEDIT_UIPACKAGE_BASE_NAME
#define TCUIEDIT_UIPACKAGE_BASE_NAME UIBase
#define TCUIEDIT_UIPACKAGE_OPERATOR_INDEX TCUIEDIT_UIPACKAGE_BASE_NAME *operator[](unsigned int index){return this->data.size()>index?(TCUIEDIT_UIPACKAGE_BASE_NAME*)(this->data[index]):NULL;}
#define TCUIEDIT_UIPACKAGE_CAST_DATA static TCUIEDIT_UIPACKAGE_BASE_NAME *castData(UIBase* baseType){return (TCUIEDIT_UIPACKAGE_BASE_NAME*)(baseType);}

namespace TCUIEdit
{
    class UIPackage_Base
    {
    protected:

        QList<UIBase *> data;

        QPair<QString, QStringList> preprocessLine(QString &str);

        UIPackage *_pkg;

    public:

        UIPackage_Base(UIPackage *package);

        virtual void readLine(QString &str) = 0;

        QList<UIBase *> getData()
        { return this->data; }

        void readComment(QString &str);
    };
};


#endif //TCUIEDIT_UIPACKAGE_BASE_H
