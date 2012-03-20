#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dirfinder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty()) return;
    ui->label_2->setText("Working...");
    DirFinder finder;
    string arg = ui->lineEdit->text().toStdString();
    string result = finder.the_oldest_subdir(arg);
    if (result.empty()) result = "Sorry, no subdirectories can be found";
    ui->lineEdit_2->setText(QString::fromStdString(result));
    ui->label_2->setText("Ready");
}
