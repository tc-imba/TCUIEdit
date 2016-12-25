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

    void Function::_addArgumentData(const QStringList &list, Argument::DATA_TYPE dataType, bool limitsFlag)
    {
        auto itArg = m_arguments.begin();
        auto itList = list.constBegin();
        bool endFlag = false;
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

}}}