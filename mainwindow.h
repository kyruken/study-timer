#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QLCDNumber>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateDisplay();

private:
    Ui::MainWindow *ui;
    QPushButton *startButton;
    QLabel *appTitle;
    QTimer *timer;
    QLCDNumber *counter;

    int secondsElapsed = 0;
};
#endif // MAINWINDOW_H
