//
// Created by liu on 2016/12/11.
//

#ifndef TCUIEDIT_UIBASE_TYPEDEFAULT_H
#define TCUIEDIT_UIBASE_TYPEDEFAULT_H

#include "../UICore.h"
#include "UIBase.h"

namespace TCUIEdit
{
    //***************************************************************************
    // [TriggerTypeDefaults]
    // Defines an optional default value for a trigger type used as a global variable
    // Key: variable type
    // Value 0: script text
    // Value 1: display text (if not present, script text will be used)
    //
    // If a type does not have an entry here, it will be set to null if it is a handle

    class UIBase_TypeDefault : public UIBase
    {
    protected:
        QString script;
    public:
        UIBase_TypeDefault(UIPackage *package, QPair<QString, QStringList> pair);

        UIBase_Type *getOriginType() const;

        const QString getDisplayName() const;

        void displayDetail(UIMainTree *tree);

    };

};
#endif //TCUIEDIT_UIBASE_TYPEDEFAULT_H
