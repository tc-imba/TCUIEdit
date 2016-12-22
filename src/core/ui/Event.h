//
// Created by liu on 2016/12/15.
//

#ifndef TCUIEDIT_UIBASE_EVENT_H
#define TCUIEDIT_UIBASE_EVENT_H

#include "../UICore.h"
#include "Base.h"
#include <QList>
#include <QPair>

namespace TCUIEdit{namespace UI
{
    //***************************************************************************
    // [TriggerEvents]
    // Defines events available in the editor
    // Key: script event function
    // Value 0: first game version in which this function is valid
    // Value 1+: argument types
    // Note that the first argument is always a `trigger`, and is excluded here

    class Event : public Base
    {
    protected:
        QString version, category;
        QList<QPair<QString, QString> > arguments;
        bool defaultsFlag, categoryFlag;
    public:
        Event(UIPackage *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString getDisplayName() const;

        const QString &getCategory() const;

    };

}};


#endif //TCUIEDIT_UIBASE_EVENT_H
