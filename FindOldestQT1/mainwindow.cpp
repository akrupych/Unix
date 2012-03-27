#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dirfinder.h"
#include <QFileDialog>
#include <QVBoxLayout>

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
    setCursor(Qt::WaitCursor);
    DirFinder finder;
    QString arg = ui->lineEdit->text();
    QString result = finder.the_oldest_subdir(arg);
    if (result.size() == 0)
        result = "Sorry, no subdirectories can be found";
    ui->lineEdit_2->setText(result);
    setCursor(Qt::ArrowCursor);
}

void MainWindow::on_pushButton_2_clicked()
{
    QFileDialog* dialog = new QFileDialog();
    dialog->setFileMode(QFileDialog::DirectoryOnly);
    if (dialog->exec())
        ui->lineEdit->setText(dialog->directory().path());
}
