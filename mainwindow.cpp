//
// Created by liu on 2016/11/29.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeView>
#include <QStandardItemModel>
#include <QDebug>
#include "core/base/UIBase_All.h"
#include "core/package/UIPackage.h"
#include "core/UIProject.h"

using namespace TCUIEdit;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str = "ui/ydwe/ui/TriggerData.txt";

    UIProject proj;

    UIPackage uip(&proj, str);

    qDebug() << "1";
    //msgBox.setText(uip.readLine());
    //msgBox.exec();



    auto model = new QStandardItemModel(ui->treeView);
    //model->setHorizontalHeaderLabels(QStringList("List"));
    auto package = new QStandardItem("ydwe");
    model->appendRow(package);

    ui->treeView->setModel(model);
    ui->treeView->setHeaderHidden(true);

    while (uip.readLine() > 0)
    {
        if (uip.isBaseChanged())
        {
            ui->textBrowser->append(UIBase::getTypeName(uip.getBaseTypeCurrent()));
            auto item = new QStandardItem(UIBase::getTypeName(uip.getBaseTypeCurrent()));
            package->appendRow(item);
        }
    }

    ui->treeView->expandToDepth(1);

    auto parentItem = package->child(0);

    auto category = static_cast<UIPackage_Category *>(uip.getBase(UIBase::TRIGGER_CATEGORY));

    for (auto it:category->getData())
    {
        auto item = new QStandardItem(it->getDisplayName());
        parentItem->appendRow(item);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
