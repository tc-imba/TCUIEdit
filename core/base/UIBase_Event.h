//
// Created by liu on 2016/12/15.
//

#ifndef TCUIEDIT_UIBASE_EVENT_H
#define TCUIEDIT_UIBASE_EVENT_H

#include "../UICore.h"
#include "UIBase.h"
#include <QList>
#include <QPair>

namespace TCUIEdit
{
    //***************************************************************************
    // [TriggerEvents]
    // Defines events available in the editor
    // Key: script event function
    // Value 0: first game version in which this function is valid
    // Value 1+: argument types
    // Note that the first argument is always a `trigger`, and is excluded here

    class UIBase_Event : public UIBase
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        UIBase_Event(UIPackage *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString getDisplayName() const;
    };

};


#endif //TCUIEDIT_UIBASE_EVENT_H
