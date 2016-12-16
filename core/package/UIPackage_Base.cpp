//
// Created by liu on 2016/12/5.
//

#include "UIPackage_Base.h"

namespace TCUIEdit
{
    UIPackage_Base::UIPackage_Base(UIPackage *package)
    {
        this->_pkg = package;
    }

    void UIPackage_Base::readComment(QString &str)
    {
        //
    }


    QPair<QString, QStringList> UIPackage_Base::preprocessLine(QString &str)
    {
        auto pos = str.indexOf('=');
        if (pos == -1)
        {
            throw UIExceptionFormatError();
        }
        auto name = str.left(pos);
        auto args = str.mid(pos + 1).split(',');
        return QPair<QString, QStringList>(name, args);
    }

};