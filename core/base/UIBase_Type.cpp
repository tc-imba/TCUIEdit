//
// Created by liu on 2016/12/8.
//

#include "UIBase_Type.h"

namespace TCUIEdit
{

    UIBase_Type::UIBase_Type(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->type = TRIGGER_TYPE;

        this->setName(pair.first);

        auto it = pair.second.constBegin();

        // Value 0: first game version in which this type is valid
        if (it != pair.second.constEnd())
        {
            this->version = *it++;
        }
        // Value 1: flag (0 or 1) indicating if this type can be a global variable
        if (it != pair.second.constEnd())
        {
            this->globalFlag = *it++;
        }
        // Value 2: flag (0 or 1) indicating if this type can be used with comparison operators
        if (it != pair.second.constEnd())
        {
            this->compareFlag = *it++;
        }
        // Value 3: string to display in the editor
        if (it != pair.second.constEnd())
        {
            this->display = *it++;
        }
        // Value 4: base type, used only for custom types
        if (it != pair.second.constEnd())
        {
            this->baseType = *it++;
        }
        // Value 5: import type, for strings which represent files (optional)
        if (it != pair.second.constEnd())
        {
            this->importType = *it++;
        }
        // Value 6: flag (0 or 1) indicating to treat this type as the base type in the editor
        if (it != pair.second.constEnd())
        {
            this->baseFlag = *it++;
        }


    }

    const QString UIBase_Type::getDisplayName() const
    {
        return this->_getDisplayName();
    }

};