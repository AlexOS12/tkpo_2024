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

MainWindow::MainWindow(Controller *controller, Model *model, QWidget *parent)
    : MainWindow(parent)
{
    this->model = model;
    this->controller = controller;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_convertBtn_clicked()
{
    std::string text = ui->inFileText->toPlainText().toStdString();
    Builder* builder;

    qDebug() << ui->outFileFormatBox->currentIndex();

    switch (ui->outFileFormatBox->currentIndex()) {
    case 0:
        controller->CreateXML(text);
        break;
    case 1:
        controller->CreateHTML(text);
        break;
    case 2:
        controller->CreateJSON(text);
        break;
    default:
        ui->outFileText->setPlainText("No such type");
        return;
    }
}

void MainWindow::update() {
    ui->outFileText->setPlainText(QString::fromStdString(model->getContent()));
    if (model->chechHash()) {
        ui->hashStatusLabel->setText("Хэш верен");
    } else {
        ui->hashStatusLabel->setText("Хэш неверен");
    }
}
