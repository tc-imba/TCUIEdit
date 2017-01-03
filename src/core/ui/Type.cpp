//
// Created by liu on 2016/12/8.
//

#include "Type.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Type::Type(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_TYPE;

        this->setName(pair.first);

        auto it = pair.second.constBegin();

        // Value 0: first game version in which this type is valid
        if (it != pair.second.constEnd())
        {
            m_version = *it++;
        }
        // Value 1: flag (0 or 1) indicating if this type can be a global variable
        if (it != pair.second.constEnd())
        {
            m_globalFlag = *it++;
        }
        // Value 2: flag (0 or 1) indicating if this type can be used with comparison operators
        if (it != pair.second.constEnd())
        {
            m_compareFlag = *it++;
        }
        // Value 3: string to display in the editor
        if (it != pair.second.constEnd())
        {
            m_display = *it++;
        }
        // Value 4: ui type, used only for custom types
        if (it != pair.second.constEnd())
        {
            m_baseType = *it++;
        }
        // Value 5: import type, for strings which represent files (optional)
        if (it != pair.second.constEnd())
        {
            m_importType = *it++;
        }
        // Value 6: flag (0 or 1) indicating to treat this type as the ui type in the editor
        if (it != pair.second.constEnd())
        {
            m_baseFlag = *it++;
        }
    }

    Type::~Type()
    {

    }

    const QString &Type::version() const
    {
        return m_version;
    }

    void Type::setVersion(const QString &version)
    {
        m_version = version;
    }

    const QString &Type::globalFlag() const
    {
        return m_globalFlag;
    }

    void Type::setGlobalFlag(const QString &globalFlag)
    {
        m_globalFlag = globalFlag;
    }

    const QString &Type::compareFlag() const
    {
        return m_compareFlag;
    }

    void Type::setCompareFlag(const QString &compareFlag)
    {
        m_compareFlag = compareFlag;
    }

    const QString &Type::baseType() const
    {
        return m_baseType;
    }

    void Type::setBaseType(const QString &baseType)
    {
        m_baseType = baseType;
    }

    const QString &Type::importType() const
    {
        return m_importType;
    }

    void Type::setImportType(const QString &importType)
    {
        m_importType = importType;
    }

    const QString &Type::baseFlag() const
    {
        return m_baseFlag;
    }

    void Type::setBaseFlag(const QString &baseFlag)
    {
        m_baseFlag = baseFlag;
    }

}}}