//
// Created by liu on 2016/12/4.
//

#ifndef TCUIEDIT_UIPACKAGE_H
#define TCUIEDIT_UIPACKAGE_H


#include <QFile>
#include <QTextStream>
#include <QByteArray>
#include <QRegExp>
#include <QDebug>

#include "../UICore.h"
#include "../UIFileInput.h"
#include "../base/UIBase.h"
#include "UIPackage_WEString.h"
#include "UIPackage_Base.h"
#include "UIPackage_Category.h"
#include "UIPackage_Type.h"

namespace TCUIEdit
{
    class UIPackage
    {
    protected:
        UIProject *_proj;

        void init();

        UIFileInput file;

        QString basePath, name;

        bool baseChangedFlag = false;
        UIBase::TYPE baseTypeCurrent = UIBase::TYPE::UNKNOWN;

        //UIPackage_Category *category;

        UIPackage_Base *base[UIBase::TYPE_NUM];

        UIPackage_WEString *weString;

        void processTrigData(QString &line);

        void processWEStrings(QString &line);

        void (UIPackage::*processLine)(QString &);

    public:

        UIPackage();

        UIPackage(UIProject *project, const QString &basePath);

        bool openFile(UIFileInput::TYPE fileType);

        int readLine();

        UIProject *getProject() const
        { return this->_proj; }

        UIPackage_WEString *getWEString() const
        { return this->weString; }

        UIPackage_Base *getBase(UIBase::TYPE type) const;

        UIPackage_Base *getBaseCurrent() const;

        const bool isBaseChanged() const
        { return this->baseChangedFlag; }

        const UIBase::TYPE getBaseTypeCurrent() const
        { return this->baseTypeCurrent; }
    };


};

#endif //TCUIEDIT_UIPACKAGE_H
