#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    pushbutton = new QPushButton(this);
    pushbutton->setText("ffff");
    this->resize(800,600);
}

MainWindow::~MainWindow()
{
}

