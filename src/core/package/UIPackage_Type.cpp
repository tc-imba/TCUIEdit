//
// Created by liu on 2016/12/8.
//

#include "UIPackage_Type.h"
#include "../base/UIBase_Type.h"

namespace TCUIEdit
{
    UIPackage_Type::UIPackage_Type(UIPackage *package) : UIPackage_Base(package)
    {

    }

    void UIPackage_Type::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        auto item = static_cast<UIBase *>(new UIBase_Type(this->_pkg, pair));
        this->data.push_back(item);
    }


};