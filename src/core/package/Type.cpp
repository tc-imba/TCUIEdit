//
// Created by liu on 2016/12/8.
//

#include "Type.h"
#include "../ui/Type.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    Type::Type(Package *package) : Base(package)
    {

    }

    void Type::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        auto item = static_cast<UI::Base *>(new UI::Type(this->_pkg, pair));
        this->data.push_back(item);
    }


}}}