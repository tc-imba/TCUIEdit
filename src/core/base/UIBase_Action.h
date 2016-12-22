//
// Created by sunyi on 2016/12/22.
//

#ifndef TCUIEDIT_UIBASE_ACTION_H
#define TCUIEDIT_UIBASE_ACTION_H
#include "../UICore.h"
#include "UIBase.h"
#include <QList>
#include <QPair>

namespace TCUIEdit
{
    //***************************************************************************
    //[TriggerActions]
// Defines action functions
// Key: action function name
// Value 0: first game version in which this function is valid
// Value 1+: argument types

    // Note that the first argument is always a `trigger`, and is excluded here

    class UIBase_Action : public UIBase
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        UIBase_Action(UIPackage *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

        const QString &getCategory() const;

        void displayDetail(UIMainTree *tree);
    };

};

#endif //TCUIEDIT_UIBASE_ACTION_H
