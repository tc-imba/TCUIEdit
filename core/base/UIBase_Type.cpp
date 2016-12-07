//
// Created by liu on 2016/12/8.
//

#include "UIBase_Type.h"

namespace TCUIEdit
{

    UIBase_Type::UIBase_Type(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->setName(pair.first);

        auto it = pair.second.constBegin();


    }

    const QString UIBase_Type::getDisplayName() const
    {
        return this->name;
    }

};