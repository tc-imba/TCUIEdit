//
// Created by sunyi on 2016/12/29.
//
#include "Type.h"
namespace TCUIEdit{namespace mainview
    {
        Type::Type(property_browser::Browser *browser, core::ui::Base *ui) 
                :Base(browser,ui)
        {
            m_ui=(core::ui::Type *)ui;
            this->refresh();
        }
        void Type::refresh(){
            Base::refresh();
            auto parent=m_browser->aliasRow("Property");
            auto row=parent->addEditor("Version",m_ui->version());
            row->nameItem()->setData("第一个可运行游戏版本",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));
            
            row=parent->addEditor("Global Flag",m_ui->globalFlag());
            row->nameItem()->setData("是否为全局变量",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));
            
            row=parent->addEditor("Compare Flag",m_ui->compareFlag());
            row->nameItem()->setData("是否适用比较运算符",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));

            row=parent->addEditor("Display",m_ui->Display());
            row->nameItem()->setData("编辑器中显示的名字",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));

            row=parent->addEditor("Base Type",m_ui->baseFlag());
            row->nameItem()->setData("ui type？内容我也不知道是什么",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));

            row=parent->addEditor("Import Type",m_ui->importType());
            row->nameItem()->setData("文件名（可选）",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));

            row=parent->addEditor("Base Flag",m_ui->baseFlag());
            row->nameItem()->setData("是否视作编译器中的ui",Qt::ToolTipRole);
            this->connect(row,SIGNAL(edited(TCUIEdit::property_browser::Row *)),
                          this,SLOT(onDisplayEdited(TCUIEdit::property_browser::Row *)));


            
        }

    }}
