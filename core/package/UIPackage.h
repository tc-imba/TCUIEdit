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
#include "../base/UIBase.h"
#include "UIPackage_Base.h"
#include "UIPackage_Category.h"

namespace TCUIEdit
{
    class UIPackage
    {
    protected:
        void initBase();

        QByteArray fileData;
        QTextStream *file;
        int fileLineNum = 0;

        bool baseChangedFlag = false;
        UIBase::TYPE baseTypeCurrent = UIBase::TYPE::UNKNOWN;

        //UIPackage_Category *category;

        UIPackage_Base *base[UIBase::TYPE_NUM];

        UIPackage_Base *getBaseCurrent();

        void processLine(QString &line);

    public:


        UIPackage();

        UIPackage(const QString &filename);


        int readLine();


        const bool isBaseChanged() const
        { return this->baseChangedFlag; }

        const UIBase::TYPE getBaseTypeCurrent() const
        { return this->baseTypeCurrent; }
    };


};

#endif //TCUIEDIT_UIPACKAGE_H
