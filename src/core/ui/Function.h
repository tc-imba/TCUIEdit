//
// Created by liu on 16-12-25.
//

#pragma once

#include "Base.h"

namespace TCUIEdit { namespace core { namespace ui
{

    class Function : public Base
    {

    public:
        class Argument
        {
        public:
            friend class Function;

            static const int DATA_TYPE_NUM = 5;
            enum DATA_TYPE
            {
                TYPE, DEFAULT, AI_DEFAULT, MIN, MAX
            };

            Argument(const QString &type)
            {
                m_data[TYPE] = type;
            }

        protected:
            QString m_data[DATA_TYPE_NUM];
        };

        static const int FLAG_NUM = 6;

        enum FLAG
        {
            FLAG_DEFAULTS, FLAG_LIMITS, FLAG_CATEGORY, FLAG_SCRIPT, FLAG_AI, FLAG_AI_DEFAULTS
        };

        static const char *FLAG_NAME[FLAG_NUM];

    protected:
        QString m_version, m_category, m_useWithAI, m_script;
        QList<Argument> m_arguments;
        bool m_flag[FLAG_NUM];
        int m_lastFlagNum;

        void _addArgumentData(const QStringList &list, Argument::DATA_TYPE dataType, bool limitsFlag = false);

        typedef void (Function::*FUNC)(const QPair<QString, QStringList> &);

        static const FUNC _add[FLAG_NUM];

        void _addDefaults(const QPair<QString, QStringList> &pair);

        void _addLimits(const QPair<QString, QStringList> &pair);

        void _addCategory(const QPair<QString, QStringList> &pair);

        void _addScript(const QPair<QString, QStringList> &pair);

        void _addAI(const QPair<QString, QStringList> &pair);

        void _addAIDefaults(const QPair<QString, QStringList> &pair);

    public:
        Function(package::Package *package);

        void add(QPair<QString, QStringList> pair);

        const QString &category() const;

        void setCategory(const QString& category);

        const QString& version() const ;

        void setVersion(const QString& version);
    };

}}}


