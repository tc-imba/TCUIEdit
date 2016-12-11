//
// Created by liu on 2016/12/3.
//

#include "UIBase.h"
#include "UIProject.h"
#include "package/UIPackage.h"

#define _PROJ this->_pkg->getProject()

namespace TCUIEdit
{
    const char *UIBase::TYPE_NAME[UIBase::TYPE_NUM] =
            {"TriggerCategories", "TriggerTypes", "TriggerTypeDefaults", "TriggerParams",
             "TriggerEvents", "TriggerConditions", "TriggerActions", "TriggerCalls",
             "DefaultTriggerCategories", "DefaultTriggers"
            };

    UIBase::UIBase(UIPackage *package)
    {
        this->_pkg = package;
    }

    UIBase::TYPE UIBase::getType() const
    {
        return this->type;
    }

    const char *UIBase::getTypeName() const
    {
        return this->getTypeName(this->type);
    }

    const char *UIBase::getTypeName(TYPE type)
    {
        if (type >= 0 && type < UIBase::TYPE_NUM)
        {
            return UIBase::TYPE_NAME[type];
        }
        return "UNKNOWN_TYPE";
    }

    const QString &UIBase::getName() const
    {
        return this->name;
    }

    const QString UIBase::getDisplay() const
    {
        return this->_pkg->getWEString()->getValue(this->display);
    }

    void UIBase::setName(const QString &name)
    {
        _PROJ->getUIMap().removeUI(this);
        this->name = name;
        _PROJ->getUIMap().addUI(this);
    }

    UIPackage* UIBase::getPackage() const
    {
        return this->_pkg;
    }
}
