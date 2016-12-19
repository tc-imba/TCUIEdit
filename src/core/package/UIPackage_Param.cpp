//
// Created by liu on 2016/12/14.
//

#include "UIPackage_Param.h"
#include "../base/UIBase_Param.h"

namespace TCUIEdit
{
    UIPackage_Param::UIPackage_Param(UIPackage *package) : UIPackage_Base(package)
    {

    }

    void UIPackage_Param::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        auto item = static_cast<UIBase *>(new UIBase_Param(this->_pkg, pair));
        this->data.push_back(item);
    }


};