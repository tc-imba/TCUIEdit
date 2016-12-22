//
// Created by liu on 2016/11/29.
//

#ifndef TCUIEDIT_MAINWINDOW_H
#define TCUIEDIT_MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QTreeView>
#include <QHeaderView>
#include <QStandardItemModel>
#include "../core/UICore.h"
#include <QMultiHash>
#include "../components/property_browser/UIPropertyBrowser.h"
#include "mainview/UIMainView.h"

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

    TCUIEdit::UIMainView *mainView;

private slots:

    void treeViewClicked(const QModelIndex &index);
};

#endif //TCUIEDIT_MAINWINDOW_H
