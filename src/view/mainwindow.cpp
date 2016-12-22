//
// Created by liu on 2016/11/29.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QElapsedTimer>
#include "../core/base/UIBase_All.h"
#include "../core/package/UIPackage.h"
#include "../core/UIProject.h"
#include "UITreeViewItem.h"

using namespace TCUIEdit;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QElapsedTimer timer;
    timer.start();

    QString str = "ui/ydwe/ui/";

    UIProject *proj = new UIProject();

    auto uip = proj->createPackage(str, "ydwe");

    //UIPackage uip(&proj, str);

    uip->openFile(UIFileInput::CLASSIC_TRIG_DATA);

    //msgBox.setText(uip->readLine());
    //msgBox.exec();

    auto model = new QStandardItemModel(ui->treeView);
    this->treeViewModel = model;
    //model->setHorizontalHeaderLabels(QStringList("List"));
    auto package = new QStandardItem(uip->getName());
    model->appendRow(package);

    ui->treeView->setModel(model);
    ui->treeView->setHeaderHidden(true);

    while (uip->readLine() > 0)
    {
        if (uip->isBaseChanged())
        {
            auto item = new UITreeViewItem(UIBase::getTypeName(uip->getBaseTypeCurrent()));
            item->setEditable(false);
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


    for (int i = 0; i < 6; i++)
    {
        auto parentItem = package->child(i);
        auto base = uip->getBase(UIBase::TYPE(i));
        for (auto it:base->getData())
        {
            auto item = new UITreeViewItem(it);
            item->setEditable(false);
            parentItem->appendRow(item);
        }
    }

    auto _ui = proj->matchUI("integer", UIBase::TRIGGER_TYPE);
    ui->textBrowser->append(_ui->getDisplayName());

    ui->treeView_2->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    model = new QStandardItemModel(ui->treeView_2);
    this->displayModel = model;
    //ui->treeView_2->setModel(model);



    this->connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(treeViewClicked(QModelIndex)));


    qDebug() << timer.elapsed();

}

void MainWindow::treeViewClicked(const QModelIndex &index)
{
    auto item = static_cast<UITreeViewItem *>(this->treeViewModel->itemFromIndex(index));

    qDebug() << item->getDepth() << item->text();


    if (item->getDepth() < 0)
    {
        auto str = item->getBase()->getDisplayName();
        //qDebug() << str;
        item->getBase()->displayDetail(this->ui->treeView_2);
        this->ui->treeView_2->expandToDepth(0);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
