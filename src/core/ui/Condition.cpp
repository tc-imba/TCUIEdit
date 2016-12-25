//
// Created by sunyi on 2016/12/21.
//


#include "Condition.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Condition::Condition(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_CONDITION;
        this->defaultsFlag = this->categoryFlag = false;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this function is valid
        if (it != pair.second.constEnd())
        {
            this->version = *it++;
        }
        // Value 1+: argument types
        while (it != pair.second.constEnd())
        {
            this->arguments.push_back(QPair<QString, QString>(*it++, ""));
        }
    }

    void Condition::add(QPair<QString, QStringList> pair)
    {
        if (pair.first == "_Defaults" && !this->defaultsFlag)
        {
            this->defaultsFlag = true;
            auto it = pair.second.constBegin();
            auto it2 = this->arguments.begin();
            while (it != pair.second.constEnd())
            {
                if (it2 != this->arguments.end())
                {
                    (*it2++).second = (*it++);
                }
                else
                {
                    this->arguments.push_back(QPair<QString, QString>("", *it++));
                    it2++;
                }
            }
        }
        else if (pair.first == "_Category" && !this->categoryFlag)
        {
            this->categoryFlag = true;
            auto it = pair.second.constBegin();
            if (it != pair.second.constEnd())
            {
                this->category = *it++;
            }
        }
    }

    const QString Condition::formDisplay() const
    {
        return m_name;
    }

    const QString &Condition::getCategory() const
    {
        return this->category;
    }


}}}