
#include "ChainDialog.h"
#include "ui_ChainDialog.h"

namespace TCUIEdit { namespace view { namespace chaindialog
{

    ChainDialog::ChainDialog(QWidget *parent) :
            QDialog(parent),
            ui(new Ui::ChainDialog)
    {
        ui->setupUi(this);
        m_model = new QStandardItemModel(this);
        ui->treeView->setModel(m_model);
        ui->treeView->setHeaderHidden(true);
        ui->label->setWordWrap(true);
    }

    ChainDialog::~ChainDialog()
    {
        delete ui;
    }

    void ChainDialog::setLabel(const QString &text)
    {
        ui->label->setText(text);
    }

    QStandardItem *ChainDialog::addItem(const QString &text, QStandardItem *parent, core::ui::Base *ui)
    {
        auto item = new QStandardItem(text);
        item->setEditable(false);
        item->setCheckable(true);
        item->setTristate(true);
        item->setData((unsigned) ui, Qt::UserRole + 1);
        parent ? parent->appendRow(item) : m_model->appendRow(item);
        return item;
    }

    void ChainDialog::connectCheckbox(int depth)
    {
        this->connect(m_model, SIGNAL(itemChanged(QStandardItem * )),
                this, SLOT(treeItemChanged(QStandardItem * )));
        ui->treeView->expandToDepth(depth);
    }

    void ChainDialog::treeItemChanged(QStandardItem *item)
    {
        if (!item)return;
        if (!item->isCheckable())return;
        auto state = item->checkState();
        if (state != Qt::PartiallyChecked)
        {
            this->updateTreeChildren(item, state);
            this->updateTreeParents(item);
        }
    }

    void ChainDialog::updateTreeChildren(QStandardItem *item, Qt::CheckState state)
    {
        for (int i = 0; i < item->rowCount(); i++)
        {
            auto child = item->child(i);
            if (!child->isCheckable())continue;
            child->setCheckState(state);
            this->updateTreeChildren(child, state);
        }
    }

    void ChainDialog::updateTreeParents(QStandardItem *item)
    {
        auto parent = item->parent();
        if (!parent)return;
        int now = 0, max = 0;
        for (int i = 0; i < parent->rowCount(); i++)
        {
            auto brother = parent->child(i);
            if (!brother->isCheckable())continue;
            max++;
            if (brother->checkState() == Qt::Checked)now++;
        }
        if (now == 0)
        {
            parent->setCheckState(Qt::Unchecked);
        }
        else if (now == max)
        {
            parent->setCheckState(Qt::Checked);
        }
        else
        {
            parent->setCheckState(Qt::PartiallyChecked);
        }
        this->updateTreeParents(parent);
    }

}}}