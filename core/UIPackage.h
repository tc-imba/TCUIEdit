//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIPACKAGE_H
#define TCUIEDIT_UIPACKAGE_H

#include "Core.h"

#define TCUIEDIT_UIPACKAGE_OPERATOR_INDEX operator[](unsigned int index){return this->data.size()>index?this->data[index]:NULL;}

namespace TCUIEdit
{


    class UIPackage
    {
    private:
        UIPackage_Category* category;
    };

    class UIPackage_Base
    {
    public:
        virtual void readLine(std::string &str) = 0;
    };

    class UIPackage_Category : UIPackage_Base
    {
    protected:
        std::vector<UIBase_Category *> data;
    public:
        UIBase_Category *TCUIEDIT_UIPACKAGE_OPERATOR_INDEX
        void readLine(std::string &str);
    };
};

#endif //TCUIEDIT_UIPACKAGE_H
