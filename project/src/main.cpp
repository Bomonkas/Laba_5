#include "nonlin_equ.h"

int main(int argc, char** argv)
{
	double a = 0, b = 1;
	fun f = f3, df = df3;
	// f2p g1 = f_3, g2 = f_4, g11 = f_31, g12 = f_32, g21 = f_41, g22 = f_42;
	f2p g1 = f_3, g2 = f_4, g11 = f_31, g12 = f_32, g21 = f_41, g22 = f_42;

	// cout << "bisection method:\n";
	// vector<double> x_bi = bi_method(a, b, f);
	// cout << "\nnewton method:\n";
	// vector<double> x_tan = tan_method(a, b, f, df, 0); // hord(a, b, f)
	cout << "\nnewton method for 2d system:\n";
	newton_method(10, 10, g1, g2, g11, g12, g21, g22); 
	return 0;
}