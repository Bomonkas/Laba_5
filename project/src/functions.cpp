#include "nonlin_equ.h"

double f_1(double x1, double x2)
{
	return (x1 * x1 - x2 * x2 - 15);
}

double f_11(double x1, double x2)
{
	return (2 * x1);
}

double f_12(double x1, double x2)
{
	return ( -2 * x2);
}

double f_2(double x1, double x2)
{
	return (x1 * x2 + 4);
}

double f_21(double x1, double x2)
{
	return (x2);
}

double f_22(double x1, double x2)
{
	return (x1);
}

// ----------------------
// ----------------------

double f_3(double x1, double x2)
{
	return (x1 * x1 + x2 * x2 + x1 + x2 - 8);
}

double f_31(double x1, double x2)
{
	return (2 * x1 + 1);
}

double f_32(double x1, double x2)
{
	return (2 * x2 + 1);
}

double f_4(double x1, double x2)
{
	return (x1 * x1 + x2 * x2 + x1 * x2 - 7);
}

double f_41(double x1, double x2)
{
	return (2 * x1 + x2);
}

double f_42(double x1, double x2)
{
	return (2 * x2 + x1);
}

// ----------------------
// ----------------------

double f1(double x)
{
	return (x - 0.1)*(x - 0.22)*(x - 0.55)*(x - 0.7)*(x - 0.75);
}

double f2(double x)
{
	double f;
	if (x >= -1)
		f = sqrt(x + 1) - 1;
	else
		f = -1;
	return f;
}

double f3(double x)
{
	return 35*pow(x,3)-67*pow(x,2)-3*x+3;
}

double df1(double x)
{
	return 0.121495 - 1.5119*x + 5.9535*pow(x,2)- 9.28*pow(x,3) + 5*pow(x,4);
}

double df2(double x)
{
	return 1/(2*sqrt(x+1));
}

double df3(double x)
{
	return 105*x*x-134*x-3;
}