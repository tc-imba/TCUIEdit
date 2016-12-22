//
// Created by sunyi on 2016/12/21.
//

#ifndef TCUIEDIT_UIBASE_CONDITION_H
#define TCUIEDIT_UIBASE_CONDITION_H

#include "../UICore.h"
#include "Base.h"
#include <QList>
#include <QPair>

namespace TCUIEdit
{
    //***************************************************************************
    // [TriggerConditions]
    // Defines boolean condition functions
    // Key: condition function name

    // Value 0: first game version in which this function is valid
    // Value 1+: argument types
    // Note that the first argument is always a `trigger`, and is excluded here

    class UIBase_Condition : public UIBase
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        UIBase_Condition(UIPackage *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

        const QString &getCategory() const;

    };

};

#endif //TCUIEDIT_UIBASE_CONDITION_H
