//
// Created by sunyi on 2016/12/22.
//

#ifndef TCUIEDIT_UIBASE_CALL_H
#define TCUIEDIT_UIBASE_CALL_H
#include "../UICore.h"
#include "UIBase.h"
#include <QList>
#include <QPair>

namespace TCUIEdit
{
    //***************************************************************************
    //[TriggerCalls]

// Defines function calls which may be used as parameter values
// Key: Function name
// Value 0: first game version in which this function is valid
// Value 1: flag (0 or 1) indicating if the call can be used in events
// Value 2: return type
// Value 3+: argument types
//
// Note: Operators are specially handled by the editor


    class UIBase_Call : public UIBase
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        UIBase_Call(UIPackage *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

        const QString &getCategory() const;

        void displayDetail(UIMainTree *tree);
    };

};

#endif //TCUIEDIT_UIBASE_CALL_H
