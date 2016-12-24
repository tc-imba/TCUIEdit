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

namespace TCUIEdit { namespace core { namespace package
{
    class Package
    {
    protected:
        // Protected Properties
        //

        Project *m_proj;

        FileInput m_file;

        QString m_basePath, m_name;

        bool m_baseChangedFlag = false;

        ui::Base::TYPE m_baseTypeCurrent = ui::Base::TYPE::UNKNOWN;

        Base *m_base[ui::Base::TYPE_NUM];

        WEString *m_weString;

        void (Package::*m_processLine)(QString &);



        //Protected Functions
        //

        void init();

        void processTrigData(QString &line);

        void processWEStrings(QString &line);


    public:
        // Constructors
        //

        Package(Project *project);

        Package(Project *project, const QString &basePath, const QString &name);

        ~Package();

        // Public Functions
        //

        Project *project() const;

        WEString *weString() const;

        Base *base(ui::Base::TYPE type) const;

        Base *baseCurrent() const;

        const ui::Base::TYPE baseTypeCurrent() const;

        const bool isBaseChanged() const;

        const QString &name() const;

        void setName(const QString &name);

        bool openFile(FileInput::TYPE fileType);

        int readLine();

    };


}}}


