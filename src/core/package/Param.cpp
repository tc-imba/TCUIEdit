//
// Created by liu on 2016/12/14.
//

#include "Param.h"
#include "../ui/Param.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    Param::Param(Package *package) : Base(package)
    {

    }

    void Param::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        auto item = static_cast<UI::Base *>(new UI::Param(this->_pkg, pair));
        this->data.push_back(item);
    }


}}}