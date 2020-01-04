#include "nonlin_equ.h"

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

int		local(double a, double b)
{
	double x1 = f(a);
	double x2 = f(b);
	if (x1 * x2 <= 0)
		return 0;
	return 1;
}

vector<double>	bi_method(double a_, double b_)
{
	vector<double> res(0), iter(0);
	vector<double> local_seg = val_table(a_, b_, N);
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (local(local_seg[i], local_seg[i + 1]) == 0)
		{
			iter.resize(k);
			iter.push_back(0);
			res.resize(k);
			double a = local_seg[i], b = local_seg[i + 1];
			double x = (a + b) / 2;
			while (fabs(b - a) > 2 * eps)
			{
				if (local(a, x) == 0)
					b = x;
				else if (local(x, b) == 0)
					a = x;
				x = (a + b) / 2;
				iter[k]++;
			}
			res.push_back(x);
			k++;
		}
	}
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << "x[" << i << "] = " << res[i] << ",  ";
		cout << "iter[" << i << "] = " << iter[i] << endl;
	}
	return res;
}