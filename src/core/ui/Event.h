//
// Created by liu on 2016/12/15.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
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
    public:
        class Argument
        {
        public:
            static const int DATA_NUM = 5;

            enum DATA
            {
                TYPE, DEFAULT, AI_DEFAULT, MIN, MAX
            };

            QString m_data[DATA_NUM];

            Argument(const QString &type)
            {
                m_data[TYPE] = type;
            }
        };

        static const int FLAG_NUM = 2;

        enum FLAG
        {
            FLAG_DEFAULT, FLAG_CATEGORY
        };

        static const char *FLAG_NAME[FLAG_NUM];

    protected:
        QString m_version, m_category, m_useWithAI, m_script;
        QList<Argument> m_arguments;
        bool m_flag[2];

        

    public:
        Event(package::Package *package, QPair<QString, QStringList> pair);

        void add(QPair<QString, QStringList> pair);

        const QString formDisplay() const;

        const QString &getCategory() const;

    };

}}}



