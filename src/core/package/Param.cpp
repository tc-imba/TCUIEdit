//
// Created by liu on 2016/12/14.
//

#include "Param.h"
#include "../ui/Param.h"

namespace TCUIEdit { namespace core { namespace package
{
    Param::Param(Package *package) : Base(package)
    {
        m_type = ui::Base::TRIGGER_PARAM;
    }

    void Param::readLine(QString &str)
    {
        auto pair = this->_preprocessLine(str);
        auto item = static_cast<ui::Base *>(new ui::Param(m_pkg, pair));
        m_data.push_back(item);
    }


}}}