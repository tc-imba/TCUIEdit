//
// Created by liu on 2016/12/16.
//

#include "UIPackage_Action.h"
#include "../base/UIBase_Action.h"
#include "../UIProject.h"
#include "../package/UIPackage.h"

namespace TCUIEdit
{
    UIPackage_Action::UIPackage_Action(UIPackage *package) : UIPackage_Base(package)
    {

    }

    void UIPackage_Action::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        if (pair.first[0] != '_')
        {
            this->lastUI = new action(this->_pkg, pair);
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
