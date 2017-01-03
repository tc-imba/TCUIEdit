//
// Created by liu on 2016/12/21.
//

#include "Category.h"

namespace TCUIEdit { namespace mainview
{

    Category::Category(property_browser::Browser *browser, core::ui::Base *ui)
            : Base(browser, ui)
    {
        m_ui = (core::ui::Category *) ui;
        this->refresh();
    }

    void Category::refresh()
    {
        Base::refresh();

        auto parent = m_browser->aliasRow("Property");

        auto row = parent->addEditor("Display", m_ui->display(true));
        row->nameItem()->setData("编辑器中显示的名字（可以为WE_STRING）", Qt::ToolTipRole);
        this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                      this, SLOT(onDisplayEdited(TCUIEdit::property_browser::Row * )));
        row = parent->addText("Display (in Editor)", m_ui->display(false), "DisplayName");
        row->nameItem()->setData("编辑器中最终显示的名字", Qt::ToolTipRole);


        row = parent->addEditor("Icon", m_ui->icon());
        row->nameItem()->setData("编辑器中显示的图标", Qt::ToolTipRole);

        row = parent->addList("Display Flag", m_ui->displayFlag(), QStringList() << "0" << "1");
        row->nameItem()->setData("编辑器中是否显示该类，0为显示，1为不显示", Qt::ToolTipRole);


        const QString typeNames[4] = {"Events", "Condition", "Action", "Call"};
        const core::ui::Base::TYPE types[4] = {core::ui::Base::TRIGGER_EVENT,
                                               core::ui::Base::TRIGGER_CONDITION,
                                               core::ui::Base::TRIGGER_ACTION,
                                               core::ui::Base::TRIGGER_CALL};

        for (int i = 0; i < 4; i++)
        {
            parent = m_browser->addCategory(typeNames[i]);
            for (auto itPkg:*(m_ui->package()->project()->packages()))
            {
                for (auto itUI:itPkg->base(types[i])->data())
                {
                    if (m_ui->name() == ((core::ui::Function *) itUI)->category())
                    {
                        row = parent->addText(itPkg->name(), itUI->name(), "");
                        row->setData((qlonglong) itUI);
                    }
                }
            }
        }

        m_browser->expandToDepth(1);
    }

    void Category::onNameEdited(TCUIEdit::property_browser::Row *row)
    {
        qDebug() << "onNameEdited" << m_ui->name();

        QString name = m_ui->name();
        Base::onNameEdited(row);
        if (name == m_ui->name())return;

        auto dialog = new view::chaindialog::ChainDialog();
        const core::ui::Base::TYPE types[4] = {core::ui::Base::TRIGGER_EVENT,
                                               core::ui::Base::TRIGGER_CONDITION,
                                               core::ui::Base::TRIGGER_ACTION,
                                               core::ui::Base::TRIGGER_CALL};

        auto rootItem = dialog->addItem("");
        int totalCount = 0;
        for (int i = 0; i < 4; i++)
        {
            QStandardItem *typeItem;
            bool firstPackageFlag = true;
            int typeCount = 0;
            for (auto itPkg:*(m_ui->package()->project()->packages()))
            {
                QStandardItem *packageItem;
                bool firstUIFlag = true;
                int packageCount = 0;
                for (auto itUI:itPkg->base(types[i])->data())
                {
                    if (name == ((core::ui::Function *) itUI)->category())
                    {
                        if (firstPackageFlag)
                        {
                            firstPackageFlag = false;
                            typeItem = dialog->addItem("", rootItem);
                        }
                        if (firstUIFlag)
                        {
                            firstUIFlag = false;
                            packageItem = dialog->addItem("", typeItem);
                        }
                        dialog->addItem(itUI->name(), packageItem, itUI);
                        packageCount++;
                    }
                }
                if (!firstUIFlag)
                {
                    QString str;
                    QTextStream stream(&str);
                    stream << itPkg->name() << " ( " << packageCount << " items )";
                    packageItem->setText(str);
                    typeCount += packageCount;
                }
            }
            if (!firstPackageFlag)
            {
                QString str;
                QTextStream stream(&str);
                stream << core::ui::Base::typeName(types[i])
                       << " ( " << typeCount << " items )";
                typeItem->setText(str);
                totalCount += typeCount;
            }
        }

        if (totalCount == 0)
        {
            delete dialog;
            this->refresh();
            return;
        }

        QString str;
        QTextStream stream(&str);
        stream << "All Effected ( " << totalCount << " items )";
        rootItem->setText(str);

        dialog->connectCheckbox(1);
        rootItem->setCheckState(Qt::Checked);
        dialog->setLabel(
                "You are editing the name of the category of the following items, please choose those you'd like to change their values of category respectively.\n你正在编辑以下UI所对应的的类别名，请选择想要一起改动的UI");

        auto result = dialog->exec();
        if (result == QDialog::Accepted)
        {
            for (int i = 0; i < rootItem->rowCount(); i++)
            {
                auto typeItem = rootItem->child(i);
                for (int j = 0; j < typeItem->rowCount(); j++)
                {
                    auto packageItem = typeItem->child(j);
                    for (int k = 0; k < packageItem->rowCount(); k++)
                    {
                        auto uiItem = packageItem->child(k);
                        if (uiItem->checkState() == Qt::Checked)
                        {
                            auto ui = (core::ui::Function *) uiItem->data(Qt::UserRole + 1).toLongLong();
                            ui->setCategory(row->value());
                        }
                    }
                }
            }
            this->refresh();
        }
        else
        {
            this->disconnect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                             this, SLOT(onNameEdited(TCUIEdit::property_browser::Row * )));
            m_ui->setName(name);
            row->setValue(name);
            row->valueItem()->setText(name);
            this->connect(row, SIGNAL(edited(TCUIEdit::property_browser::Row * )),
                          this, SLOT(onNameEdited(TCUIEdit::property_browser::Row * )));
        }
        delete dialog;
    }

}}
