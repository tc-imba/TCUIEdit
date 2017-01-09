//
// Created by liu on 2016/12/15.
//

#include "Action.h"

namespace TCUIEdit { namespace core { namespace ui
{
    Action::Action(package::Package *package, QPair<QString, QStringList> pair)
            : Function(package)
    {
        m_type = TRIGGER_ACTION;

        this->setName(pair.first, true);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this function is valid
        if (it != pair.second.constEnd())
        {
            m_version = *it++;
        }
        // Value 1+: argument types
        while (it != pair.second.constEnd())
        {
            m_arguments.push_back(Argument(*it++));
            m_argumentNum++;
        }
    }

    Action::~Action()
    {

    }

    QString Action::trigData()
    {
        QString str = this->_formArgument(1, m_name, m_version);
        str += Function::trigData();
        return str;
    }

}}}