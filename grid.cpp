#include "grid.h"
#include "device.h"

Grid::Grid(){}
LineOfSources Grid::ModifyLine ( LineOfSources& prevLine) {
    /*for(int i = 0; i <= 4; i++){
        params.insert ( pair<string,double> ("d",0.01) );
    }*/
    double d = 0.1;// params["d"];
    double N = 10;//params["N"];
    double b = 0.05;//params["b"];
    double lx = 0;//params["lx"];

    LineOfSources newLine = prevLine;

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
