/* #ifndef GRID_H
#define GRID_H
#include "device.h"

class Grid: public Device
{

public:
    Grid();
    LineOfSources ModifyLine (LineOfSources prevLine)const override;
    vector <string> showParams(){
        return {"lx", "y", "N", "d", "b"};
    }
};

#endif // GRID_H */
