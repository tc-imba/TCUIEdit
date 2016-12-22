//
// Created by liu on 2016/12/3.
//

#include "Base.h"
#include "../UIProject.h"
#include "package/UIPackage.h"

#define _PROJ this->_pkg->getProject()

namespace TCUIEdit { namespace UI
{
    const char *Base::TYPE_NAME[Base::TYPE_NUM] =
            {"TriggerCategories", "TriggerTypes", "TriggerTypeDefaults", "TriggerParams",
             "TriggerEvents", "TriggerConditions", "TriggerActions", "TriggerCalls",
             "DefaultTriggerCategories", "DefaultTriggers"
            };

    // Constructors
    //

    Base::Base(UIPackage *package)
    {
        this->_pkg = package;
    }

    Base::~Base()
    {

    }

    // Protected Functions
    //

    const QString Base::_getDisplayName() const
    {
        if (this->display == "")
        {
            return this->name;
        }
        return this->name + " - " + this->getDisplay();
    }

    // Public Functions
    //

    UIPackage *Base::getPackage() const
    {
        return this->_pkg;
    }

    Base::TYPE Base::getType() const
    {
        return this->type;
    }

    const char *Base::getTypeName(TYPE type)
    {
        if (type >= 0 && type < Base::TYPE_NUM)
        {
            return Base::TYPE_NAME[type];
        }
        return "UNKNOWN_TYPE";
    }

    const char *Base::getTypeName() const
    {
        return this->getTypeName(this->type);
    }

    const QString &Base::getName() const
    {
        return this->name;
    }

    void Base::setName(const QString &name)
    {
        _PROJ->getUIMap()->removeUI(this);
        this->name = name;
        _PROJ->getUIMap()->addUI(this);
    }

    const QString Base::getDisplay(bool origin) const
    {
        if (origin)return this->display;
        return this->_pkg->getWEString()->getValue(this->display);
    }

    void Base::setDisplay(const QString &display)
    {
        this->display = display;
    }

    /*void Base::initDisplayDetail(UIMainTree *tree)
    {
        tree->clear();
        tree->setColumnCount(2);
        tree->setHeaderLabels(QStringList() << "Name" << "Value");
        tree->addTopLevelItem(this->formRow("Name", this->name));

        //treeModel->clear();
        //treeModel->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));
        //treeModel->appendRow(this->formRow("Name", this->name));
    }

    QTreeWidgetItem *Base::formRow(const QString &strName, const QString &strValue)
    {
        return new QTreeWidgetItem(QStringList() << strName << strValue);
    }*/
}}
