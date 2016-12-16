//
// Created by liu on 2016/12/5.
//

#include "UIBase_Category.h"
#include "UIBase_Event.h"
#include "../package/UIPackage.h"
#include "../UIProject.h"

namespace TCUIEdit
{

    UIBase_Category::UIBase_Category(UIPackage *package, QPair<QString, QStringList> pair) : UIBase(package)
    {
        this->type = TRIGGER_CATEGORY;

        this->setName(pair.first);

        auto it = pair.second.constBegin();

        // Value 0: Display text
        if (it != pair.second.constEnd())
        {
            this->display = *it++;
        }
        // Value 1: Icon image file
        if (it != pair.second.constEnd())
        {
            this->icon = *it++;
        }
        // Value 2: Optional flag (defaults to 0) indicating to disable display of category name
        if (it != pair.second.constEnd())
        {
            this->displayFlag = *it++;
        }
    }

    const QString UIBase_Category::getDisplayName() const
    {
        if (this->displayFlag == "1")
        {
            return this->name;
        }
        return this->_getDisplayName();
    }

    void UIBase_Category::displayDetail(QStandardItemModel *treeModel)
    {
        treeModel->clear();
        treeModel->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));
        auto row = QList<QStandardItem *>();
        row << new QStandardItem("Name") << new QStandardItem(this->name);
        row.first()->setEditable(false);
        treeModel->appendRow(row);
        row.clear();
        row << new QStandardItem("Display text") << new QStandardItem(this->display);
        row.first()->setEditable(false);
        treeModel->appendRow(row);
        row.clear();
        row << new QStandardItem("Icon image file") << new QStandardItem(this->icon);
        row.first()->setEditable(false);
        treeModel->appendRow(row);
        row.clear();
        row << new QStandardItem("Display flag") << new QStandardItem(this->displayFlag);
        row.first()->setEditable(false);
        treeModel->appendRow(row);

        auto parent = new QStandardItem("Events");
        parent->setEditable(false);
        treeModel->appendRow(parent);

        auto base = this->_pkg->getBase(UIBase::TRIGGER_EVENT);
        for (auto it:base->getData())
        {
            if (this->name == ((UIBase_Event *) it)->getCategory())
            {
                row.clear();
                auto item = new QStandardItem(it->getPackage()->getName());
                item->setEditable(false);
                row << item;
                item = new QStandardItem(it->getDisplayName());
                item->setEditable(false);
                row << item;
                parent->appendRow(row);
            }
        }


    }
};