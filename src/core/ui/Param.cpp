//
// Created by liu on 2016/12/13.
//

#include "Param.h"
#include "Type.h"
#include "package/Package.h"
#include "Project.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Param::Param(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_PARAM;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this parameter is valid
        if (it != pair.second.constEnd())
        {
            this->m_version = *it++;
        }
        // Value 1: variable type
        if (it != pair.second.constEnd())
        {
            this->m_variable = *it++;
        }
        // Value 2: code text (used in script)
        if (it != pair.second.constEnd())
        {
            this->m_script = *it++;
        }
        // Value 3: display text
        if (it != pair.second.constEnd())
        {
            m_display =  *it++;
        }

    }

    Type *Param::getOriginType() const
    {
        return (Type *) (m_pkg->project()->matchUI(this->m_variable, TRIGGER_TYPE));
    }

    const QString Param::formDisplay() const
    {
        auto type = this->getOriginType();
        if (type)
        {
            QString str = type->formDisplay();
            if (str != "")
            {
                return m_name + " ( " + str + " )";
            }
        }
        return m_name;
    }
            QString Param::version(){
                return this->m_version;
            }
            void Param::setVersion(QString version){
                this->m_version=version;
            }
            QString Param::variable() {
                return this->m_variable;
            }
            void Param::setVariable(QString variable) {
                this->m_variable=variable;
            }
            QString Param::script() {
                return this->m_script;
            }
            void Param::setScript(QString script) {
                this->m_script=script;
            }

}}}