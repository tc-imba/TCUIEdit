//
// Created by liu on 2016/12/4.
//

#pragma once

#include "../core.h"
#include "../FileInput.h"
#include "../ui/Base.h"
#include "WEString.h"
#include "Base.h"
#include "Category.h"
#include "Type.h"
#include "TypeDefault.h"
#include "Param.h"
#include "Event.h"
#include "Condition.h"
#include "Action.h"
#include "Call.h"

namespace TCUIEdit { namespace Core { namespace Package
{
    class Package
    {
    protected:
        Project *_proj;

        void init();

        FileInput file;

        QString basePath, name;

        bool baseChangedFlag = false;
        UI::Base::TYPE baseTypeCurrent = UI::Base::TYPE::UNKNOWN;

        //Category *category;

        Base *base[UI::Base::TYPE_NUM];

        WEString *weString;

        void processTrigData(QString &line);

        void processWEStrings(QString &line);

        void (Package::*processLine)(QString &);

    public:

        Package(Project *project);

        Package(Project *project, const QString &basePath, const QString &name);

        bool openFile(FileInput::TYPE fileType);

        int readLine();

        Project *getProject() const
        { return this->_proj; }

        WEString *getWEString() const
        { return this->weString; }

        Base *getBase(UI::Base::TYPE type) const;

        Base *getBaseCurrent() const;

        const bool isBaseChanged() const
        { return this->baseChangedFlag; }

        const UI::Base::TYPE getBaseTypeCurrent() const
        { return this->baseTypeCurrent; }

        const QString &getName() const
        { return this->name; }
    };


}}}


