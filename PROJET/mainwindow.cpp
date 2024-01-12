#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "IJeu.h"
#include
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "You clicked ";
    QMessageBox::information(this, "Message", "You clicked", QMessageBox::Ok);
}

