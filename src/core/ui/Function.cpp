//
// Created by liu on 16-12-25.
//

#include "Function.h"
#include "../package/Package.h"
#include "../Project.h"

namespace TCUIEdit { namespace core { namespace ui
{

    const char *Function::FLAG_NAME[Function::FLAG_NUM] =
            {"_Defaults", "_Limits", "_Category", "_ScriptName", "_UseWithAI", "_AIDefaults"};

    Base::TYPE Function::FUNCTION_TO_BASE(FUNCTION_TYPE type)
    {
        if (type < 0 || type > 4)return Base::UNKNOWN;
        return Base::TYPE(type + Base::TRIGGER_EVENT);
    }

    Function::FUNCTION_TYPE Function::BASE_TO_FUNCTION(Base::TYPE type)
    {
        if (!isFunction(type))return FUNCTION_TYPE_EVENT;
        return FUNCTION_TYPE(type - Base::TRIGGER_EVENT);
    }

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
        m_argumentNum = 0;
    }

    Function::~Function()
    {

    }

    Function::FUNCTION_TYPE Function::functionType() const
    {
        return this->BASE_TO_FUNCTION(m_type);
    }

    void Function::_addArgumentData(const QStringList &list, Argument::DATA_TYPE dataType)
    {
        bool limitsFlag = dataType == Argument::MIN;
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
                if ((*itArg).m_data[dataType] == "_")(*itArg).m_data[dataType] = "";
                if (itList != list.constEnd() && limitsFlag)
                {
                    (*itArg).m_data[Argument::MAX] = (*itList++);
                    if ((*itArg).m_data[Argument::MAX] == "_")(*itArg).m_data[dataType] = "";
                }
                ++itArg;
            }
            else
            {
                auto _itList = itList;
                while (_itList != list.constEnd())
                {
                    if ((*_itList).length() > 0 && (*_itList) != "_" && (*_itList) != "nothing")break;
                    ++_itList;
                }
                if (_itList == list.constEnd())return;
#ifdef QT_DEBUG
                qDebug() << typeName() << m_name << list;
#endif
                endFlag = true;
                Argument arg("");
                arg.m_data[dataType] = (*itList++);
                if (arg.m_data[dataType] == "_")arg.m_data[dataType] = "";
                if (itList != list.constEnd() && limitsFlag)
                {
                    arg.m_data[Argument::MAX] = (*itList++);
                    if (arg.m_data[Argument::MAX] == "_")arg.m_data[dataType] = "";
                }
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
        this->_addArgumentData(pair.second, Argument::MIN);
    }

    void Function::_addCategory(const QPair<QString, QStringList> &pair)
    {
        m_flag[FLAG_CATEGORY] = true;
        if (pair.second.size() > 0)this->setCategory(pair.second.first());
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
        // Fix some old problems in YDWE ui
        if (!successFlag)
        {
            if (pair.first.length() == 0)
            {
                if (pair.second.size() == 1)
                {
                    if (!m_flag[FLAG_CATEGORY] &&
                        m_pkg->project()->matchUI(pair.second.first(), ui::Base::TRIGGER_CATEGORY) != NULL)
                    {
                        this->_addCategory(pair);
                        m_flag[FLAG_CATEGORY] = false;
                        successFlag = true;
                    }
                }
                if (!m_flag[FLAG_DEFAULTS] && !successFlag)
                {
                    if (pair.second.size() > 0)
                    {
                        auto &str = pair.second.first();
                        QString cmp = FLAG_NAME[FLAG_DEFAULTS];
                        if (str.left(cmp.length()) == cmp)
                        {
                            str = str.mid(cmp.length() + 1);
                        }
                    }
                    this->_addDefaults(pair);
                    m_flag[FLAG_DEFAULTS] = false;
                    successFlag = true;
                }
            }
            else if (pair.first == FLAG_NAME[FLAG_DEFAULTS] && !m_flag[FLAG_LIMITS])
            {
                this->_addLimits(pair);
                m_flag[FLAG_LIMITS] = false;
                successFlag = true;
            }
            else if (pair.first == "_Script" && !m_flag[FLAG_SCRIPT])
            {
                this->_addScript(pair);
                m_flag[FLAG_SCRIPT] = false;
                successFlag = true;
            }
        }

#ifdef QT_DEBUG
        if (!successFlag)qDebug() << typeName() << m_name << pair.first << pair.second;
#endif
    }

    void Function::setName(const QString &name, bool firstFlag)
    {
        if (!firstFlag)
        {
            m_pkg->project()->removeUI(this);
            m_pkg->removeCategoryUI(this);
        }
        m_name = name;
        m_pkg->project()->addUI(this);
        m_pkg->addCategoryUI(this);
    }

    const QString &Function::category() const
    {
        return m_category;
    }

    void Function::setCategory(const QString &category)
    {
        m_pkg->removeCategoryUI(this);
        m_category = category;
        m_pkg->addCategoryUI(this);
    }

    const QString &Function::version() const
    {
        return this->m_version;
    }

    void Function::setVersion(const QString &version)
    {
        m_version = version;
    }

    const QString Function::formDisplay() const
    {
        int pos = 0;
        while (pos < m_name.length())
        {
            if (m_name[pos++] != ' ')break;
        }
        return m_name.left(pos - 1).replace(' ', "~") + m_name.mid(pos - 1);
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
            this->_addArgument(str, _arg_(it.m_data[Argument::DEFAULT]), firstFlag);
            firstFlag = false;
        }
        // Limits
        if (m_flag[FLAG_LIMITS])
        {
            firstFlag = true;
            str += "\n" + this->_formArgument(0, "_" + m_name + FLAG_NAME[FLAG_LIMITS]);
            for (auto &it:m_arguments)
            {
                this->_addArgument(str, _arg_(it.m_data[Argument::MIN]), firstFlag);
                this->_addArgument(str, _arg_(it.m_data[Argument::MAX]));
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
                    this->_addArgument(str, _arg_(it.m_data[Argument::AI_DEFAULT]), firstFlag);
                    firstFlag = false;
                }
            }
        }
        str += "\n";
        return str;
    }


}}}