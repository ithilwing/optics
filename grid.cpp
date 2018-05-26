#include "grid.h"
#include "device.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QString>


Grid::Grid(){}


LineOfSources Grid::ModifyLine ( LineOfSources& prevLine  ) {

    char grid_params[50];
        ifstream fin("grid.txt");
        fin.getline(grid_params, 50);
        fin.close();
        cout << grid_params << endl;

    /*double d;
    double N;
    double b;
    double lx;
    double y;*/
   // std::cout << "vvedite d, N, b, lx, y" << std::endl;
    //std::cin >> d >> N >> b >> lx >> y;

    /*for(int i = 0; i <= 4; i++){
        params.insert ( pair<string,double> ("d",0.01) );
    }*/
    double d = 0.1;// params["d"];
    double N = 10;//params["N"];
    double b = 0.05;//params["b"];
    double lx = 0;//params["lx"];
    double y = 0.5; // координата по y*/

	LineOfSources line_to_modify(y, prevLine);
	LineOfSources newLine = line_to_modify;

    for(int k = 0; k < numberOfSources; k ++){
        for (int i = 0; i < N; i++){
            if (lx + i*d <= newLine.sources[k].x && lx + b + i*d >= newLine.sources[k].x ){
                newLine.sources[k].amplitude = 0;
            }
        }
    }

    return newLine;
}
// LineOfSources ModifyLine (LineOfSources prevLine){
        /* вычисляем на уровне Y значение теущей линии источников; потом ищем расстояние между источниками l; цикл из N итераций внутри него (d-b)/l
         * раз зануляем амлитуду и b/l раз ничего не трогаем. Все начинаем с X и считаем что решетка начинается с темной полосы*/
