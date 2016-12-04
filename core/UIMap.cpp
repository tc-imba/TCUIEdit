//
// Created by liu on 2016/12/4.
//

#include "UIMap.h"

namespace TCUIEdit
{
    UIMap::UIMap()
    {

    }

    void UIMap::addUI(UIBase *UI)
    {
        if (UI == NULL)
        {
            throw UIExceptionNotFound();
        }
        std::string name = UI->getName();
    }

};