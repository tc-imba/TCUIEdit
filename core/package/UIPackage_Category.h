//
// Created by liu on 2016/12/5.
//

#ifndef TCUIEDIT_UIPACKAGE_CATEGORY_H
#define TCUIEDIT_UIPACKAGE_CATEGORY_H

#include "../UICore.h"
#include "UIPackage_Base.h"

namespace TCUIEdit
{
    class UIPackage_Category : UIPackage_Base
    {
    protected:
        std::vector<UIBase_Category *> data;
    public:
        UIBase_Category *TCUIEDIT_UIPACKAGE_OPERATOR_INDEX

        void readLine(std::string &str);
    };

};


#endif //TCUIEDIT_UIPACKAGE_CATEGORY_H
