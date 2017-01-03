//
// Created by liu on 2016/12/16.
//

#include "Call.h"
#include "../ui/Call.h"
#include "Project.h"
#include "Package.h"

namespace TCUIEdit { namespace core { namespace package
{
    Call::Call(Package *package) : Base(package)
    {
        m_type = ui::Base::TRIGGER_CALL;
    }

    void Call::readLine(QString &str)
    {
        auto pair = this->_preprocessLine(str);
        if (pair.first[0] != '_')
        {
            m_lastUI = new ui::Call(m_pkg, pair);
            auto item = static_cast<ui::Base *>(m_lastUI);
            m_data.push_back(item);
        }
        else if (m_lastUI != NULL)
        {
            auto lastName = m_lastUI->name();
            auto name = pair.first.mid(1, lastName.length());
            if (lastName == name)
            {
                pair.first = pair.first.mid(1 + lastName.length());
                m_lastUI->add(pair);
            }
        }
    }


}}}
