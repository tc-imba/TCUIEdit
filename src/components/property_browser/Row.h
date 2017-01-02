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
    public:
        enum TYPE
        {
            TYPE_CATEGORY, TYPE_TEXT, TYPE_EDITOR, TYPE_LIST
        };

    protected:
        TYPE m_type;

        Browser *m_browser;

        QString m_name, m_value;

        Item *m_nameItem, *m_valueItem;

        void *m_data;

        QString m_alias;

        Row *addRow(TYPE type, const QString &name, const QString &value, const QString &alias);

    public:
        friend class Browser;

        Row(Browser *browser, const QString &name, const QString &value = "");

        ~Row();

        QList<QStandardItem *> formRow();

        Row::TYPE type();

        const QString &name();

        const QString &value();

        void setName(const QString &name);

        void setValue(const QString &value);

        Item *nameItem();

        Item *valueItem();

        virtual QVariant data(int role = Qt::UserRole + 1) const;

        virtual void setData(const QVariant &value, int role = Qt::UserRole + 1);


        const QString &alias();

        Row *addEditor(const QString &name, const QString &value, const QString &alias);

        Row *addEditor(const QString &name, const QString &value);

        Row *addText(const QString &name, const QString &value, const QString &alias);

        Row *addText(const QString &name, const QString &value);

        Row *addList(const QString &name, const QString &value, const QStringList &list, const QString &alias);

        Row *addList(const QString &name, const QString &value, const QStringList &list);

        void removeChildren();

        virtual void emitEditSignal();

        /*signals:

            void nameClicked(property_browser::Row *);

            void valueClicked(property_browser::Row *);

        protected slots:*/

    };

}}


