//
// Created by liu on 2016/12/3.
//

#ifndef TCUIEDIT_UIBASE_H
#define TCUIEDIT_UIBASE_H

#include "Core.h"

namespace TCUIEdit
{
    class UIBase
    {
    public:
        static const int TYPE_NUM = 10;
        enum TYPE
        {
            TRIGGER_CATEGORY, TRIGGER_TYPE, TRIGGER_TYPE_DEFAULT, TRIGGER_PARAM,
            TRIGGER_EVENT, TRIGGER_CONDITION, TRIGGER_ACTION, TRIGGER_CALL,
            DEFAULT_TRIGGER_CATEGORY, DEFAULT_TRIGGER, UNKNOWN = -1
        };
        static const char *TYPE_NAME[TYPE_NUM];
    protected:
        TYPE type = UNKNOWN;
        std::string name;

    public:
        const char *getTypeName() const;

        std::string getName() const;
    };

    class UIBase_Category : public UIBase
    {

    };

};

#endif //TCUIEDIT_UIBASE_H
