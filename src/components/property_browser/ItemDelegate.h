//
// Created by liu on 17-1-2.
//

#pragma once

#include <QStyledItemDelegate>
#include "Browser.h"


namespace TCUIEdit { namespace property_browser
{

    class ItemDelegate : public QStyledItemDelegate
    {
    Q_OBJECT
    protected:
        Browser* m_browser;
    public:
        ItemDelegate(Browser *parent = 0);

        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    };

}}
