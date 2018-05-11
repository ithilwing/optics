#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lineofsources.h"
#include "lightsource.h"
#include "constants.h"

double A = 1;
double Ph = 100;
double Y = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) // нужно прописать х и A^2
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
   // line.Debug();
    LineOfSources final(1.0, line);

    final.Debug();

    QVector<double> x(numberOfSources), y(numberOfSources); // строить будем до 360 градусов
    for (int i=0; i<numberOfSources; ++i)
    {

      x[i] = final.Graph(i).first;
      y[i] = final.Graph(i).second * final.Graph(i).second; //
    }
    // создаем график и добавляем данные:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    // задаем имена осей координат
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // задаем размеры осей
    ui->widget->xAxis->setRange(0, 1);
    ui->widget->yAxis->setRange(0, 600);
    ui->widget->replot();
}
