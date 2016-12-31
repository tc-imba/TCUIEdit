#include "ChainDialog.h"
#include "ui_ChainDialog.h"

namespace TCUIEdit { namespace view { namespace chaindialog
{

    ChainDialog::ChainDialog(QWidget *parent) :
            QDialog(parent),
            ui(new Ui::ChainDialog)
    {
        ui->setupUi(this);
    }

    ChainDialog::~ChainDialog()
    {
        delete ui;
    }

}}}