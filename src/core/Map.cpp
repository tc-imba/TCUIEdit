//
// Created by liu on 2016/12/4.
//

#include "Map.h"

namespace TCUIEdit { namespace core
{

    Map::Map()
    {

    }

    void Map::addUI(ui::Base *UI)
    {
        if (UI == NULL)
        {
            throw ExceptionUndefined();
        }

        auto name = UI->name();

        if (this->hashtable.find(name, UI) == this->hashtable.end())
        {
            this->hashtable.insert(name, UI);
        }
        /*else
        {
            throw UIExceptionRedefined();
        }*/
    }


    /*QList<UIBase *> Map::getUI(QString &name) const
    {
        return this->hashtable.values(name);
    }*/

    QList<ui::Base *> Map::getUI(const QString &name) const
    {
        return this->hashtable.values(name);
    }

    void Map::removeUI(ui::Base *UI)
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
        this->hashtable.remove(name, UI);
    }
}}