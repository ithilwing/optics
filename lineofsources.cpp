#include "lineofsources.h"
#include <math.h>
#include <stdio.h>


LineOfSources::LineOfSources()
{

}
LineOfSources::LineOfSources( double _amplitude, double _phase, double _y){
    for(int i = 0; i < numberOfSources; i ++){
        double _x = min_x + i * ( (max_x-min_x) / (numberOfSources - 1));
        sources.push_back(Lightsource(_amplitude, _phase, _x, _y));
    }
}
LineOfSources::LineOfSources(double new_y, const LineOfSources& prev_line){
    for(int i = 0; i < numberOfSources; i ++){
        double _x = min_x + i * ( (max_x-min_x) / (numberOfSources - 1));
        sources.push_back(Lightsource(0, 0, _x, new_y));
        for (int k = 0; k < numberOfSources; k++){
           sources[i] += prev_line.sources[k];
        }
        

    }
}

void LineOfSources::Debug () {
    
    for (int i = 0; i < numberOfSources; i ++) {
        sources[i].Debug();
    }
    cout << "----------------------------------------" << endl;
}

string LineOfSources::print()
{
    string result;
    for (int i = 0; i < numberOfSources; i++)
    {
        string _ampl;
        string _x;
        double a = sources[i].returnAmpl();
        double b = sources[i].returnX();
        result += std::to_string(a) + "," + std::to_string(b) + "\n";
    }
    return result;
};


