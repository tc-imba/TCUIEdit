//
// Created by liu on 2016/12/15.
//

#pragma once

#include "Function.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerEvents]
    // Defines events available in the editor
    // Key: script event function
    // Value 0: first game version in which this function is valid
    // Value 1+: argument types
    // Note that the first argument is always a `trigger`, and is excluded here

    class Event : public Function
    {
    public:
        Event(package::Package *package, QPair<QString, QStringList> pair);
    };

}}}



