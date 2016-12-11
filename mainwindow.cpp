//
// Created by liu on 2016/11/29.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTreeView>
#include <QStandardItemModel>
#include <QDebug>
#include <QElapsedTimer>
#include "core/base/UIBase_All.h"
#include "core/package/UIPackage.h"
#include "core/UIProject.h"

using namespace TCUIEdit;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QElapsedTimer timer;
    timer.start();

    QString str = "ui/ydwe/ui/";

    UIProject proj;

    auto uip = proj.createPackage(str);

    //UIPackage uip(&proj, str);

    uip->openFile(UIFileInput::CLASSIC_TRIG_DATA);

    //msgBox.setText(uip->readLine());
    //msgBox.exec();

    auto model = new QStandardItemModel(ui->treeView);
    //model->setHorizontalHeaderLabels(QStringList("List"));
    auto package = new QStandardItem("ydwe");
    model->appendRow(package);

    ui->treeView->setModel(model);
    ui->treeView->setHeaderHidden(true);

    while (uip->readLine() > 0)
    {
        if (uip->isBaseChanged())
        {
            auto item = new QStandardItem(UIBase::getTypeName(uip->getBaseTypeCurrent()));
            package->appendRow(item);
        }
    }

    uip->openFile(UIFileInput::CLASSIC_WE_STRINGS);
    while (uip->readLine() > 0)
    {
        //ui->textBrowser->append("1");
    }

    ui->treeView->expandToDepth(0);


    //uip->openWEString("ui/ydwe/ui/WorldEditStrings.txt");


    for (int i = 0; i < 3; i++)
    {
        auto parentItem = package->child(i);
        auto base = uip->getBase(UIBase::TYPE(i));
        for (auto it:base->getData())
        {
            auto item = new QStandardItem(it->getDisplayName());
            parentItem->appendRow(item);
        }
    }

    auto _ui = proj.matchUI("integer", UIBase::TRIGGER_TYPE);
    ui->textBrowser->append(_ui->getDisplayName());

    qDebug() << timer.elapsed();

}

MainWindow::~MainWindow()
{
    delete ui;
}
