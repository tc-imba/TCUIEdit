//
// Created by liu on 2016/12/4.
//

#include "package/UIPackage.h"
#include "QMessageBox"

namespace TCUIEdit
{
    void UIPackage::initBase()
    {
        this->base[UIBase::TRIGGER_CATEGORY] = new UIPackage_Category();

    }

    UIPackage::UIPackage()
    {
        this->initBase();
    }


    UIPackage::UIPackage(const QString &filename)
    {
        this->initBase();
        QFile qFile(filename);
        if (qFile.open(QFile::ReadOnly))
        {
            this->fileData = qFile.readAll();
            this->file = new QTextStream(this->fileData);
            /**
             * @TODO File Codec of input UI File
             * The default format of UI File is UTF-8
             * This version only supports UTF-8 encoding
             * The support of ANSI and UNICODE may be added later
             */
            this->file->setCodec("UTF-8");
            qFile.close();
        }
    }

    UIPackage_Base *UIPackage::getBaseCurrent()
    {
        if (this->baseTypeCurrent == UIBase::UNKNOWN)return NULL;
        return this->base[this->baseTypeCurrent];
    }

    int UIPackage::readLine()
    {
        if (this->fileLineNum < 0)return 0;
        QString line;
        while (this->file->readLineInto(&line))
        {
            this->fileLineNum++;
            line = line.trimmed();
            if (!line.isEmpty())
            {
                this->processLine(line);
                return this->fileLineNum;
            }
        }
        this->fileLineNum = -1;
        return 0;

    }

    void UIPackage::processLine(QString &line)
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

        this->getBaseCurrent()->readLine(line);
    }

};

