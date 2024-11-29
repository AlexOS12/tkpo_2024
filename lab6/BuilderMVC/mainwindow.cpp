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

void MainWindow::on_convertBtn_clicked()
{
    std::string text = ui->inFileText->toPlainText().toStdString();
    Builder* builder;

    qDebug() << ui->outFileFormatBox->currentIndex();

    switch (ui->outFileFormatBox->currentIndex()) {
    case 0:
        builder = new XMLBuilder(text);
        break;
    case 1:
        builder = new HTMLBuilder(text);
        break;
    case 2:
        builder = new JSONBuilder(text);
        break;
    default:
        ui->outFileText->setPlainText("No such type");
        return;
    }

    Director* director = new Director(builder);

    director->construct();

    Product* converted = builder->getResult();

    if (converted->checkHash())
        ui->hashStatusLabel->setText("Хеш верен");
    else
        ui->hashStatusLabel->setText("Хен неверен!");


    ui->outFileText->setPlainText(QString::fromStdString(converted->toString()));

}

