#pragma once

#include <QDialog>

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

    private:
        Ui::ChainDialog *ui;
    };

}}}
