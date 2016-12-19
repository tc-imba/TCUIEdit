//
// Created by liu on 16-12-18.
//

#ifndef TCUIEDIT_UIMAINTREEVIEW_H
#define TCUIEDIT_UIMAINTREEVIEW_H

#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtCore/QVector>
#include "../core/UICore.h"

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

#endif //TCUIEDIT_UIMAINTREEVIEW_H
