//
// Created by liu on 2016/12/21.
//

#pragma once

#include "common.h"
#include "Item.h"

namespace TCUIEdit { namespace property_browser
{
    class Row : public QObject
    {
    Q_OBJECT
    protected:

        Browser *m_browser;

        QString m_name, m_value;

        Item *m_nameItem, *m_valueItem;

        void *m_data;

        QString m_alias;

    public:
        friend class Browser;

        Row(Browser *browser, const QString &name, const QString &value = "");

        ~Row();

        QList<QStandardItem *> formRow();

        const QString &name();

        const QString &value();

        void setName(const QString& name);

        void setValue(const QString& value);

        Item *nameItem();

        Item *valueItem();

        void *data();

        void setData(void *data);

        const QString &alias();

        Row *addEditor(const QString &name, const QString &value, const QString &alias);

        Row *addEditor(const QString &name, const QString &value);

        Row *addText(const QString &name, const QString &value, const QString &alias);

        Row *addText(const QString &name, const QString &value);

        void removeChildren();

        virtual void emitEditSignal();

        /*signals:

            void nameClicked(property_browser::Row *);

            void valueClicked(property_browser::Row *);

        protected slots:*/

    };

}}


