//
// Created by liu on 16-12-26.
//

#include "Editor.h"

namespace TCUIEdit { namespace property_browser
{
    Editor::Editor(Browser *browser, const QString &name, const QString &value)
            : Row(browser, name, value)
    {
        m_type = TYPE_EDITOR;
    }

    void Editor::emitEditSignal()
    {
        emit this->edited(this);
    }

}}