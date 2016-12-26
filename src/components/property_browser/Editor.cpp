//
// Created by liu on 16-12-26.
//

#include "Editor.h"

namespace TCUIEdit { namespace property_browser
{
    Editor::Editor(Browser *browser, const QString &name, const QString &value)
            : Row(browser, name, value)
    {

    }

    void Editor::emitEditSignal()
    {
        emit this->edited(this);
    }

}}