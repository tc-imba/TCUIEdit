//
// Created by liu on 2016/12/4.
//

#include "Package.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    void Package::init()
    {
        this->weString = new WEString(this);

        this->base[UI::Base::TRIGGER_CATEGORY] = new Category(this);
        this->base[UI::Base::TRIGGER_TYPE] = new Type(this);
        this->base[UI::Base::TRIGGER_TYPE_DEFAULT] = new TypeDefault(this);
        this->base[UI::Base::TRIGGER_PARAM] = new Param(this);
        this->base[UI::Base::TRIGGER_EVENT] = new Event(this);
        this->base[UI::Base::TRIGGER_CONDITION]=new Condition(this);
        this->base[UI::Base::TRIGGER_ACTION]=new Action(this);
        this->base[UI::Base::TRIGGER_CALL]=new Call(this);

    }

    Package::Package(Project *project)
    {
        this->init();
        this->_proj = project;
    }


    Package::Package(Project *project, const QString &basePath, const QString &name)
    {
        this->init();
        this->_proj = project;
        this->basePath = basePath;
        this->name = name;
    }

    Base *Package::getBase(UI::Base::TYPE type) const
    {
        if (type == UI::Base::UNKNOWN)return NULL;
        return this->base[type];
    }

    Base *Package::getBaseCurrent() const
    {
        return this->getBase(this->baseTypeCurrent);
    }

    void Package::processTrigData(QString &line)
    {
        // Match the sign [\w] when a new ui is assigned.
        QRegExp rx("^\\[\\w+\\]$");
        if (rx.indexIn(line) > -1)
        {
            QString tempStr = rx.cap(0);
            tempStr = tempStr.mid(1, tempStr.length() - 2);
            for (int i = 0; i < UI::Base::TYPE_NUM; i++)
            {
                if (tempStr == UI::Base::getTypeName(UI::Base::TYPE(i)))
                {
                    if (this->baseTypeCurrent != i)
                    {
                        this->baseTypeCurrent = UI::Base::TYPE(i);
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
            // this->baseTypeCurrent = UI::Base::UNKNOWN;
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

        if (getBaseTypeCurrent() < UI::Base::TYPE(8))
        {
            this->getBaseCurrent()->readLine(line);
        }
    }

    void Package::processWEStrings(QString &line)
    {
        // Match the sign [\w] when a new ui is assigned.
        QRegExp rx("^\\[\\w+\\]$");
        if (rx.indexIn(line) > -1)return;
        rx.setPattern("^//");
        if (rx.indexIn(line) > -1)
        {
            return;
        }
        this->weString->readLine(line);
    }

    bool Package::openFile(FileInput::TYPE fileType)
    {
        this->file.open(this->basePath, fileType);
        if (this->file.is_open())
        {
            switch (fileType)
            {
            case FileInput::CLASSIC_TRIG_DATA:
                this->processLine = &Package::processTrigData;
                break;
            case FileInput::CLASSIC_WE_STRINGS:
                this->processLine = &Package::processWEStrings;
                break;
            default:
                return false;
            }
            return true;
        }
        return false;
    }

    int Package::readLine()
    {
        QString line;
        auto lineNum = this->file.readLineInto(line);
        if (lineNum > 0)
        {
            (this->*processLine)(line);
        }
        return lineNum;
    }
}}}

