//
// Created by liu on 2016/12/16.
//

#include "Event.h"
#include "../ui/Event.h"

namespace TCUIEdit { namespace core { namespace package
{
    Event::Event(Package *package) : Function(package)
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
        else
        {
            this->_addLine(pair);
        }
    }


}}}
