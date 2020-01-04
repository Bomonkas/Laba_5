#include "nonlin_equ.h"

int main(int argc, char** argv)
{
	double a = 0, b = 1;
	vector<double> x = bi_method(a, b);
	return 0;
}