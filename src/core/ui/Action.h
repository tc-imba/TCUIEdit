//
// Created by sunyi on 2016/12/22.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerActions]
    // Defines action functions
    // Key: action function name

    // Value 0: first game version in which this function is valid
    // Value 1+: argument types

    // Note that the first argument is always a `trigger`, and is excluded here

    class Action : public Base
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        Action(package::Package *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString formDisplay() const;

        const QString &getCategory() const;

    };

}}}


