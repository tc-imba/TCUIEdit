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
    /*public:
        struct FunctionProperty
        {
            ui::Function::FUNCTION_TYPE m_type;
            QString m_category, m_returnType;

            FunctionProperty(ui::Function::FUNCTION_TYPE type, const QString &category = "",
                             const QString &returnType = "")
                    : m_type(type), m_category(category), m_returnType(returnType)
            {}
        };
    */
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

        QHash<QPair<QString, QString>, QMultiMap<QString, ui::Base *> > m_categoryMap[4];

        //QHash<FunctionProperty, QMultiMap<QString, ui::Base *>>m_categoryMap;

        static const QMultiMap<QString, ui::Base *> m_emptyCategoryMap;

        void (Package::*m_processLine)(QString &);


        //Protected Functions
        //

        void init();

        void _processTrigData(QString &line);

        void _processWEStrings(QString &line);

        void _writeTrigData();


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

        const QHash<QPair<QString, QString>, QMultiMap<QString, ui::Base * >> &
        categoryMap(ui::Function::FUNCTION_TYPE funcType) const;

        const QMultiMap<QString, ui::Base *> &
        categoryMap(ui::Function::FUNCTION_TYPE funcType, const QString &category,
                    const QString &returnType = "") const;
    };

    /*inline bool operator==(const Package::FunctionProperty &a, const Package::FunctionProperty &b)
    {
        return a.m_type == b.m_type && a.m_category == b.m_category && a.m_returnType == b.m_returnType;
    }

    inline uint qHash(const Package::FunctionProperty &key, uint seed)
    {
        return qHash(key.m_category, seed) ^ qHash(key.m_returnType, seed) ^ key.m_type;
    }*/
}}}


