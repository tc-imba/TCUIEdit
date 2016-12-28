//
// Created by liu on 2016/12/8.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
{
    //***************************************************************************
    // [TriggerTypes]
    // Defines all trigger variable types to be used by the Script Editor
    // Key: type name

    // Value 0: first game version in which this type is valid
    // Value 1: flag (0 or 1) indicating if this type can be a global variable
    // Value 2: flag (0 or 1) indicating if this type can be used with comparison operators
    // Value 3: string to display in the editor
    // Value 4: ui type, used only for custom types
    // Value 5: import type, for strings which represent files (optional)
    // Value 6: flag (0 or 1) indicating to treat this type as the ui type in the editor

    class Type : public Base
    {

    protected:
        QString m_version, m_globalFlag, m_compareFlag, m_baseType, m_importType, m_baseFlag;
    public:
        Type(package::Package *package, QPair<QString, QStringList> pair);
        QString version();
        void setVersion(QString version);
        QString globalFlag();
        void setGlobalFlag(QString globalFlag);
        QString compareFlag();
        void setCompareFlag(QString compareFlag);
        QString display();
        void setDisplay(QString display);
        QString baseType();
        void setBaseType(QString baseType);
        QString importType();
        void setImportType(QString importType);
        QString baseFlag();
        void setBaseFlag(QString baseFlag);
    };
}}}


