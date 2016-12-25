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
        m_pkg->project()->getUIMap()->removeUI(this);
        m_name = name;
        m_pkg->project()->getUIMap()->addUI(this);
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

    /*void Base::initDisplayDetail(UIMainTree *tree)
    {
        tree->clear();
        tree->setColumnCount(2);
        tree->setHeaderLabels(QStringList() << "Name" << "Value");
        tree->addTopLevelItem(this->formRow("Name", m_name));

        //treeModel->clear();
        //treeModel->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));
        //treeModel->appendRow(this->formRow("Name", m_name));
    }

    QTreeWidgetItem *Base::formRow(const QString &strName, const QString &strValue)
    {
        return new QTreeWidgetItem(QStringList() << strName << strValue);
    }*/
}}}
