//
// Created by liu on 2016/12/3.
//

#include "UIBase.h"
#include "UIProject.h"

namespace TCUIEdit
{
    const char *UIBase::TYPE_NAME[UIBase::TYPE_NUM] =
            {"TriggerCategories", "TriggerTypes", "TriggerTypeDefaults", "TriggerParams",
             "TriggerEvents", "TriggerConditions", "TriggerActions", "TriggerCalls",
             "DefaultTriggerCategories", "DefaultTriggers"
            };

    UIBase::UIBase(UIProject *project)
    {
        this->_proj = project;
    }

    const char *UIBase::getTypeName() const
    {
        return this->TYPE_NAME[this->type];
    }

    const QString &UIBase::getName() const
    {
        return this->name;
    }

    void UIBase::setName(QString &name)
    {
        try
        {
            this->_proj->getUIMap().removeUI(this);
            this->name = name;
            this->_proj->getUIMap().addUI(this);
        }
        catch (QException &e)
        {
            throw e;
        }
    }

    void UIBase::setName(const QString &name)
    {
        try
        {
            QString str = name;
            this->setName(str);
        }
        catch (QException &e)
        {
            throw e;
        }
    }


}