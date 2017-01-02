//
// Created by liu on 17-1-2.
//

#pragma once

#include "core.h"

namespace TCUIEdit { namespace core
{
    class Error
    {
    public:
        static const int TYPE_NUM = 4;
        enum TYPE
        {
            TYPE_NONE, TYPE_ERROR, TYPE_WARNING, TYPE_TIP
        };
        static const char *TYPE_NAME[TYPE_NUM];
        static const Qt::GlobalColor TYPE_COLOR[TYPE_NUM];

        struct Item
        {
            QString name, value;
            ui::Base *ui;
        };

    protected:
        QString m_name;
        TYPE m_type;
        QList<Item> m_list;
    public:
        Error(TYPE type = TYPE_NONE);

        Error(const QString &name, TYPE type = TYPE_NONE);

        const QString &name() const;

        Error::TYPE type() const;

        const QList<Item> &list() const;

        void addItem(const QString &name, const QString &value, ui::Base *ui = NULL);

        QColor color() const;

        const char *typeName() const;

    };
}}
