//
// Created by liu on 2016/12/4.
//

#include "Project.h"
#include "package/Package.h"

namespace TCUIEdit { namespace core
{

    package::Package *Project::createPackage()
    {
        auto pkg = new package::Package(this);
        m_packages.push_back(pkg);
        return pkg;
    }

    package::Package *Project::createPackage(const QString &basePath, const QString &name)
    {
        auto pkg = new package::Package(this, basePath, name);
        m_packages.push_back(pkg);
        return pkg;
    }

    QList<package::Package *>* Project::packages()
    {
        return &m_packages;
    }

    ui::Base *Project::matchUI(const QString &name, ui::Base::TYPE type) const
    {
        auto list = this->uiMap.getUI(name);
        ui::Base *base = NULL;
        int index = -1;
        for (auto it:list)
        {
            if (it->type() == type)
            {
                auto itIndex = m_packages.indexOf(it->package());
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