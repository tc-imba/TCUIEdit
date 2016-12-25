//
// Created by liu on 2016/12/21.
//

#include "Browser.h"

namespace TCUIEdit { namespace property_browser
{
    Browser::Browser(QWidget *parent) : QTreeView(parent)
    {
        this->model = new Model(this);
        this->setModel(this->model);
        this->header()->setStretchLastSection(true);

        this->init();
        //
    }

    Browser::~Browser()
    {
        delete this->model;
    }

    void Browser::init()
    {
        m_category.clear();

        this->model->clear();
        this->model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));
        this->header()->resizeSection(0, this->rect().width() * 0.3);
        this->header()->resizeSection(1, this->rect().width() * 0.7);
        this->header()->setSectionResizeMode(QHeaderView::Fixed);
        //qDebug() << "Frame" << this->rect().width() << this->rect().height();
    }

    Category *Browser::addCategory(const QString &text)
    {
        auto category = new Category(text);
        this->model->appendRow(category->nameItem());
        m_category[text] = category;
        return category;
    }


}}