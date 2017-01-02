//
// Created by liu on 2016/12/21.
//

#include "Browser.h"
#include "ItemDelegate.h"

namespace TCUIEdit { namespace property_browser
{
    Browser::Browser(QWidget *parent) : QTreeView(parent)
    {
        m_model = new Model(this);
        this->setModel(m_model);
        this->header()->setStretchLastSection(true);

        this->setItemDelegate(new ItemDelegate(this));

        this->init();
        //
    }

    Browser::~Browser()
    {
        //delete m_model;
    }

    Model* Browser::model()
    {
        return m_model;
    }

    void Browser::init()
    {
        m_propertyMap.clear();

        m_model->clear();
        m_model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("Row") << QStringLiteral("Value"));

        this->header()->resizeSection(0, this->rect().width() * 0.3);
        this->header()->resizeSection(1, this->rect().width() * 0.7);
        this->header()->setSectionResizeMode(QHeaderView::Fixed);


        //qDebug() << "Frame" << this->rect().width() << this->rect().height();
    }

    bool Browser::addAlias(Row *item, const QString &alias)
    {
        if (alias.length() > 0 && !m_propertyMap.contains(alias))
        {
            m_propertyMap[alias] = item;
            item->m_alias = alias;
            return true;
        }
        return false;
    }

    Row *Browser::aliasRow(const QString &alias)
    {
        if (m_propertyMap.contains(alias))return m_propertyMap[alias];
        return NULL;
    }

    Category *Browser::addCategory(const QString &text, const QString &alias)
    {
        auto category = new Category(this, text);
        m_model->appendRow(category->formRow());
        this->addAlias(category, alias.length() > 0 ? alias : text);
        return category;
    }


    void Browser::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
    {
        auto item = (Item *) m_model->itemFromIndex(topLeft);
        item->row()->emitEditSignal();
        /*item = (Item *) m_model->itemFromIndex(bottomRight);
        item->row()->emitEditSignal();
        qDebug() << roles;*/
    }

    void Browser::contextMenuEvent(QContextMenuEvent *event)
    {
        auto item = (Item *) m_model->itemFromIndex(this->currentIndex());
        auto row = item ? item->row() : NULL;
        emit this->rightClicked(row);
        event->accept();
    }

}}