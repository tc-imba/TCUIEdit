//
// Created by liu on 2016/12/4.
//

#include "Project.h"
#include "package/Package.h"

namespace TCUIEdit { namespace core
{


    QMultiHash<QString, ui::WEString *> &Project::weStringMap()
    {
        return m_weStringMap;
    }

    QMap<QString, QPair<bool, int> > &Project::categoryNumMap()
    {
        return m_categoryNumMap;
    }

    QMap<QString, QPair<bool, int> > &Project::typeNumMap()
    {
        return m_typeNumMap;
    }

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

    const QList<package::Package *> &Project::packages() const
    {
        return m_packages;
    }

    void Project::addUI(ui::Base *ui)
    {
        if (ui == NULL)
        {
            throw ExceptionUndefined();
        }

        auto name = ui->name();
        name = name.toLower();

        if (m_uiMap.find(name, ui) == m_uiMap.end())
        {
            m_uiMap.insert(name, ui);
        }
        if (ui->type() == ui::Base::TRIGGER_CATEGORY)
        {
            auto it = m_categoryNumMap.find(name);
            if (it != m_categoryNumMap.end())(*it).first = true;
            else m_categoryNumMap.insert(name, qMakePair(true, 0));
        }
        else if (ui->type() == ui::Base::TRIGGER_TYPE)
        {
            auto it = m_typeNumMap.find(name);
            if (it != m_typeNumMap.end())(*it).first = true;
            else m_typeNumMap.insert(name, qMakePair(true, 0));
        }
        /*else if (ui->isFunction())
        {
            auto category = ((ui::Function *) ui)->category();
            auto it = m_categoryNumMap.find(category);
            if (it != m_categoryNumMap.end())(*it).second++;
            else m_categoryNumMap.insert(category, qMakePair(false, 1));
            if (ui->type() == ui::Base::TRIGGER_CALL)
            {
                auto type = ((ui::Call *) ui)->returnType();
                it = m_typeNumMap.find(type);
                if (it != m_typeNumMap.end())(*it).second++;
                else m_typeNumMap.insert(type, qMakePair(false, 1));
            }
        }*/
        /*else
        {
            throw UIExceptionRedefined();
        }*/
    }

    QList<ui::Base *> Project::getUI(const QString &name) const
    {
        return m_uiMap.values(name.toLower());
    }

    QList<ui::Base *> Project::examineUI(const ui::Base *ui) const
    {
        if (ui == NULL)
        {
            throw ExceptionUndefined();
        }
        auto list = this->getUI(ui->name());
        for (auto it = list.begin(); it != list.end();)
        {
            if (*it == ui)it = list.erase(it);
            else ++it;
        }
        return list;
    }

    void Project::removeUI(ui::Base *ui)
    {
        if (ui == NULL)
        {
            throw ExceptionUndefined();
        }

        auto name = ui->name();
        name = name.toLower();

        /*if (this->hashtable.find(name, ui) == this->hashtable.end())
        {
            throw UIExceptionNotFound();
        }*/
        m_uiMap.remove(name, ui);
        if (ui->type() == ui::Base::TRIGGER_CATEGORY)
        {
            if (this->matchUI(name, ui::Base::TRIGGER_CATEGORY) == NULL)
            {
                auto it = m_categoryNumMap.find(name);
                if (it != m_categoryNumMap.end())(*it).first = false;
                else m_categoryNumMap.insert(name, qMakePair(false, 0));
            }
        }
        else if (ui->type() == ui::Base::TRIGGER_TYPE)
        {
            if (this->matchUI(name, ui::Base::TRIGGER_TYPE) == NULL)
            {
                auto it = m_typeNumMap.find(name);
                if (it != m_typeNumMap.end())(*it).first = false;
                else m_typeNumMap.insert(name, qMakePair(false, 0));
            }
        }
        /*else if (ui->isFunction())
        {
            auto category = ((ui::Function *) ui)->category();
            auto it = m_categoryNumMap.find(category);
            if (it != m_categoryNumMap.end())(*it).second--;
            if (ui->type() == ui::Base::TRIGGER_CALL)
            {
                auto type = ((ui::Call *) ui)->returnType();
                it = m_typeNumMap.find(type);
                if (it != m_typeNumMap.end())(*it).second--;
            }
        }*/
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