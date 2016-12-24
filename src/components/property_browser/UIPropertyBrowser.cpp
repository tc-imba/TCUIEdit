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
        this->header()->resizeSection(0, this->rect().width() * 0.3);
        this->header()->resizeSection(1, this->rect().width() * 0.7);
        this->header()->setSectionResizeMode(QHeaderView::Fixed);
        //qDebug() << "Frame" << this->rect().width() << this->rect().height();
    }

    UIPropertyBrowserCategory* UIPropertyBrowser::addCategory(const QString &text)
    {
        auto category = new UIPropertyBrowserCategory(text);
        this->model->appendRow(category);
        return category;
    }


};