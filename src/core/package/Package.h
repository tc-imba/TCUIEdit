//
// Created by liu on 2016/12/4.
//

#pragma once

#include "../core.h"
#include "../File.h"
#include "../ui/all.h"
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

        File m_file;

        QString m_basePath, m_name;

        bool m_baseChangedFlag = false;

        ui::Base::TYPE m_baseTypeCurrent = ui::Base::TYPE::UNKNOWN;

        Base *m_base[ui::Base::TYPE_NUM];

        WEString *m_weString;

        QHash<QPair<QString, QString>, QMultiMap<QString, ui::Function *> > m_categoryMap[4];

        //QHash<FunctionProperty, QMultiMap<QString, ui::Base *>>m_categoryMap;

        static const QMultiMap<QString, ui::Function *> m_emptyCategoryMap;

        void (Package::*m_processLine)(QString &);


        //Protected Functions
        //

        void init();

        void _processTrigData(QString &line);

        void _processWEStrings(QString &line);

        void _writeTrigData();

        void _writeWEStrings();

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

        void setBasePath(const QString &basePath);

        bool readFile(File::TYPE fileType);

        int readLine();

        bool writeFile(File::TYPE fileType);

        void addCategoryUI(ui::Function *ui);

        void removeCategoryUI(ui::Function *ui);

        const QHash<QPair<QString, QString>, QMultiMap<QString, ui::Function * >> &
        categoryMap(ui::Function::FUNCTION_TYPE funcType) const;

        const QMultiMap<QString, ui::Function *> &
        categoryMap(ui::Function::FUNCTION_TYPE funcType, const QString &category,
                    const QString &returnType = "") const;
    };


}}}


