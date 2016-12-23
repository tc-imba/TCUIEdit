//
// Created by liu on 2016/12/5.
//

#include "Base.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    Base::Base(Package *package)
    {
        this->_pkg = package;
    }

    void Base::readComment(QString &str)
    {
        //
    }


    QPair<QString, QStringList> Base::preprocessLine(QString &str)
    {
        auto pos = str.indexOf('=');
        if (pos == -1)
        {
            throw ExceptionFormatError();
        }
        auto name = str.left(pos);
        auto args = str.mid(pos + 1).split(',');
        return QPair<QString, QStringList>(name, args);
    }

}}}