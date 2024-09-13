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

    timer = new QTimer(this);
    counter = new QLCDNumber(this);
    counter->setDigitCount(8);
    counter->setGeometry(50, 50, 200, 60);  // Adjust the position and size
    counter->display("00:00:00");

    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay()
{
    secondsElapsed++;  // Increment the seconds elapsed

    // Convert seconds to hours, minutes, and seconds
    int hours = secondsElapsed / 3600;
    int minutes = (secondsElapsed % 3600) / 60;
    int seconds = secondsElapsed % 60;

    // Format the time as HH:mm:ss
    QString timeText = QString("%1:%2:%3")
                           .arg(hours, 2, 10, QChar('0'))
                           .arg(minutes, 2, 10, QChar('0'))
                           .arg(seconds, 2, 10, QChar('0'));

    // Display the formatted time
    counter->display(timeText);
}
