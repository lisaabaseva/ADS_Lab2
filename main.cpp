#include "brokenLine.h"

int main() {

	IntPoint2 intPoint, intPoint2;
	StdComplexPoint compPoint, compPoint2;

	compPoint._x = 2;
	compPoint._x = 7;

	
	intPoint._x = 2;
	intPoint._y = 4;
	intPoint2._x = 7;
	intPoint2._y = 9;

	BrokenLine<std::complex<double>> complexPoint;

	complexPoint = complexPoint + compPoint;

	BrokenLine<IntPoint2> a;
	a = intPoint + a;
	
	////DoublePoint3 doublePoint;

	BrokenLine<IntPoint2> bIntPoint;
	BrokenLine<IntPoint2> bIntPoint2;

	BrokenLine<std::complex<double>> stdPoint;

	

	//BrokenLine<DoublePoint3> bDoublePoint;
	//BrokenLine <std::complex<double>> bComplex;

	bIntPoint2 = intPoint2 + bIntPoint2;
	std::cout << bIntPoint + intPoint;

	std::cout << bIntPoint + bIntPoint2;


	std::cout << bIntPoint2.SizeLine();


	return 0;
}