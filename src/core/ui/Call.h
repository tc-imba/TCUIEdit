//
// Created by sunyi on 2016/12/22.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerCalls]
    // Defines function calls which may be used as parameter values
    // Key: Function name

    // Value 0: first game version in which this function is valid
    // Value 1: flag (0 or 1) indicating if the call can be used in events
    // Value 2: return type
    // Value 3+: argument types
    //
    // Note: Operators are specially handled by the editor


    class Call : public Base
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        Call(package::Package *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString formDisplay() const;

        const QString &getCategory() const;

        //void displayDetail(UIMainTree *tree);
    };

}}}


