#pragma once

#include <QDialog>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "../../core/core.h"

namespace Ui
{
    class ChainDialog;
}

namespace TCUIEdit { namespace view { namespace chaindialog
{
    class ChainDialog : public QDialog
    {
    Q_OBJECT

    public:
        explicit ChainDialog(QWidget *parent = 0);

        ~ChainDialog();

        void setLabel(const QString &text);

        QStandardItem *addItem(const QString &text, QStandardItem *parent = NULL, core::ui::Base *ui = NULL);

        void connectCheckbox(int depth = 0);

    private:
        Ui::ChainDialog *ui;
    protected:
        QStandardItemModel *m_model;

        void updateTreeChildren(QStandardItem *item, Qt::CheckState state);

        void updateTreeParents(QStandardItem *item);

    protected slots:

        void treeItemChanged(QStandardItem *item);
    };

}}}
