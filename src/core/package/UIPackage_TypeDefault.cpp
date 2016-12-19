//
// Created by liu on 2016/12/11.
//

#include "UIPackage_TypeDefault.h"
#include "../base/UIBase_TypeDefault.h"

namespace TCUIEdit
{
    UIPackage_TypeDefault::UIPackage_TypeDefault(UIPackage *package) : UIPackage_Base(package)
    {

    }

    void UIPackage_TypeDefault::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        auto item = static_cast<UIBase *>(new UIBase_TypeDefault(this->_pkg, pair));
        this->data.push_back(item);
    }


};
