//
// Created by liu on 2016/12/3.
//

#include "Base.h"
#include "Project.h"
#include "package/Package.h"

namespace TCUIEdit { namespace core { namespace ui
{
    const char *Base::TYPE_NAME[Base::TYPE_NUM] =
            {"TriggerCategories", "TriggerTypes", "TriggerTypeDefaults", "TriggerParams",
             "TriggerEvents", "TriggerConditions", "TriggerActions", "TriggerCalls",
             "DefaultTriggerCategories", "DefaultTriggers"
            };

    // Constructors
    //

    Base::Base(package::Package *package)
    {
        m_pkg = package;
    }

    Base::~Base()
    {

    }

    // Protected Functions
    //
    QString Base::_formArgument(int argc, ...)
    {
        QString str = "";
        va_list argv;
        va_start(argv, argc);
        str += va_arg(argv, QString) + "=";
        for (int i = 1; i < argc; i++)
        {
            str += va_arg(argv, QString) + ",";
        }
        if (argc >= 1)
        {
            str += va_arg(argv, QString);
        }
        va_end(argv);
        return str;
    }

    void Base::_addArgument(QString &str, const QString &arg, bool firstFlag)
    {
        str += !firstFlag ? "," + arg : arg;
    }

    // Public Functions
    //

    package::Package *Base::package() const
    {
        return m_pkg;
    }

    Base::TYPE Base::type() const
    {
        return m_type;
    }

    const char *Base::typeName(TYPE type)
    {
        if (type >= 0 && type < Base::TYPE_NUM)
        {
            return Base::TYPE_NAME[type];
        }
        return "UNKNOWN_TYPE";
    }

    const char *Base::typeName() const
    {
        return this->typeName(m_type);
    }

    const QString &Base::name() const
    {
        return m_name;
    }

    void Base::setName(const QString &name)
    {
        m_pkg->project()->removeUI(this);
        m_name = name;
        m_pkg->project()->addUI(this);
    }

    Error Base::examineName() const
    {
        auto list = m_pkg->project()->examineUI(this);
        if (list.size() == 0)return Error();
        Error error("Redefinition", Error::TYPE_ERROR);
        for (auto it:list)
        {
            error.addItem(it->package()->name(), it->name(), it);
        }
        return error;
    }

    const QString Base::display(bool origin) const
    {
        if (origin)return m_display;
        return m_pkg->weString()->getValue(m_display);
    }

    void Base::setDisplay(const QString &display)
    {
        m_display = display;
    }

    const QString Base::formDisplay() const
    {
        if (m_display == "")
        {
            return m_name;
        }
        return m_name + " - " + this->display();
    }

    Error Base::examineFlag(const QString &value, bool optionalFlag) const
    {
        if (value == "0" || value == "1" || value.isEmpty() && optionalFlag)return Error();
        Error error("Illegal", Error::TYPE_ERROR);
        //error.addItem("","")
        return error;
    }


}}}
