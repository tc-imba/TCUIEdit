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

    QList<package::Package *> *Project::packages()
    {
        return &m_packages;
    }

    void Project::addUI(ui::Base *UI)
    {
        if (UI == NULL)
        {
            throw ExceptionUndefined();
        }

        auto name = UI->name();

        if (m_uiMap.find(name, UI) == m_uiMap.end())
        {
            m_uiMap.insert(name, UI);
        }
        /*else
        {
            throw UIExceptionRedefined();
        }*/
    }

    QList<ui::Base *> Project::getUI(const QString &name) const
    {
        return m_uiMap.values(name);
    }

    QList<ui::Base *> Project::examineUI(const ui::Base *UI) const
    {
        if (UI == NULL)
        {
            throw ExceptionUndefined();
        }
        auto list = this->getUI(UI->name());
        for (auto it = list.begin(); it != list.end();)
        {
            if (*it == UI)it = list.erase(it);
            else ++it;
        }
        return list;
    }

    void Project::removeUI(ui::Base *UI)
    {
        if (UI == NULL)
        {
            throw ExceptionUndefined();
        }

        auto name = UI->name();

        /*if (this->hashtable.find(name, UI) == this->hashtable.end())
        {
            throw UIExceptionNotFound();
        }*/
        m_uiMap.remove(name, UI);
    }

    ui::Base *Project::matchUI(const QString &name, ui::Base::TYPE type) const
    {
        auto list = this->getUI(name);
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