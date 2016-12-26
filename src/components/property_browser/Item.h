//
// Created by liu on 2016/12/21.
//

#pragma once

#include "common.h"

namespace TCUIEdit { namespace property_browser
{
    class Item
    {
    protected:

        Browser *m_browser;

        QString m_name, m_value;

        QStandardItem *m_nameItem, *m_valueItem;

        void *m_data;

    public:

        Item(Browser *browser, const QString &name, const QString &value = "");


        QList<QStandardItem *> formRow();

        QStandardItem *nameItem();

        QStandardItem *valueItem();

        void *data();

        void setData(void* data);

        Item *addEditor(const QString &name, const QString &value, const QString &alias);

        Item *addEditor(const QString &name, const QString &value);

        Item *addText(const QString &name, const QString &value, const QString &alias);

        Item *addText(const QString &name, const QString &value);


    };

}}


