#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    appTitle = new QLabel(this);
    appTitle->setText("Study Timer");

    startButton = new QPushButton("Start", this);
    startButton->move(100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
