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
        QString m_version, m_variableType, m_script;
    public:
        Param(package::Package *package, QPair<QString, QStringList> pair);

        ~Param();

        const QString& version() const ;

        void setVersion(const QString& version);

        const QString &variableType() const;

        void setVariableType(const QString &variableType);

        const QString &script() const;

        void setScript(const QString &script);

        Type *getOriginType() const;

        const QString formDisplay() const;


    };

}}}


