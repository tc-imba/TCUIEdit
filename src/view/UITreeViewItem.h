//
// Created by liu on 2016/12/17.
//

#ifndef TCUIEDIT_UITREEVIEWITEM_H
#define TCUIEDIT_UITREEVIEWITEM_H

#include <QStandardItem>
#include "../core/UICore.h"
#include "../core/base/base.h"

namespace TCUIEdit
{

    class UITreeViewItem : public QStandardItem
    {
    protected:
        UIBase *base;
        bool titleFlag;
        int depth;

    public:
        UITreeViewItem(const QString &text);

        UITreeViewItem(const QString &text, UITreeViewItem *item);

        UITreeViewItem(UIBase *base);

        ~UITreeViewItem();

        UIBase *getBase() const;

        int getDepth() const;
    };

};
#endif //TCUIEDIT_UITREEVIEWITEM_H
