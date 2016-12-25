//
// Created by liu on 2016/12/15.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace Core { namespace UI
{
            enum FLAG{FLAG_DEFAULT,FLAG_CATEGORY};
            class Argument{
            public:
                QString type;
                QString Default;
                QString min;
                QString max;
                QString script;
                QString aiDefault;
                Argument(QPair<QString,QStringList> pair):type(""),Default(""),min(""),max(""),script(""),aiDefault(""){
                    auto it = pair.second.constBegin();
                    while (it != pair.second.constEnd())
                    {
                        if(*it=="type"){this->type=*++it;}
                        if(*it=="default"){this->Default=*++it;}
                        if(*it=="limit"){this->min=*++it;this->max=*++it;}
                        if(*it=="script"){this->script=*++it;}
                        if(*it=="aiDefault"){this->aiDefault=*++it;}
                    }
                }
            };
    //***************************************************************************
    // [TriggerEvents]
    // Defines events available in the editor
    // Key: script event function
    // Value 0: first game version in which this function is valid
    // Value 1+: argument types
    // Note that the first argument is always a `trigger`, and is excluded here

    class Event : public Base
    {
    protected:
        QString version, category,useWithAI;
        QList<Argument> arguments;
        bool Flag[2];
    public:
        Event(Package::Package *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

        const QString &getCategory() const;

    };

}}}



