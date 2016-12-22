//
// Created by liu on 2016/12/5.
//

#include "UIBase_Category.h"
//#include "UIBase_Event.h"
#include "package/UIPackage.h"
//#include "../UIProject.h"

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
        return this->_getDisplayName();
    }

    /*void UIBase_Category::displayDetail(UIMainTree *tree)
    {

        this->initDisplayDetail(tree);

        tree->addTopLevelItem(this->formRow("Display Text", this->display));

        tree->addTopLevelItem(this->formRow("Display text (In Editor)", this->getDisplay()));
        tree->addTopLevelItem(this->formRow("Icon image file", this->icon));
        tree->addTopLevelItem(this->formRow("Display flag (optional)", this->displayFlag));

        auto parent = this->formRow("Events");
        tree->addTopLevelItem(parent);

        for (auto it:this->_pkg->getBase(UIBase::TRIGGER_EVENT)->getData())
        {
            if (this->name == ((UIBase_Event *) it)->getCategory())
            {
                parent->addChild(this->formRow(it->getPackage()->getName(), it->getDisplayName()));
            }
        }

    }*/
};