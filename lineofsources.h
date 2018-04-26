#ifndef LINEOFSOURCES_H
#define LINEOFSOURCES_H
#include "vector"
#include "lightsource.h"
#include "constants.h"
#include "iostream"


using namespace std;

class LineOfSources
{
private:
    vector <Lightsource> sources;  //вектор из lightsource которы называется sources
public:
    LineOfSources();
    LineOfSources(double amplitude, double phase, double y);
    LineOfSources(double new_y, const LineOfSources& prev_line);
    void Debug ();
};


#endif // LINEOFSOURCES_H
