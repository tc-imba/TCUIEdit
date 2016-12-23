//
// Created by liu on 2016/12/17.
//

#pragma once

#include <QStandardItem>
#include "../core/core.h"
#include "../core/ui/Base.h"

using namespace TCUIEdit::Core;

namespace TCUIEdit
{

    class UITreeViewItem : public QStandardItem
    {
    protected:
        UI::Base *base;
        bool titleFlag;
        int depth;

    public:
        UITreeViewItem(const QString &text);

        UITreeViewItem(const QString &text, UITreeViewItem *item);

        UITreeViewItem(UI::Base *base);

        ~UITreeViewItem();

        UI::Base *getBase() const;

        int getDepth() const;
    };

};

