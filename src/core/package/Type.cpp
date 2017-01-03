//
// Created by liu on 2016/12/8.
//

#include "Type.h"
#include "../ui/Type.h"

namespace TCUIEdit { namespace core { namespace package
{
    Type::Type(Package *package) : Base(package)
    {
        m_type = ui::Base::TRIGGER_TYPE;
    }

    void Type::readLine(QString &str)
    {
        auto pair = this->_preprocessLine(str);
        auto item = static_cast<ui::Base *>(new ui::Type(m_pkg, pair));
        m_data.push_back(item);
    }


}}}