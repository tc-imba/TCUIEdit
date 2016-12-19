//
// Created by liu on 2016/12/17.
//

#include "UITreeViewItem.h"

namespace TCUIEdit
{

    UITreeViewItem::UITreeViewItem(const QString &text) : QStandardItem(text)
    {
        this->titleFlag = true;
        this->depth = 0;
    }

    UITreeViewItem::UITreeViewItem(const QString &text, UITreeViewItem *item) : QStandardItem(text)
    {
        this->titleFlag = true;
        this->depth = item->depth + 1;
    }

    UITreeViewItem::UITreeViewItem(UIBase *base) : QStandardItem(base->getDisplayName())
    {
        this->titleFlag = false;
        this->base = base;
        this->depth = -1;
    }

    UITreeViewItem::~UITreeViewItem()
    {

    }

    UIBase *UITreeViewItem::getBase() const
    {
        return this->base;
    }

    int UITreeViewItem::getDepth() const
    {
        return this->depth;
    }

};