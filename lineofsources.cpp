#include "lineofsources.h"


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
        sources.push_back(Lightsource(prev_line.firstAmpl(), prev_line.firstPh(), _x, new_y));
        for (int k = 1; k < numberOfSources; k++){
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

double LineOfSources::firstAmpl() const{
    return sources[0].ReturnAmpl();
};

double LineOfSources::firstPh() const{
    return sources[0].ReturnPh();
};

