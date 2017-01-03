//
// Created by sunyi on 2016/12/22.
//

#pragma once

#include "Function.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerActions]
    // Defines action functions
    // Key: action function name

    // Value 0: first game version in which this function is valid
    // Value 1+: argument types

    // Note that the first argument is always a `trigger`, and is excluded here

    class Action : public Function
    {
    public:
        Action(package::Package *package, QPair<QString, QStringList> pair);

        ~Action();
    };

}}}


