//
// Created by liu on 2016/12/5.
//

#include "Base.h"
#include "Resourse.h"

namespace TCUIEdit { namespace core { namespace package
{
    Base::Base(Package *package)
    {
        m_pkg = package;
    }

    Base::~Base()
    {

    }

    ui::Base::TYPE Base::type()
    {
        return m_type;
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

    const QString& Base::typeDefineText() const
    {
        return Resourse::typeDefineText(m_type);
    }

}}}