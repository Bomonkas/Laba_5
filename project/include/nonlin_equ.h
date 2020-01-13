#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>
#include <vector>

#define N 100
#define eps 1e-6
#define NUM 0
typedef double(*fun) (double x);
typedef double(*f2p) (double x1, double x2);
using namespace std;

double f1(double x);	// (x - 0.1)*(x - 0.22)*(x - 0.55)*(x - 0.7)*(x - 0.75)
double f2(double x);	// sqrt(x + 1) - 1
double f3(double x);	// 35*pow(x,3)-67*pow(x,2)-3*x+3
double df1(double x);
double df2(double x);
double df3(double x);
double f_1(double x1, double x2);
double f_2(double x1, double x2);
double f_3(double x1, double x2);
double f_4(double x1, double x2);
double f_11(double x1, double x2);
double f_12(double x1, double x2);
double f_21(double x1, double x2);
double f_22(double x1, double x2);
double f_31(double x1, double x2);
double f_32(double x1, double x2);
double f_41(double x1, double x2);
double f_42(double x1, double x2);

int is_zero(double elem);

vector<double>			val_table(double a, double b, int n);
int						local(double a, double b, fun f);
double					hord(double a, double b, fun f);
vector<double>			bi_method(double a_, double b_, fun f);
vector<double>			tan_method(double a_, double b_, fun f, fun df, double x);
vector<vector<double>> 	newton_method(double x1, double x2, f2p f1, f2p f2, f2p df11, f2p df12, f2p df21, f2p df22);