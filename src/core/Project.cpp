//
// Created by liu on 2016/12/4.
//

#include "Project.h"
#include "package/Package.h"

namespace TCUIEdit { namespace Core
{

    Package::Package *Project::createPackage()
    {
        auto pkg = new Package::Package(this);
        this->uiPkg.push_back(pkg);
        return pkg;
    }

    Package::Package *Project::createPackage(const QString &basePath, const QString &name)
    {
        auto pkg = new Package::Package(this, basePath, name);
        this->uiPkg.push_back(pkg);
        return pkg;
    }

    UI::Base *Project::matchUI(const QString &name, UI::Base::TYPE type) const
    {
        auto list = this->uiMap.getUI(name);
        UI::Base *base = NULL;
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

}}