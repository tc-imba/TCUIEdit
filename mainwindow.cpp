//
// Created by liu on 2016/11/29.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include "core/UIProject.h"
#include "core/package/UIPackage.h"

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
    while (uip.readLine() > 0)
    {
        if (uip.isBaseChanged())
        {
            ui->textBrowser->append(UIBase::getTypeName(uip.getBaseTypeCurrent()));
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
