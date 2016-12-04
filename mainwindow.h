//
// Created by liu on 2016/11/29.
//

#ifndef TCUIEDIT_MAINWINDOW_H
#define TCUIEDIT_MAINWINDOW_H

#include <QtWidgets/QMainWindow>

namespace Ui {
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
};

#endif //TCUIEDIT_MAINWINDOW_H
