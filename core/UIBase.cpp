//
// Created by liu on 2016/12/3.
//

#include "UIBase.h"

namespace TCUIEdit
{
    const char *UIBase::TYPE_NAME[UIBase::TYPE_NUM] =
            {"TriggerCategories", "TriggerTypes", "TriggerTypeDefaults", "TriggerParams",
             "TriggerEvents", "TriggerConditions", "TriggerActions", "TriggerCalls",
             "DefaultTriggerCategories", "DefaultTriggers"
            };

    const char *UIBase::getTypeName() const
    {
        return this->TYPE_NAME[this->type];
        //return "0";
    }

    std::string UIBase::getName() const
    {
        return this->name;
    }


}