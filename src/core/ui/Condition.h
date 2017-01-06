//
// Created by sunyi on 2016/12/21.
//

#pragma once

#include "Function.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerConditions]
    // Defines boolean condition functions
    // Key: condition function name

    // Value 0: first game version in which this function is valid
    // Value 1+: argument types
    // Note that the first argument is always a `trigger`, and is excluded here

    class Condition : public Function
    {
    public:
        Condition(package::Package *package, QPair<QString, QStringList> pair);

        ~Condition();

        QString trigData();
    };

}}}


