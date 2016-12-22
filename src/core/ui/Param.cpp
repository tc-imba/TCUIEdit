//
// Created by liu on 2016/12/13.
//

#include "Param.h"
#include "Type.h"
#include "../package/UIPackage.h"
#include "../UIProject.h"

namespace TCUIEdit{namespace UI
{

    Param::Param(UIPackage *package, QPair<QString, QStringList> pair) : Base(package)
    {
        this->type = TRIGGER_PARAM;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this parameter is valid
        if (it != pair.second.constEnd())
        {
            this->version = *it++;
        }
        // Value 1: variable type
        if (it != pair.second.constEnd())
        {
            this->variable = *it++;
        }
        // Value 2: code text (used in script)
        if (it != pair.second.constEnd())
        {
            this->script = *it++;
        }
        // Value 3: display text
        if (it != pair.second.constEnd())
        {
            this->display = *it++;
        }

    }

    UIBase_Type *Param::getOriginType() const
    {
        return (UIBase_Type *) (this->_pkg->getProject()->matchUI(this->variable, TRIGGER_TYPE));
    }

    const QString Param::getDisplayName() const
    {
        auto type = this->getOriginType();
        if (type)
        {
            QString str = type->getDisplayName();
            if (str != "")
            {
                return this->name + " ( " + str + " )";
            }
        }
        return this->name;
    }

};