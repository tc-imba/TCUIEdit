//
// Created by liu on 2016/11/29.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QElapsedTimer>
//#include "../core/ui/UIBase_All.h"
#include "../core/package/Package.h"
#include "src/core/Project.h"
#include "UITreeViewItem.h"

using namespace TCUIEdit;
using namespace TCUIEdit::core;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //qDebug() << this->ui->mainView->rect().width() << this->ui->mainView->rect().height();

    this->ui->mainView->init();

    QElapsedTimer timer;
    timer.start();

    QString str = "ui/ydwe/ui/";

    Project *proj = new Project();

    auto uip = proj->createPackage(str, "ydwe");

    //Package uip(&proj, str);

    uip->openFile(FileInput::CLASSIC_TRIG_DATA);

    //msgBox.setText(uip->readLine());
    //msgBox.exec();

    auto model = new QStandardItemModel(ui->treeView);
    this->treeViewModel = model;
    //model->setHorizontalHeaderLabels(QStringList("List"));
    auto package = new QStandardItem(uip->name());
    model->appendRow(package);

    ui->treeView->setModel(model);
    ui->treeView->setHeaderHidden(true);

    while (uip->readLine() > 0)
    {
        if (uip->isBaseChanged())
        {
            auto item = new UITreeViewItem(ui::Base::typeName(uip->baseTypeCurrent()));
            item->setEditable(false);
            package->appendRow(item);
        }
    }

    uip->openFile(FileInput::CLASSIC_WE_STRINGS);
    while (uip->readLine() > 0)
    {
        //ui->textBrowser->append("1");
    }

    ui->treeView->expandToDepth(0);


    //uip->openWEString("ui/ydwe/ui/WorldEditStrings.txt");


    for (int i = 0; i < 8; i++)
    {
        auto parentItem = package->child(i);
        auto base = uip->base(ui::Base::TYPE(i));
        for (auto it:base->data())
        {
            auto item = new UITreeViewItem(it);
            item->setEditable(false);
            parentItem->appendRow(item);
        }
    }

    auto _ui = proj->matchUI("integer", ui::Base::TRIGGER_TYPE);
    ui->textBrowser->append(_ui->formDisplay());

    //ui->treeView_2->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //model = new QStandardItemModel(ui->treeView_2);
    //this->displayModel = model;
    //ui->treeView_2->setModel(model);

    this->mainView = new mainview::MainView(this->ui->mainView);

    this->connect(ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(treeViewClicked(QModelIndex)));


    qDebug() << timer.elapsed();

}

void MainWindow::treeViewClicked(const QModelIndex &index)
{
    auto item = static_cast<UITreeViewItem *>(this->treeViewModel->itemFromIndex(index));

    qDebug() << item->getDepth() << item->text();


    if (item->getDepth() < 0)
    {
        auto str = item->getBase()->formDisplay();
        //qDebug() << str;
        //item->getBase()->displayDetail(this->ui->treeView_2);
        this->mainView->displayUI(item->getBase());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
