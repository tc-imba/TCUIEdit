//
// Created by liu on 17-1-9.
//

#include "Function.h"
#include "../ui/Function.h"

namespace TCUIEdit { namespace core { namespace package
{

    Function::Function(Package *package) : Base(package)
    {

    }

    Function::~Function()
    {

    }

    void Function::_addLine(QPair<QString, QStringList> pair)
    {
        if (m_lastUI != NULL)
        {
            auto lastName = m_lastUI->name();
            auto name = pair.first.mid(1, lastName.length());
            if (lastName.compare(name, Qt::CaseInsensitive) == 0)
            {
                pair.first = pair.first.mid(1 + lastName.length());
            }
            else
            {
                auto pos = pair.first.lastIndexOf('_');
                if (pos >= 0)
                {
                    pair.first = pair.first.mid(pos);
                }
            }
            m_lastUI->add(pair);
        }
    }

}}}