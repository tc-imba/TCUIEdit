//
// Created by liu on 2016/12/3.
//

#include "UIBase.h"
#include "../UIProject.h"
#include "package/UIPackage.h"

#define _PROJ this->_pkg->getProject()

namespace TCUIEdit
{
    const char *UIBase::TYPE_NAME[UIBase::TYPE_NUM] =
            {"TriggerCategories", "TriggerTypes", "TriggerTypeDefaults", "TriggerParams",
             "TriggerEvents", "TriggerConditions", "TriggerActions", "TriggerCalls",
             "DefaultTriggerCategories", "DefaultTriggers"
            };

    UIBase::UIBase(UIPackage *package)
    {
        this->_pkg = package;
    }

    UIBase::TYPE UIBase::getType() const
    {
        return this->type;
    }

    const char *UIBase::getTypeName() const
    {
        return this->getTypeName(this->type);
    }

    const char *UIBase::getTypeName(TYPE type)
    {
        if (type >= 0 && type < UIBase::TYPE_NUM)
        {
            return UIBase::TYPE_NAME[type];
        }
        return "UNKNOWN_TYPE";
    }

    const QString &UIBase::getName() const
    {
        return this->name;
    }

    const QString UIBase::getDisplay() const
    {
        return this->_pkg->getWEString()->getValue(this->display);
    }

    const QString UIBase::_getDisplayName() const
    {
        if (this->display == "")
        {
            return this->name;
        }
        return this->name + " - " + this->getDisplay();
    }

    void UIBase::setName(const QString &name)
    {
        _PROJ->getUIMap()->removeUI(this);
        this->name = name;
        _PROJ->getUIMap()->addUI(this);
    }

    UIPackage *UIBase::getPackage() const
    {
        return this->_pkg;
    }

    void UIBase::initDisplayDetail(UIMainTree *tree)
    {
        tree->clear();
        tree->setColumnCount(2);
        tree->setHeaderLabels(QStringList() << "Name" << "Value");
        //treeModel->clear();
        //treeModel->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));
        //treeModel->appendRow(this->formRow("Name", this->name));
    }

    QTreeWidgetItem* UIBase::formRow(const QString &strName, const QString &strValue)
    {
        return new QTreeWidgetItem(QStringList()<<strName<<strValue);
    }
}
