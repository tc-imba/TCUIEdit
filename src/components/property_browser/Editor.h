//
// Created by liu on 16-12-26.
//

#pragma once

#include "Row.h"

namespace TCUIEdit { namespace property_browser
{
    class Editor : public Row
    {
    Q_OBJECT
    public:
        Editor(Browser *browser, const QString &name, const QString &value = "");

        void emitEditSignal();


    signals:

        void edited(TCUIEdit::property_browser::Row *);
    };

}}
