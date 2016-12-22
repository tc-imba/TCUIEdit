//
// Created by liu on 2016/12/13.
//

#ifndef TCUIEDIT_UIBASE_PARAM_H
#define TCUIEDIT_UIBASE_PARAM_H

#include "../UICore.h"
#include "Base.h"

namespace TCUIEdit{namespace UI
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
        Param(UIPackage *package, QPair<QString, QStringList> pair);

        UIBase_Type *getOriginType() const;

        const QString getDisplayName() const;


    };

}};

#endif //TCUIEDIT_UIBASE_PARAM_H
