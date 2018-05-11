#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

double myAtan(double x, double y);

class Lightsource
{
private:
    double amplitude;
    double phase;
    double x;
    double y;
public:
    Lightsource();
    Lightsource(double _amplitude, double _phase, double _x, double _y);
    Lightsource operator+=(const Lightsource& b);
    void Debug ();
    
    double ReturnX () const;
        double ReturnAmpl() const;
        double ReturnPh() const;
};

#endif // LIGHTSOURCE_H
