#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->outFileFormatBox->addItem("XML");
    ui->outFileFormatBox->addItem("HTML");
    ui->outFileFormatBox->addItem("JSON");
}

MainWindow::~MainWindow()
{
    delete ui;
}
