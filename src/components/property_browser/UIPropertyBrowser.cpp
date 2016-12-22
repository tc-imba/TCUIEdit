//
// Created by liu on 2016/12/21.
//

#include "UIPropertyBrowser.h"

namespace TCUIEdit
{
    UIPropertyBrowser::UIPropertyBrowser(QWidget *parent) : QTreeView(parent)
    {
        this->model = new UIPropertyBrowserModel(this);
        this->setModel(this->model);
        this->header()->setStretchLastSection(true);

        this->init();
        //
    }

    UIPropertyBrowser::~UIPropertyBrowser()
    {
        delete this->model;
    }

    void UIPropertyBrowser::init()
    {
        this->model->clear();
        this->model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));
        //this->header()->setStretchLastSection(true);
        //this->header()->setSectionResizeMode(QHeaderView::Fixed);
        this->header()->resizeSection(0, this->rect().width() * 0.4);
        qDebug() << "Frame" << this->header()->frameWidth() << this->header()->geometry().height();
    }

    void UIPropertyBrowser::addCategory(const QString &text)
    {
        auto category = new UIPropertyBrowserCategory(text);
        auto category_2 = new UIPropertyBrowserCategory(text);
        auto row = QList<QStandardItem *>() << category << category_2;
        this->model->appendRow(row);

    }


};