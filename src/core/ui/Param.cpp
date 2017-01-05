//
// Created by liu on 2016/12/13.
//

#include "Param.h"
#include "Type.h"
#include "package/Package.h"
#include "Project.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Param::Param(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_PARAM;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this parameter is valid
        if (it != pair.second.constEnd())
        {
            this->m_version = *it++;
        }
        // Value 1: variable type
        if (it != pair.second.constEnd())
        {
            this->m_variableType = *it++;
        }
        // Value 2: code text (used in script)
        if (it != pair.second.constEnd())
        {
            this->m_script = *it++;
        }
        // Value 3: display text
        if (it != pair.second.constEnd())
        {
            m_display = *it++;
        }

    }

    Param::~Param()
    {

    }

    const QString &Param::version() const
    {
        return m_version;
    }

    void Param::setVersion(const QString &version)
    {
        m_version = version;
    }

    Type *Param::getOriginType() const
    {
        return (Type *) (m_pkg->project()->matchUI(this->m_variableType, TRIGGER_TYPE));
    }

    const QString Param::formDisplay() const
    {
        auto type = this->getOriginType();
        if (type)
        {
            QString str = type->formDisplay();
            if (str != "")
            {
                return m_name + " ( " + str + " )";
            }
        }
        return m_name;
    }

    const QString &Param::variableType() const
    {
        return m_variableType;
    }

    void Param::setVariableType(const QString &variableType)
    {
        m_variableType = variableType;
    }

    const QString &Param::script() const
    {
        return m_script;
    }

    void Param::setScript(const QString &script)
    {
        m_script = script;
    }

    QString Param::trigData()
    {
        QString str = this->_formArgument(4, m_name, m_version, m_variableType, m_script, m_display);
        return str;
    }


}}}