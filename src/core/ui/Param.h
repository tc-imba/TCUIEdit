//
// Created by liu on 2016/12/13.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerParams]
    // Defines possible values for variable types
    // Key: arbitrary text
    // Value 0: first game version in which this parameter is valid
    // Value 1: variable type
    // Value 2: code text (used in script)
    // Value 3: display text
    //
    // Note: If the code text is a literal string, surround it with backward single quotes (`),
    //       and they will be converted to double quotes in the script.

    class Param : public Base
    {
    protected:
        QString version, variable, script;
    public:
        Param(package::Package *package, QPair<QString, QStringList> pair);

        Type *getOriginType() const;

        const QString formDisplay() const;


    };

}}}


