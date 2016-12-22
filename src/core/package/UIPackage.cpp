//
// Created by liu on 2016/12/4.
//

#include "UIPackage.h"
#include "QMessageBox"

namespace TCUIEdit
{
    void UIPackage::init()
    {
        this->weString = new UIPackage_WEString(this);

        this->base[UIBase::TRIGGER_CATEGORY] = new UIPackage_Category(this);
        this->base[UIBase::TRIGGER_TYPE] = new UIPackage_Type(this);
        this->base[UIBase::TRIGGER_TYPE_DEFAULT] = new UIPackage_TypeDefault(this);
        this->base[UIBase::TRIGGER_PARAM] = new UIPackage_Param(this);
        this->base[UIBase::TRIGGER_EVENT] = new UIPackage_Event(this);
        this->base[UIBase::TRIGGER_CONDITION]=new UIPackage_Condition(this);

    }

    UIPackage::UIPackage(UIProject *project)
    {
        this->init();
        this->_proj = project;
    }


    UIPackage::UIPackage(UIProject *project, const QString &basePath, const QString &name)
    {
        this->init();
        this->_proj = project;
        this->basePath = basePath;
        this->name = name;
    }

    UIPackage_Base *UIPackage::getBase(UIBase::TYPE type) const
    {
        if (type == UIBase::UNKNOWN)return NULL;
        return this->base[type];
    }

    UIPackage_Base *UIPackage::getBaseCurrent() const
    {
        return this->getBase(this->baseTypeCurrent);
    }

    void UIPackage::processTrigData(QString &line)
    {
        // Match the sign [\w] when a new base is assigned.
        QRegExp rx("^\\[\\w+\\]$");
        if (rx.indexIn(line) > -1)
        {
            QString tempStr = rx.cap(0);
            tempStr = tempStr.mid(1, tempStr.length() - 2);
            for (int i = 0; i < UIBase::TYPE_NUM; i++)
            {
                if (tempStr == UIBase::getTypeName(UIBase::TYPE(i)))
                {
                    if (this->baseTypeCurrent != i)
                    {
                        this->baseTypeCurrent = UIBase::TYPE(i);
                        this->baseChangedFlag = true;
                    }
                    return;
                }
            }
            /**
             * @TODO throw an error here
             * The name of base type is wrong.
             * We won't change the current base.
             * But if we never have a correct one,
             * there will be a fatal error.
             */
            // this->baseTypeCurrent = UIBase::UNKNOWN;
            return;
        }
        this->baseChangedFlag = false;


        // Match the comments
        rx.setPattern("^//");
        if (rx.indexIn(line) > -1)
        {
            this->getBaseCurrent()->readComment(line);
            return;
        }

        if (getBaseTypeCurrent() < UIBase::TYPE(6))
        {
            this->getBaseCurrent()->readLine(line);
        }
    }

    void UIPackage::processWEStrings(QString &line)
    {
        // Match the sign [\w] when a new base is assigned.
        QRegExp rx("^\\[\\w+\\]$");
        if (rx.indexIn(line) > -1)return;
        rx.setPattern("^//");
        if (rx.indexIn(line) > -1)
        {
            return;
        }
        this->weString->readLine(line);
    }

    bool UIPackage::openFile(UIFileInput::TYPE fileType)
    {
        this->file.open(this->basePath, fileType);
        if (this->file.is_open())
        {
            switch (fileType)
            {
            case UIFileInput::CLASSIC_TRIG_DATA:
                this->processLine = &UIPackage::processTrigData;
                break;
            case UIFileInput::CLASSIC_WE_STRINGS:
                this->processLine = &UIPackage::processWEStrings;
                break;
            default:
                return false;
            }
            return true;
        }
        return false;
    }

    int UIPackage::readLine()
    {
        QString line;
        auto lineNum = this->file.readLineInto(line);
        if (lineNum > 0)
        {
            (this->*processLine)(line);
        }
        return lineNum;
    }
};

