#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lineofsources.h"
#include "lightsource.h"
#include "constants.h"
#include "device.h"
#include "grid.h"
#include "slit.h"

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

vector<Device*> devices;

void MainWindow::on_pushButton_clicked() // кнопка
{
    LineOfSources line(A, Ph, Y);
   // line.Debug();
    //Grid *grid = new Grid();
  //  Device* device = new Grid();
    Device* device = new Slit();
    LineOfSources curr_line = device->ModifyLine(line);
   // LineOfSources final = curr_line;
   LineOfSources final(1, curr_line);
    //LineOfSources final = curr_line;

  //  final.Debug();
      std::cout << final.MaxAmpl() << std::endl;

    QVector<double> x(numberOfSources), y(numberOfSources);
    for (int i=0; i<numberOfSources; i++)
    {

      x[i] = final.Graph(i).first;
      y[i] = final.Graph(i).second * final.Graph(i).second;
    }
    // создаем график и добавляем данные:
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
   // ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  //  ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 3));
    // задаем имена осей координат
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // задаем размеры осей
    ui->widget->xAxis->setRange(min_x, max_x);
    ui->widget->yAxis->setRange(0, 1);
//     ui->widget->yAxis->setRange(0, 100000);
    ui->widget->replot();
}
