//
// Created by liu on 16-12-18.
//

#include <QtGui/QContextMenuEvent>
#include "UIMainTree.h"

namespace TCUIEdit
{

    UIMainTree::UIMainTree(QWidget *parent) : QTreeWidget(parent)
    {
        this->contextMenu = new QMenu();

        auto action = new QAction(this);
        action->setText("Target to");
        this->contextMenuActions.push_back(action);
    }

    void UIMainTree::contextMenuEvent(QContextMenuEvent *event)
    {
        qDebug() << "contextMenuEvent";

        this->contextMenu->clear();

        QPoint point = event->pos(); //得到窗口坐标
        auto item = this->itemAt(point);

        this->contextMenu->addAction(this->contextMenuActions[0]);

        this->contextMenu->exec(QCursor::pos());

        event->accept();

    }


};