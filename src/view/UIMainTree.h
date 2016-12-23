//
// Created by liu on 16-12-18.
//

#pragma once

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtCore/QVector>
#include "../core/core.h"

namespace TCUIEdit
{

    class UIMainTree : public QTreeWidget
    {
    public:
        UIMainTree(QWidget *parent = Q_NULLPTR);

    protected:
        void contextMenuEvent(QContextMenuEvent *event);

        QMenu *contextMenu;
        QVector<QAction *> contextMenuActions;


    };

};


