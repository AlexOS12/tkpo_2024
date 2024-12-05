#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "mvc.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT
public:
    void update() override;

    MainWindow(QWidget *parent = nullptr);
    MainWindow(Controller* controller, Model* model, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_convertBtn_clicked();

private:
    Ui::MainWindow *ui;
    Controller* controller;
    Model* model;
};

#endif // MAINWINDOW_H
