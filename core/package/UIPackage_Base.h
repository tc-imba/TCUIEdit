//
// Created by liu on 2016/12/5.
//

#ifndef TCUIEDIT_UIPACKAGE_BASE_H
#define TCUIEDIT_UIPACKAGE_BASE_H

#include <QVector>
#include <QPair>
#include "../UICore.h"
#include "../UIException.h"

#define TCUIEDIT_UIPACKAGE_OPERATOR_INDEX operator[](unsigned int index){return this->data.size()>index?this->data[index]:NULL;}

namespace TCUIEdit
{
    class UIPackage_Base
    {
    protected:

        QPair<QString, QStringList> preprocessLine(QString &str);

        UIPackage *_pkg;

    public:

        UIPackage_Base(UIPackage *package);

        virtual void readLine(QString &str) = 0;

        void readComment(QString &str);
    };
};


#endif //TCUIEDIT_UIPACKAGE_BASE_H
