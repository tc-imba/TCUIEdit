//
// Created by liu on 2016/12/4.
//

#include "UIMap.h"

namespace TCUIEdit
{

    UIMap::UIMap()
    {

    }

    void UIMap::addUI(UIBase *UI)
    {
        if (UI == NULL)
        {
            throw UIExceptionUndefined();
        }

        auto name = UI->getName();

        if (this->hashtable.find(name, UI) == this->hashtable.end())
        {
            this->hashtable.insert(name, UI);
        }
        /*else
        {
            throw UIExceptionRedefined();
        }*/
    }


    QList<UIBase *> UIMap::getUI(QString &name)
    {
        return this->hashtable.values();
    }

    QList<UIBase *> UIMap::getUI(const QString &name)
    {
        return this->hashtable.values();
    }

    void UIMap::removeUI(UIBase *UI)
    {
        if (UI == NULL)
        {
            throw UIExceptionUndefined();
        }

        auto name = UI->getName();

        /*if (this->hashtable.find(name, UI) == this->hashtable.end())
        {
            throw UIExceptionNotFound();
        }*/
        this->hashtable.remove(name, UI);
    }
};