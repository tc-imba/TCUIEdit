//
// Created by liu on 2016/12/11.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace Core { namespace UI
{
    //***************************************************************************
    // [TriggerTypeDefaults]
    // Defines an optional default value for a trigger type used as a global variable
    // Key: variable type
    // Value 0: script text
    // Value 1: display text (if not present, script text will be used)
    //
    // If a type does not have an entry here, it will be set to null if it is a handle

    class TypeDefault : public Base
    {
    protected:
        QString script;
    public:
        TypeDefault(Package::Package *package, QPair<QString, QStringList> pair);

        Type *getOriginType() const;

        const QString getDisplayName() const;

    };

}}}

