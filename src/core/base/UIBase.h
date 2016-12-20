//
// Created by liu on 2016/12/3.
//

#ifndef TCUIEDIT_UIBASE_H
#define TCUIEDIT_UIBASE_H

#include "../UICore.h"
#include "../UIException.h"
#include "../../view/UIMainTree.h"
#include <QTreeView>
#include <QStandardItemModel>

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

        const QString _getDisplayName() const;

    public:
        UIBase(UIPackage *package);

        TYPE getType() const;

        const char *getTypeName() const;

        static const char *getTypeName(TYPE type);

        const QString &getName() const;

        const QString getDisplay() const;


        virtual const QString getDisplayName() const = 0;

        void setName(const QString &name);

        UIPackage *getPackage() const;

        virtual void displayDetail(UIMainTree *tree) = 0;

        void initDisplayDetail(UIMainTree *tree);

        static QTreeWidgetItem *formRow(const QString &strName, const QString &strValue = "");
    };

};

#endif //TCUIEDIT_UIBASE_H
