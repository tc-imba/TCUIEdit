//
// Created by liu on 2016/12/16.
//

#include "UIPackage_Condition.h"
#include "../base/UIBase_Condition.h"
#include "../UIProject.h"
#include "../package/UIPackage.h"

namespace TCUIEdit
{
    UIPackage_Condition::UIPackage_Condition(UIPackage *package) : UIPackage_Base(package)
    {

    }

    void UIPackage_Condition::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        if (pair.first[0] != '_')
        {
            this->lastUI = new UIBase_Condition(this->_pkg, pair);
            auto item = static_cast<UIBase *>(this->lastUI);
            this->data.push_back(item);
        }
        else if (lastUI != NULL)
        {
            auto lastName = this->lastUI->getName();
            auto name = pair.first.mid(1, lastName.length());
            if (lastName == name)
            {
                pair.first = pair.first.mid(1 + lastName.length());
                this->lastUI->add(pair);
            }
        }
    }


};
