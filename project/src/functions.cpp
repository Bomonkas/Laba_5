#include "nonlin_equ.h"

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