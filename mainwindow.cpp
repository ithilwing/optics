#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lineofsources.h"
#include "lightsource.h"
#include "constants.h"
#include "device.h"
#include "grid.h"
#include "slit.h"
#include "lens.h"
#include "factory.h"
#include "vector"

using namespace std;



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

     //vector<double> _params {d, N, b, lx, y};
    LineOfSources line(A, Ph, Y);
    Factory f;
   // line.Debug();
    //Grid *grid = new Grid();
//    GridFactory* grid = new Grid;
//    SlitFactory* slit = new Slit;
 //   vector<>
  // Device* device = new Grid();
        Device* grid = f.createDevice("Grid");
        Device* slit = f.createDevice("Slit");
  //  Device* lens = new Lens();
  //  LineOfSources curr_line = lens->ModifyLine(line);
  // Device* grid = new Grid();

    LineOfSources curr_line = grid->ModifyLine(line);
    LineOfSources curr_line1 = slit->ModifyLine(curr_line);
//    LineOfSources curr_line = grid->ModifyLine(line);
   // LineOfSources final = curr_line;
   LineOfSources final(1, curr_line1);
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

void MainWindow::on_textEdit_copyAvailable(bool b)
{

}
