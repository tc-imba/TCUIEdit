//
// Created by liu on 2016/12/15.
//

#include "Event.h"

namespace TCUIEdit { namespace core { namespace ui
{
    const char *Event::FLAG_NAME[Event::FLAG_NUM] =
            {"_Defaults", "_Category"};


    Event::Event(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_EVENT;
        for (int i = 0; i < FLAG_NUM; i++)m_flag[i] = false;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this function is valid
        if (it != pair.second.constEnd())
        {
            m_version = *it++;
        }
        // Value 1+: argument types
        while (it != pair.second.constEnd())
        {
            m_arguments.push_back(Argument(*it++));
        }
    }

    void Event::_addArgumentData(const QStringList &list, Argument::DATA_TYPE dataType)
    {
        auto itArg = m_arguments.begin();
        auto itList = list.constBegin();
        while (itList != list.constEnd())
        {
            if (itArg != m_arguments.end())
            {
                (*itArg++).m_data[dataType] = (*itList++);
            }
            else
            {
                Argument arg("");
                arg.m_data[dataType] = (*itList++);
                m_arguments.push_back(arg);
            }
        }
    }

    bool Event::_matchFlag(QString &text, FLAG flag)
    {
        return text == FLAG_NAME[flag] && !m_flag[flag];
    }

    void Event::add(QPair<QString, QStringList> pair)
    {
        if (_matchFlag(pair.first, FLAG_DEFAULTS))
        {
            m_flag[FLAG_DEFAULTS] = true;
            this->_addArgumentData(pair.second, Argument::DEFAULT);
        }
        else if (_matchFlag(pair.first, FLAG_CATEGORY))
        {
            m_flag[FLAG_CATEGORY] = true;
            if(pair.second.size()>0)m_category=pair.second.first();
        }
    }

    const QString Event::formDisplay() const
    {
        return m_name;
    }

    const QString &Event::category() const
    {
        return m_category;
    }

    /*void UIBase_Event::displayDetail(UIMainTree *tree)
    {
        this->initDisplayDetail(treeModel);

        treeModel->appendRow(this->formRow("First game version", this->version));

        auto parent = new QStandardItem("Arguments");
        parent->setEditable(false);
        treeModel->appendRow(parent);

        for (auto &it:this->arguments)
        {
            parent->appendRow(this->formRow(it.first, it.second, true));
        }
    }*/
}}}