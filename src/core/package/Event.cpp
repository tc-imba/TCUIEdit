//
// Created by liu on 2016/12/16.
//

#include "Event.h"
#include "../ui/Event.h"
#include "Project.h"
#include "Package.h"

namespace TCUIEdit { namespace core { namespace package
{
    Event::Event(Package *package) : Base(package)
    {
        m_type = ui::Base::TRIGGER_EVENT;
    }

    void Event::readLine(QString &str)
    {
        auto pair = this->_preprocessLine(str);
        if (pair.first[0] != '_')
        {
            m_lastUI = new ui::Event(m_pkg, pair);
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
