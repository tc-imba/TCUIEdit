//
// Created by liu on 2016/12/10.
//

#ifndef TCUIEDIT_UIPACKAGE_WESTRING_H
#define TCUIEDIT_UIPACKAGE_WESTRING_H

#include "../UICore.h"
#include "UIPackage.h"
#include <QMultiHash>
#include <QList>

namespace TCUIEdit
{
    class WEString
    {
    protected:
        QString name, value;
        UIPackage *_pkg;
    public:
        friend class UIPackage_WEString;

        WEString(UIPackage *package)
        { this->_pkg = package; }

        const QString &getName() const
        { return this->name; }

        const QString &getValue() const
        { return this->value; }

        UIPackage *getPackage() const
        { return this->_pkg; }

    };

    class UIPackage_WEString
    {
    protected:
        QList<WEString *> data;
        UIPackage *_pkg;
    public:
        UIPackage_WEString(UIPackage *package);

        void readLine(const QString &line);

        void add(const QString &name = "", const QString &value = "");

        void remove(WEString *weString);

        const QString getValue(const QString &name) const;

        UIPackage *getPackage() const
        { return this->_pkg; }
    };

};


#endif //TCUIEDIT_UIPACKAGE_WESTRING_H
