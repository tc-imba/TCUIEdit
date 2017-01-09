//
// Created by liu on 17-1-3.
//

#include "DefaultCategory.h"

namespace TCUIEdit { namespace core { namespace ui
{
    DefaultCategory::DefaultCategory(package::Package *package, QPair<QString, QStringList> pair)
            : Base(package)
    {
        m_type = DEFAULT_TRIGGER_CATEGORY;

        this->setName(pair.first, true);

        auto it = pair.second.constBegin();

        if (it != pair.second.constEnd())
        {
            m_display = *it++;
        }
    }

    DefaultCategory::~DefaultCategory()
    {

    }

    const QString DefaultCategory::formDisplay() const
    {
        return m_name;
    }

}}}