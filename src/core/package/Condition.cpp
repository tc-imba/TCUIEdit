//
// Created by liu on 2016/12/16.
//

#include "Condition.h"
#include "../ui/Condition.h"

namespace TCUIEdit { namespace core { namespace package
{
    Condition::Condition(Package *package) : Function(package)
    {
        m_type = ui::Base::TRIGGER_CONDITION;
    }

    void Condition::readLine(QString &str)
    {
        auto pair = this->_preprocessLine(str);
        if (pair.first[0] != '_')
        {
            m_lastUI = new ui::Condition(m_pkg, pair);
            auto item = static_cast<ui::Base *>(m_lastUI);
            m_data.push_back(item);
        }
        else
        {
            this->_addLine(pair);
        }
    }


}}}
