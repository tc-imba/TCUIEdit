//
// Created by liu on 16-12-25.
//

#include "Function.h"

namespace TCUIEdit { namespace core { namespace ui
{

    const char *Function::FLAG_NAME[Function::FLAG_NUM] =
            {"_Defaults", "_Limits", "_Category", "_ScriptName", "_UseWithAI", "_AIDefaults"};

    const Function::FUNC Function::_add[Function::FLAG_NUM] =
            {
                    &Function::_addDefaults,
                    &Function::_addLimits,
                    &Function::_addCategory,
                    &Function::_addScript,
                    &Function::_addAI,
                    &Function::_addAIDefaults
            };

    Function::Function(package::Package *package)
            : Base(package)
    {
        m_lastFlagNum = 0;
        for (int i = 0; i < FLAG_NUM; i++)m_flag[i] = false;
    }

    Function::~Function()
    {

    }

    void Function::_addArgumentData(const QStringList &list, Argument::DATA_TYPE dataType, bool limitsFlag)
    {
        auto itArg = m_arguments.begin();
        auto itList = list.constBegin();
        bool endFlag = false;
        if (itArg == m_arguments.end() && list.size() == 1)
        {
            if (list.first() == "")return;
        }
        while (itList != list.constEnd())
        {
            if (itArg != m_arguments.end() & !endFlag)
            {
                (*itArg).m_data[dataType] = (*itList++);
                if (itList != list.constEnd() && limitsFlag)(*itArg).m_data[Argument::MAX] = (*itList++);
                ++itArg;
            }
            else
            {
#ifdef QT_DEBUG
                qDebug() << typeName() << m_name << list;
#endif
                endFlag = true;
                Argument arg("");
                arg.m_data[dataType] = (*itList++);
                if (itList != list.constEnd() && limitsFlag)arg.m_data[Argument::MAX] = (*itList++);
                m_arguments.push_back(arg);
            }
        }
    }

    void Function::_addDefaults(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_DEFAULTS] = true;
        this->_addArgumentData(pair.second, Argument::DEFAULT);
    }

    void Function::_addLimits(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_LIMITS] = true;
        this->_addArgumentData(pair.second, Argument::MIN, true);
    }

    void Function::_addCategory(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_CATEGORY] = true;
        if (pair.second.size() > 0)m_category = pair.second.first();
    }

    void Function::_addScript(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_SCRIPT] = true;
        if (pair.second.size() > 0)m_script = pair.second.first();
    }

    void Function::_addAI(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_AI] = true;
        if (pair.second.size() > 0)m_useWithAI = pair.second.first();
    }

    void Function::_addAIDefaults(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_AI_DEFAULTS] = true;
        this->_addArgumentData(pair.second, Argument::AI_DEFAULT);
    }

    void Function::add(QPair<QString, QStringList> pair)
    {
        bool successFlag = false;
        for (int i = 0; i < FLAG_NUM; i++)
        {
            int next = (m_lastFlagNum + i) % FLAG_NUM;
            if (pair.first == FLAG_NAME[next])
            {
                if (!m_flag[next])
                {
                    (this->*_add[next])(pair);
                    m_lastFlagNum = next + 1;
                    successFlag = true;
                }
                break;
            }
        }
#ifdef QT_DEBUG
        if (!successFlag)qDebug() << typeName() << m_name << pair.first << pair.second;
#endif
    }

    const QString &Function::category() const
    {
        return m_category;
    }

    void Function::setCategory(const QString &category)
    {
        m_category = category;
    }

    const QString &Function::version() const
    {
        return this->m_version;
    }

    void Function::setVersion(const QString &version)
    {
        m_version = version;
    }

    QString Function::trigData()
    {
        QString str = "";
        if (m_arguments.length() == 0)
        {
            this->_addArgument(str, "nothing");
        }
        else
        {
            for (auto &it:m_arguments)
            {
                this->_addArgument(str, it.m_data[Argument::TYPE]);
            }
        }
        // Defaults
        str += "\n" + this->_formArgument(0, "_" + m_name + FLAG_NAME[FLAG_DEFAULTS]);
        bool firstFlag = true;
        for (auto &it:m_arguments)
        {
            this->_addArgument(str, it.m_data[Argument::DEFAULT], firstFlag);
            firstFlag = false;
        }
        // Limits
        if (m_flag[FLAG_LIMITS])
        {
            firstFlag = true;
            str += "\n" + this->_formArgument(0, "_" + m_name + FLAG_NAME[FLAG_LIMITS]);
            for (auto &it:m_arguments)
            {
                this->_addArgument(str, it.m_data[Argument::MIN], firstFlag);
                this->_addArgument(str, it.m_data[Argument::MAX]);
                firstFlag = false;
            }
        }
        // Category
        str += "\n" + this->_formArgument(1, "_" + m_name + FLAG_NAME[FLAG_CATEGORY], m_category);
        // ScriptName
        if (m_flag[FLAG_SCRIPT])
        {
            str += "\n" + this->_formArgument(1, "_" + m_name + FLAG_NAME[FLAG_SCRIPT], m_script);
        }
        // UseWithAI
        if (m_useWithAI == "1")
        {
            str += "\n" + this->_formArgument(1, "_" + m_name + FLAG_NAME[FLAG_AI], m_useWithAI);
            // AIDefaults
            if (m_flag[FLAG_AI_DEFAULTS])
            {
                firstFlag = true;
                str += "\n" + this->_formArgument(0, "_" + m_name + FLAG_NAME[FLAG_AI_DEFAULTS]);
                for (auto &it:m_arguments)
                {
                    this->_addArgument(str, it.m_data[Argument::AI_DEFAULT], firstFlag);
                    firstFlag = false;
                }
            }
        }
        str += "\n";
        return str;
    }

}}}