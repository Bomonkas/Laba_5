#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>
#include <vector>

#define eps 1e-6
#define f(x) (x - 0.1) * (x - 0.22) * (x - 0.55) * (x - 0.7) * (x - 0.75)
// 35 * x * x * x - 67 * x * x - 3 * x + 3
// sqrt(x + 1) - 1
// (x - 0.1) * (x - 0.22) * (x - 0.55) * (x - 0.7) * (x - 0.75)
#define N 11

using namespace std;

vector<double>	val_table(double a, double b, int n);
int				local(double a, double b);
vector<double>	bi_method(double a, double b);