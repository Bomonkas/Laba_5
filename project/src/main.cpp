#include "nonlin_equ.h"

int main(int argc, char** argv)
{
	double a = 0, b = 1;
	fun f = f3, df = df3;
	cout << "bisection method:\n";
	vector<double> x_bi = bi_method(a, b, f);
	cout << "\nnewton method:\n";
	vector<double> x_tan = tan_method(a, b, f, df);
	return 0;
}