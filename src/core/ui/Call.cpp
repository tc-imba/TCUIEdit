//
// Created by liu on 2016/12/15.
//

#include "Call.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Call::Call(package::Package *package, QPair<QString, QStringList> pair)
            : Function(package)
    {
        m_type = TRIGGER_CALL;

        this->setName(pair.first);

        auto it = pair.second.constBegin();
        // Value 0: first game version in which this function is valid
        if (it != pair.second.constEnd())
        {
            m_version = *it++;
        }
        // Value 1: flag (0 or 1) indicating if the call can be used in events
        if (it != pair.second.constEnd())
        {
            m_eventFlag = *it++;
        }
        // Value 2: return type
        if (it != pair.second.constEnd())
        {
            m_returnType = *it++;
        }
        // Value 3+: argument types
        while (it != pair.second.constEnd())
        {
            m_arguments.push_back(Argument(*it++));
        }
    }
            QString Call::version(){
                return this->m_version;
            }
            void Call::setVersion(QString version) {
                this->m_version=version;
            }
            bool *Call::flag() {
                return this->m_flag;
            }
            void Call::setFlag(bool *flag) {
                this->m_flag=flag;
            }
            TYPE Call::type()  {
                return this->m_type;
            }
            void Call::setType(TYPE type){
                this->m_type=type;
            }

}}}