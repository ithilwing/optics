#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lineofsources.h"

double A = 1;
double Ph = 100;
double Y = 0;

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

void MainWindow::on_pushButton_clicked() // кнопка
{
    LineOfSources line(A, Ph, Y);
    line.Debug();
    LineOfSources final_line(1.0, line);
    final_line.Debug();
}
