//
// Created by liu on 2016/12/15.
//

#include "Call.h"
#include "../package/Package.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Call::Call(package::Package *package, QPair<QString, QStringList> pair)
            : Function(package)
    {
        m_type = TRIGGER_CALL;

        this->setName(pair.first, true);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this function is valid
        if (it != pair.second.constEnd())
        {
            m_version = *it++;
        }
        // Value 1: flag (0 or 1) indicating if the call can be used in events
        if (it != pair.second.constEnd())
        {
            m_eventFlag = *it++;
        }
        // Value 2: return type
        if (it != pair.second.constEnd())
        {
            this->setReturnType(*it++);
        }
        // Value 3+: argument types
        while (it != pair.second.constEnd())
        {
            m_arguments.push_back(Argument(*it++));
            m_argumentNum++;
        }
    }

    Call::~Call()
    {

    }

    const QString &Call::eventFlag() const
    {
        return m_eventFlag;
    }

    void Call::setEventFlag(const QString &eventFlag)
    {
        m_eventFlag = eventFlag;
    }

    const QString &Call::returnType() const
    {
        return m_returnType;
    }

    void Call::setReturnType(const QString &returnType)
    {
        m_pkg->removeCategoryUI(this);
        m_returnType = returnType;
        m_pkg->addCategoryUI(this);
    }

    const QString Call::formDisplay() const
    {
        return "(" + m_returnType + ") " + Function::formDisplay();
    }

    QString Call::trigData()
    {
        QString str = this->_formArgument(3, m_name, m_version, m_eventFlag, m_returnType);
        str += Function::trigData();
        return str;
    }


}}}