#include "slit.h"
#include "device.h"

Slit::Slit() {}
LineOfSources Slit::ModifyLine(LineOfSources& prevLine) {
	/*for(int i = 0; i <= 4; i++){
	params.insert ( pair<string,double> ("d",0.01) );
	}*/
	double d = 0.1;// params["d"]; расстояние между щелями
	double b = 0.05;//params["b"];  ширина щели
    double y = 0.52;//params["y"];

	LineOfSources line_to_modify(y, prevLine);
	LineOfSources newLine = line_to_modify;

	double x_0 = (1 - 2*b - d) / 2;

        std::cout << x_0 << std::endl;
            std::cout << x_0 / dSources << std::endl;
            std::cout << dSources / (x_0 + b) << std::endl;
            std::cout << dSources / (x_0 + b + d) << std::endl;



    for (int k = 0; k < (int)( x_0 / dSources); k++) {
                newLine.sources[k].amplitude = 0;
    };
    for (int k = (int)( (x_0 + b)/dSources); k < (int)((x_0 + b + d)/dSources); k++) {
        newLine.sources[k].amplitude = 0;
    };
    for (int k = (int)((x_0 + 2*b + d)/dSources); k < numberOfSources; k++) {
        newLine.sources[k].amplitude = 0;
    };



	return newLine;
}
