//
// Created by liu on 2016/12/5.
//

#ifndef TCUIEDIT_UIPACKAGE_BASE_H
#define TCUIEDIT_UIPACKAGE_BASE_H

#include "../UICore.h"

#define TCUIEDIT_UIPACKAGE_OPERATOR_INDEX operator[](unsigned int index){return this->data.size()>index?this->data[index]:NULL;}

namespace TCUIEdit
{
    class UIPackage_Base
    {
    public:
        virtual void readLine(QString &str) = 0;
    };
};


#endif //TCUIEDIT_UIPACKAGE_BASE_H
