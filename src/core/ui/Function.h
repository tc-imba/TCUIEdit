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

        enum FUNCTION_TYPE
        {
            FUNCTION_TYPE_EVENT, FUNCTION_TYPE_CONDITION, FUNCTION_TYPE_ACTION, FUNCTION_TYPE_CALL
        };

        static Base::TYPE FUNCTION_TO_BASE(FUNCTION_TYPE type);

        static FUNCTION_TYPE BASE_TO_FUNCTION(Base::TYPE type);

    protected:
        QString m_version, m_category, m_useWithAI, m_script;
        QList<Argument> m_arguments;
        int m_argumentNum;
        bool m_flag[FLAG_NUM];
        int m_lastFlagNum;

        void _addArgumentData(const QStringList &list, Argument::DATA_TYPE dataType);

        typedef void (Function::*FUNC)(const QPair<QString, QStringList> &);

        static const FUNC _add[FLAG_NUM];

        inline QString _arg_(const QString &arg)
        {
            return arg.length() == 0 ? "_" : arg;
        }

        void _addDefaults(const QPair<QString, QStringList> &pair);

        void _addLimits(const QPair<QString, QStringList> &pair);

        void _addCategory(const QPair<QString, QStringList> &pair);

        void _addScript(const QPair<QString, QStringList> &pair);

        void _addAI(const QPair<QString, QStringList> &pair);

        void _addAIDefaults(const QPair<QString, QStringList> &pair);

    public:
        Function(package::Package *package);

        virtual ~Function() = 0;

        FUNCTION_TYPE functionType() const;

        void add(QPair<QString, QStringList> pair);

        void setName(const QString &name, bool firstFlag = false);

        const QString &category() const;

        void setCategory(const QString &category);

        const QString &version() const;

        void setVersion(const QString &version);

        const QString formDisplay() const;

        virtual QString trigData();
    };

}}}


