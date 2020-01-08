#include "nonlin_equ.h"

int is_zero(double elem)
{
	if (fabs(elem) <= eps)
		return 1;
	return 0;
}

vector<double> val_table(double a, double b, int n)
{
	vector<double> res_table(n + 1);
	for (int i = 0; i < n + 1; i++)
	{
		res_table[i] = a + i * (b - a) / n;
		// cout << res_table[i] << "  ";
	}
	// cout << endl;
	return res_table;
}

int local(double a, double b, fun f)
{
	if (f(a) * f(b) <= 0)
		return 1;
	return 0;
}

double hord(double a, double b, fun f)
{
	return (f(a) * b - f(b) * a) / (f(a) - f(b));
}

vector<double> bi_method(double a_, double b_, fun f)
{
	vector<double> res(0), iter(0);
	vector<double> local_seg = val_table(a_, b_, N);
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (local(local_seg[i], local_seg[i + 1], f))
		{
			iter.resize(k);
			iter.push_back(0);
			res.resize(k);
			double a = local_seg[i], b = local_seg[i + 1];
			double x = (a + b) / 2;
			while (fabs(b - a) > 2 * eps)
			{
				if (local(a, x, f))
					b = x;
				else if (local(x, b, f))
					a = x;
				x = (a + b) / 2;
				if (is_zero(x))
					x = 0.;
				iter[k]++;
			}
			res.push_back(x);
			k++;
		}
	}
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << "x[" << i << "] = " << setw(8) << res[i] << ",  ";
		cout << "iter[" << i << "] = " << iter[i] << endl;
	}
	return res;
}

vector<double> tan_method(double a_, double b_, fun f, fun df)
{
	vector<double> res(0), iter(0);
	vector<double> local_seg = val_table(a_, b_, N);
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		// cout << local_seg[i] << "   " << local_seg[i + 1] << endl;
		if (local(local_seg[i], local_seg[i + 1], f))
		{
			iter.resize(k);
			iter.push_back(0);
			res.resize(k);
			double a = local_seg[i], b = local_seg[i + 1];
			double x = hord(a, b, f);
			double x1 = x + 1.;
			while (fabs(x1 - x) > eps)
			{
				x1 = x;
				x -= f(x) / df(x);
				if (is_zero(x))
					x = 0.;
				if ((x < a) || (x > b))
				{
					cout << "Out of range\n";
					return res;
				}
				iter[k]++;
			}
			res.push_back(x);
			k++;
		}
	}
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << "x[" << i << "] = " << setw(8) << res[i] << ",  ";
		cout << "iter[" << i << "] = " << iter[i] << endl;
	}
	return res;
}