//
// Created by liu on 2016/12/21.
//

#include "Browser.h"

namespace TCUIEdit { namespace property_browser
{
    Browser::Browser(QWidget *parent) : QTreeView(parent)
    {
        m_model = new Model(this);
        this->setModel(m_model);
        this->header()->setStretchLastSection(true);

        this->init();
        //
    }

    Browser::~Browser()
    {
        //delete m_model;
    }

    void Browser::init()
    {
        m_propertyMap.clear();

        m_model->clear();
        m_model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Item") << QStringLiteral("Value"));

        this->header()->resizeSection(0, this->rect().width() * 0.3);
        this->header()->resizeSection(1, this->rect().width() * 0.7);
        this->header()->setSectionResizeMode(QHeaderView::Fixed);

        //qDebug() << "Frame" << this->rect().width() << this->rect().height();
    }

    bool Browser::addAlias(Item *item, const QString &alias)
    {
        if (alias.length() > 0 && !m_propertyMap.contains(alias))
        {
            m_propertyMap[alias] = item;
            return true;
        }
        return false;
    }

    Category *Browser::addCategory(const QString &text, const QString &alias)
    {
        auto category = new Category(this, text);
        m_model->appendRow(category->nameItem());
        this->addAlias(category, alias.length() > 0 ? alias : text);
        return category;
    }


}}