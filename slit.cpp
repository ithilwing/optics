#include "slit.h"
#include "device.h"

Slit::Slit() {}
LineOfSources Slit::ModifyLine(LineOfSources& prevLine) {
	/*for(int i = 0; i <= 4; i++){
	params.insert ( pair<string,double> ("d",0.01) );
	}*/
	double d = 0.1;// params["d"]; расстояние между щелями
	double b = 0.05;//params["b"];  ширина щели
	double y = 0.5;//params["y"];

	LineOfSources line_to_modify(y, prevLine);
	LineOfSources newLine = line_to_modify;

	double x_0 = (1 - 2*b - d) / 2;

	for (int k = 0; k < (numberOfSources/x_0); k++) {
				newLine.sources[k].amplitude = 0;
	};
	for (int k = (numberOfSources / (x_0 + b)); k < (numberOfSources / (x_0 + b + d)); k++) {
		newLine.sources[k].amplitude = 0;
	};
	for (int k = (numberOfSources / (x_0 + 2*b + d)); k < numberOfSources; k++) {
		newLine.sources[k].amplitude = 0;
	};

	return newLine;
}