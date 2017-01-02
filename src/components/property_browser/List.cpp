//
// Created by liu on 17-1-2.
//

#include "List.h"

namespace TCUIEdit { namespace property_browser
{
    List::List(Browser *browser, const QString &name, const QString &value)
            : Editor(browser, name, value)
    {
        m_type = TYPE_LIST;
        m_list = QStringList();
    }

    const QStringList& List::list()
    {
        return m_list;
    }

    void List::setList(const QStringList &list)
    {
        m_list = list;
    }
}}