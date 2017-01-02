//
// Created by liu on 17-1-2.
//

#pragma once

#include <QComboBox>

#include "common.h"
#include "Editor.h"

namespace TCUIEdit { namespace property_browser
{

    class List : public Editor
    {
    Q_OBJECT
    protected:
        QStringList m_list;
    public:
        List(Browser *browser, const QString &name, const QString &value = "");

        const QStringList& list();

        void setList(const QStringList &list);

    };

}}


