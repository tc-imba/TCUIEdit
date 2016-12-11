//
// Created by liu on 2016/12/5.
//

#include "UIBase_Category.h"

namespace TCUIEdit
{

    UIBase_Category::UIBase_Category(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->type = TRIGGER_CATEGORY;

        this->setName(pair.first);

        auto it = pair.second.constBegin();

        // Value 0: Display text
        if (it != pair.second.constEnd())
        {
            this->display = *it++;
        }
        // Value 1: Icon image file
        if (it != pair.second.constEnd())
        {
            this->icon = *it++;
        }
        // Value 2: Optional flag (defaults to 0) indicating to disable display of category name
        if (it != pair.second.constEnd())
        {
            this->displayFlag = *it++;
        }
    }

    const QString UIBase_Category::getDisplayName() const
    {
        if (this->displayFlag == "1")
        {
            return this->name;
        }
        return this->name + " - " + this->getDisplay();
    }
};