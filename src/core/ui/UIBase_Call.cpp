//
// Created by liu on 2016/12/15.
//

#include "UIBase_Call.h"

namespace TCUIEdit
{

    UIBase_Call::UIBase_Call(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->type = TRIGGER_CALL;
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

    void UIBase_Call::add(QPair<QString, QStringList> pair)
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

    const QString UIBase_Call::getDisplayName() const
    {
        return this->name;
    }

    const QString &UIBase_Call::getCategory() const
    {
        return this->category;
    }

};