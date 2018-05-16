#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "lineofsources.h"
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    
    std::cout << "Hello, world" << std::endl;
    
    double A = 1;
    double Ph = 1.57;
    double Y = 0;
    
    LineOfSources line(0, Ph, Y);
  //  line.sources[40] = Lightsource(A, Ph, 0.4, Y);
  //  line.sources[61] = Lightsource(A, Ph, 0.61, Y);
 //   line.Debug();
//    LineOfSources line2(1.0, line);
//    line2.Debug();
//    LineOfSources line3(2.0, line2);
//    line3.Debug();
//    LineOfSources line4(3.0, line3);
//    line4.Debug();
//    LineOfSources line5(4.0, line4);
//    line5.Debug();
//    LineOfSources line6(5.0, line5);
//    line6.Debug();
//    LineOfSources line7(6.0, line6);
//    line7.Debug();
//    LineOfSources line8(7.0, line7);
//    line8.Debug();
//    LineOfSources line9(8.0, line8);
//    line9.Debug();
//    LineOfSources line10(9.0, line9);
//    line10.Debug();
    
    LineOfSources final_line(1.0, line);
 //   final_line.Debug();
    
    
//    cout << myAtan(1, 0.5)*180/pi << endl;
//    cout << myAtan(1, 1.5)*180/pi << endl;
//    cout << myAtan(-1, 1.5)*180/pi << endl;
//    cout << myAtan(-1, 0.5)*180/pi << endl;
//    cout << myAtan(-1, -0.5)*180/pi << endl;
//    cout << myAtan(-1, -1.5)*180/pi << endl;
//    cout << myAtan(1, -1.5)*180/pi << endl;
//    cout << myAtan(1, -0.5)*180/pi << endl;

    ofstream file;
    file.open("data.txt");
    file << final_line.print();

     return a.exec();
}
