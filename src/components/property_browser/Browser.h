//
// Created by liu on 2016/12/21.
//

#pragma once

#include "common.h"
#include "Model.h"
#include "Category.h"

namespace TCUIEdit { namespace property_browser
{

    class Browser : public QTreeView
    {
    Q_OBJECT
    protected:
        Model *m_model;

        QMap<QString, Item *> m_propertyMap;

    public:
        Browser(QWidget *parent = Q_NULLPTR);

        ~Browser();

        void init();

        bool addAlias(Item* item, const QString& alias);

        Category* addCategory(const QString &text, const QString &alias = "");

    };

}}


