//
// Created by liu on 2016/12/11.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
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
        QString m_script;
    public:
        TypeDefault(package::Package *package, QPair<QString, QStringList> pair);

        ~TypeDefault();

        Type *getOriginType() const;

        const QString formDisplay() const;

        const QString &script() const;

        void setScript(const QString &script);

        virtual QString trigData();

    };

}}}

