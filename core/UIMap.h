//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIMAP_H
#define TCUIEDIT_UIMAP_H

#include "Core.h"
#include "UIBase.h"
#include "UIException.h"

namespace TCUIEdit
{
    class UIMap
    {
    protected:
        std::unordered_map<std::string, std::list<UIBase *>> map;
    public:
        UIMap();

        void addUI(UIBase *UI);
    };
};


#endif //TCUIEDIT_UIMAP_H
