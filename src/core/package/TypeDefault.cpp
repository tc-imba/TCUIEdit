//
// Created by liu on 2016/12/11.
//

#include "TypeDefault.h"
#include "../ui/TypeDefault.h"

namespace TCUIEdit { namespace core { namespace package
{
    TypeDefault::TypeDefault(Package *package) : Base(package)
    {

    }

    void TypeDefault::readLine(QString &str)
    {
        auto pair = this->_preprocessLine(str);
        auto item = static_cast<ui::Base *>(new ui::TypeDefault(m_pkg, pair));
        m_data.push_back(item);
    }


}}}
