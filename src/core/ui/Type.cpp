//
// Created by liu on 2016/12/8.
//

#include "Type.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Type::Type(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_TYPE;

        this->setName(pair.first);

        auto it = pair.second.constBegin();

        // Value 0: first game version in which this type is valid
        if (it != pair.second.constEnd())
        {
            this->m_version = *it++;
        }
        // Value 1: flag (0 or 1) indicating if this type can be a global variable
        if (it != pair.second.constEnd())
        {
            this->m_globalFlag = *it++;
        }
        // Value 2: flag (0 or 1) indicating if this type can be used with comparison operators
        if (it != pair.second.constEnd())
        {
            this->m_compareFlag = *it++;
        }
        // Value 3: string to display in the editor
        if (it != pair.second.constEnd())
        {
            m_display =  *it++;
        }
        // Value 4: ui type, used only for custom types
        if (it != pair.second.constEnd())
        {
            this->m_baseType = *it++;
        }
        // Value 5: import type, for strings which represent files (optional)
        if (it != pair.second.constEnd())
        {
            this->m_importType = *it++;
        }
        // Value 6: flag (0 or 1) indicating to treat this type as the ui type in the editor
        if (it != pair.second.constEnd())
        {
            this->m_baseFlag = *it++;
        }


    }
            QString Type::version(){
                return this->m_version;
            }
            void Type::setVersion(QString version){
                this->m_version=version;
            }
            QString Type::globalFlag(){
                return this->m_globalFlag;
            }
            void Type::setGlobalFlag(QString globalFlag){
                this->m_globalFlag=globalFlag;
            }
            QString Type::compareFlag(){
                return this->m_compareFlag;
            }
            void Type::setCompareFlag(QString compareFlag){
                this->m_compareFlag=compareFlag;
            }
            QString Type::display(){
                return this->m_display;
            }
            void Type::setDisplay(QString display){
                this->m_display=display;
            }
            QString Type::baseType(){
                return this->m_baseType;
            }
            void Type::setBaseType(QString baseType){
                this->m_baseType=baseType;
            }
            QString Type::importType(){
                return this->m_importType;
            }
            void Type::setImportType(QString importType){
                this->m_importType=importType;
            }
            QString Type::baseFlag(){
                return this->m_baseFlag;
            }
            void Type::setBaseFlag(QString baseFlag){
                this->m_baseFlag=baseFlag;
            }

}}}