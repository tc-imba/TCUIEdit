//
// Created by liu on 2016/12/3.
//

#ifndef TCUIEDIT_UIBASE_H
#define TCUIEDIT_UIBASE_H

#include "../UICore.h"
#include "../UIException.h"

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
        QString name, display;
        //UIProject *_proj;
        UIPackage *_pkg;
    public:
        UIBase(UIPackage *package);

        const char *getTypeName() const;

        static const char *getTypeName(TYPE type);

        const QString &getName() const;

        virtual const QString getDisplayName() const = 0;

        void setName(QString &name);

        void setName(const QString &name);
    };

};

#endif //TCUIEDIT_UIBASE_H
