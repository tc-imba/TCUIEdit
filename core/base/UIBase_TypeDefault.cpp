//
// Created by liu on 2016/12/11.
//

#include <package/UIPackage.h>
#include "UIBase_TypeDefault.h"
#include "UIBase_Type.h"
#include "../UIProject.h"

namespace TCUIEdit
{

    UIBase_TypeDefault::UIBase_TypeDefault(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->type = TRIGGER_TYPE_DEFAULT;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: script text
        if (it != pair.second.constEnd())
        {
            this->script = *it++;
        }
        // Value 1: display text (if not present, script text will be used)
        if (it != pair.second.constEnd())
        {
            this->display = *it++;
        }
    }

    UIBase_Type *UIBase_TypeDefault::getOriginType() const
    {
        return (UIBase_Type *) (this->_pkg->getProject()->matchUI(this->name, TRIGGER_TYPE));
    }

    const QString UIBase_TypeDefault::getDisplayName() const
    {
        auto type = this->getOriginType();
        if (type)
        {
            return type->getDisplayName();
        }
        return "";
    }

};