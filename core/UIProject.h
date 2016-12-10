//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIPROJECT_H
#define TCUIEDIT_UIPROJECT_H

#include "UICore.h"
#include "UIMap.h"
#include <QMultiHash>

namespace TCUIEdit
{
    class UIProject
    {
        // friend class UIBase;

    protected:
        UIMap uiMap;
        QMultiHash<QString, WEString *> weStringMap;
    public:
        UIMap &getUIMap()
        { return this->uiMap; }

        QMultiHash<QString, WEString *> &getWEStringMap()
        { return this->weStringMap; }

    };


};

#endif //TCUIEDIT_UIPROJECT_H
