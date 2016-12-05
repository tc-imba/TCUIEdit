//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIPROJECT_H
#define TCUIEDIT_UIPROJECT_H

#include "UICore.h"
#include "UIMap.h"

namespace TCUIEdit
{
    class UIProject
    {
        // friend class UIBase;

    protected:
        UIMap uiMap;

    public:
        UIMap& getUIMap();
    };


};

#endif //TCUIEDIT_UIPROJECT_H
