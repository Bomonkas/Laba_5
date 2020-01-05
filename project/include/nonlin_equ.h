#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>
#include <vector>

#define N 23
#define eps 1e-6

typedef double(*fun) (double x);

using namespace std;

double f1(double x);	// (x - 0.1)*(x - 0.22)*(x - 0.55)*(x - 0.7)*(x - 0.75)
double f2(double x);	// sqrt(x + 1) - 1
double f3(double x);	// 35*pow(x,3)-67*pow(x,2)-3*x+3
double df1(double x);
double df2(double x);
double df3(double x);

int is_zero(double elem);

vector<double>			val_table(double a, double b, int n);
int						local(double a, double b, fun f);
double					hord(double a, double b, fun f);
vector<double>			bi_method(double a_, double b_, fun f);
vector<double>			tan_method(double a_, double b_, fun f, fun df);
vector<double>			newton_method(double a, double b, fun f, fun df);
vector<vector<double>>	newton2d_method(double a, double b, fun f, fun df); // TODO