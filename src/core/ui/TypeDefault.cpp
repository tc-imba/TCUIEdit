//
// Created by liu on 2016/12/11.
//

#include "TypeDefault.h"
#include "Type.h"
#include "../package/UIPackage.h"
#include "../UIProject.h"

namespace TCUIEdit{namespace UI
{

    TypeDefault::TypeDefault(UIPackage *package, QPair<QString, QStringList> pair) : Base(package)
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

    UIBase_Type *TypeDefault::getOriginType() const
    {
        return (UIBase_Type *) (this->_pkg->getProject()->matchUI(this->name, TRIGGER_TYPE));
    }

    const QString TypeDefault::getDisplayName() const
    {
        auto type = this->getOriginType();
        if (type)
        {
            return type->getDisplayName();
        }
        return "";
    }


}};