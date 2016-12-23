//
// Created by liu on 2016/12/16.
//

#include "Action.h"
#include "../ui/Action.h"
#include "Project.h"
#include "Package.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    Action::Action(Package *package) : Base(package)
    {

    }

    void Action::readLine(QString &str)
    {
        auto pair = this->preprocessLine(str);
        if (pair.first[0] != '_')
        {
            this->lastUI = new UI::Action(this->_pkg, pair);
            auto item = static_cast<UI::Base *>(this->lastUI);
            this->data.push_back(item);
        }
        else if (lastUI != NULL)
        {
            auto lastName = this->lastUI->getName();
            auto name = pair.first.mid(1, lastName.length());
            if (lastName == name)
            {
                pair.first = pair.first.mid(1 + lastName.length());
                this->lastUI->add(pair);
            }
        }
    }


}}}
