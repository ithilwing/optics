#include "lightsource.h"
#include "math.h"
#include "iostream"
#include "constants.h"

using namespace std;


Lightsource::Lightsource(double _amplitude, double _phase, double _x, double _y){
    amplitude = _amplitude;
    phase = _phase;
    x = _x;
    y = _y;
}

Lightsource Lightsource::operator+=(const Lightsource& b) {
    double r = sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
    double new_phase = b.phase + 2 * pi * (r / lambda);
    double res_phase = atan((amplitude * sin(new_phase) + b.amplitude * sin(b.phase)) /
                            (amplitude * cos(new_phase) + b.amplitude*cos(b.phase)));
    double res_amplitude = amplitude*amplitude + b.amplitude*b.amplitude + 2*amplitude*b.amplitude*cos(b.phase - new_phase);
    amplitude = res_amplitude;
    phase = res_phase;
    return *this;
}

void Lightsource::Debug () {
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "ampl = " << amplitude << endl;
    cout << "phase = " << phase << endl;

}
