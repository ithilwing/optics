/* #ifndef DEVICE_H
#define DEVICE_H
#include "lineofsources.h"
#include "string.h"

using namespace std;

class Device
{
private:
    map <string, double> params;
public:
    Device();
    virtual vector <string> showParams() =0; // метод возвращает вектор
    void setParam(string name, double value); //
    virtual LineOfSources ModifyLine (LineOfSources prevLine) =0;

};

#endif // DEVICE_H */
