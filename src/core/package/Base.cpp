//
// Created by liu on 2016/12/5.
//

#include "Base.h"

namespace TCUIEdit { namespace core { namespace package
{
    Base::Base(Package *package)
    {
        m_pkg = package;
    }

    QList<ui::Base *> Base::data()
    {
        return m_data;
    }

    void Base::readComment(QString &str)
    {
        //
    }


    QPair<QString, QStringList> Base::_preprocessLine(QString &str)
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