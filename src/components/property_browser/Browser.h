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
        Model *model;

        QMap<QString, Category *> m_category;

    public:
        Browser(QWidget *parent = Q_NULLPTR);

        ~Browser();

        void init();

        Category* addCategory(const QString &text);

        Item* addItem(const QString &name);
    };

}}


