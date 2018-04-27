//#include "mainwindow.h"
//#include <QApplication>
#include <iostream>
#include "lineofsources.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    
    std::cout << "Hello, world" << std::endl;
    
    double A = 1;
    double Ph = 1;
    double Y = 0;
    
    LineOfSources line(A, Ph, Y);
    line.Debug();
    LineOfSources line2(1.0, line);
    line2.Debug();
    LineOfSources line3(2.0, line2);
    line3.Debug();
    LineOfSources line4(3.0, line3);
    line4.Debug();
    LineOfSources line5(4.0, line4);
    line5.Debug();
    LineOfSources final_line(5.0, line5);
    final_line.Debug();
   // return a.exec();
}
