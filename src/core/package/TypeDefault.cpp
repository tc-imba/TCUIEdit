//
// Created by liu on 2016/12/11.
//

#include "TypeDefault.h"
#include "../ui/TypeDefault.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    TypeDefault::TypeDefault(Package *package) : Base(package)
    {

    }

    void TypeDefault::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        auto item = static_cast<UI::Base *>(new UI::TypeDefault(this->_pkg, pair));
        this->data.push_back(item);
    }


}}}
