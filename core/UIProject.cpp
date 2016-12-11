//
// Created by liu on 2016/12/4.
//

#include "UIProject.h"
#include "package/UIPackage.h"

namespace TCUIEdit
{

    UIPackage *UIProject::createPackage()
    {
        auto pkg = new UIPackage(this);
        this->uiPkg.push_back(pkg);
        return pkg;
    }

    UIPackage *UIProject::createPackage(const QString &basePath)
    {
        auto pkg = new UIPackage(this, basePath);
        this->uiPkg.push_back(pkg);
        return pkg;
    }

    UIBase *UIProject::matchUI(const QString &name, UIBase::TYPE type) const
    {
        auto list = this->uiMap.getUI(name);
        UIBase *base = NULL;
        int index = -1;
        for (auto it:list)
        {
            if (it->getType() == type)
            {
                auto itIndex = this->uiPkg.indexOf(it->getPackage());
                if (itIndex >= 0 && (index < 0 || itIndex < index))
                {
                    index = itIndex;
                    base = it;
                }
            }
        }
        return base;
    }

};