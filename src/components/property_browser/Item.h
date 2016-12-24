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

        Browser* m_browser;
        QString m_name, m_value;
        QStandardItem *m_nameItem, *m_valueItem;

    public:

        Item(const QString &name, const QString &value = "");

        QList<QStandardItem *> formRow();

        QStandardItem *nameItem();

        QStandardItem *valueItem();


        Item* addEditor();

    };

}}


