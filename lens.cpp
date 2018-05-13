#include "lens.h"
#include "device.h"

Lens::Lens() {}
LineOfSources Lens::ModifyLine(LineOfSources& prevLine) {
	/*for(int i = 0; i <= 4; i++){
	params.insert ( pair<string,double> ("d",0.01) );
	}*/
	double f = 0.1;// params["d"]; �������� ���������
//	double y = 10;//params["y"];


	LineOfSources newLine = prevLine;

	double R = f * 0.5; // ������ ��������
	double x_0 = max_x - min_x;


	for (int k = 0; k < numberOfSources; k++) {
			double b = sqrt(4 * R*R - x_0*x_0 + 4 * x_0*newLine.sources[k].x - 4 * newLine.sources[k].x*newLine.sources[k].x);
			newLine.sources[k].phase += (pi * 0.5 * (b - sqrt(b*b - 4*newLine.sources[k].x*(x_0 - newLine.sources[k].x)))/lambda);

	}

	return newLine;
}