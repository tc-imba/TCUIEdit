//
// Created by liu on 2016/11/29.
//

#pragma once

#include <QtWidgets/QMainWindow>
#include <QTreeView>
#include <QHeaderView>
#include <QStandardItemModel>
#include "src/core/core.h"
#include <QMultiHash>
#include "src/components/property_browser/Browser.h"
#include "src/view/mainview/MainView.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
	Ui::MainWindow *ui;
    QStandardItemModel* treeViewModel;
    QStandardItemModel* displayModel;

    TCUIEdit::mainview::MainView *mainView;

protected slots:

    void treeViewClicked(const QModelIndex &index);
};


