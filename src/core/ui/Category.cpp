//
// Created by liu on 2016/12/5.
//

#include "Category.h"
//#include "UIBase_Event.h"
#include "package/Package.h"
//#include "../Project.h"

namespace TCUIEdit { namespace core { namespace ui
{

    Category::Category(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = TRIGGER_CATEGORY;

        this->setName(pair.first);

        auto it = pair.second.constBegin();

        // Value 0: Display text
        if (it != pair.second.constEnd())
        {
            m_display =  *it++;
        }
        // Value 1: Icon image file
        if (it != pair.second.constEnd())
        {
            m_icon = *it++;
        }
        // Value 2: Optional flag (defaults to 0) indicating to disable display of category name
        if (it != pair.second.constEnd())
        {
            m_displayFlag = *it++;
        }
    }

    const QString& Category::icon()
    {
        return m_icon;
    }

    const QString& Category::displayFlag()
    {
        return m_displayFlag;
    }

    const QString Category::formDisplay() const
    {
        if (m_displayFlag == "1")
        {
            return m_name;
        }
        return Base::formDisplay();
    }
            QString Category::display() {
                return this->m_display;
            }
            void Category::setDisplay(QString display) {
                this->m_display=display;
            }
            void Category::setIcon(QString icon){
                this->m_icon=icon;
            }

}}}