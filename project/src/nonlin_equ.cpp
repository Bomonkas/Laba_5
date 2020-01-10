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

double deriv(fun f, double x)
{
	return ((f(x + 1e-11) - f(x)) / 1e-11);
}

double partial_deriv(f2p f, double x1, double x2, int num)
{
	if (num == 1)
		return ((f(x1 + 1e-11, x2) - f(x1, x2)) / 1e-11);
	else
		return ((f(x1, x2 + 1e-11) - f(x1, x2)) / 1e-11);
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

vector<double> tan_method(double a_, double b_, fun f, fun df, double x)
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
			double x1;
			do
			{
				x1 = x;
				if (NUM)
					x -= f(x) / deriv(f, x);
				else
					x -= f(x) / df(x);	
				if (is_zero(x))
					x = 0.;
				if ((x < a) || (x > b))
				{
					if (x1 > a && x1 < b)
					{
						if (local(a, x1, f))
							x = hord(a, x1, f);
						else if (local(x1, b, f))
							x = hord(x1, b, f);
					}
					else
						x = hord(a, b, f);
				}
				iter[k]++;
				if (iter[k] > 100)
				{
					cout << "looping occurred" << endl;
					break ;
				}
			} while (fabs(x1 - x) > eps);
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

void		print_vvec(vector<vector<double>> res)
{
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << "( x  y ) = (";
		for (size_t j = 0; j < res[i].size(); j++)
		{
			cout << " " << res[i][j] << " ";
		}
		cout << ")\n";
	}
}

vector<vector<double>> inv_yacoby(double x1, double x2, f2p f1, f2p f2, f2p df11, f2p df12, f2p df21, f2p df22)
{
	vector<vector<double>> y(2);

	y[0].resize(2);
	y[1].resize(2);
	if (NUM)
	{
		y[0][0] = partial_deriv(f1, x1, x2, 1);
		y[0][1] = partial_deriv(f1, x1, x2, 0);
		y[1][0] = partial_deriv(f2, x1, x2, 1);
		y[1][1] = partial_deriv(f2, x1, x2, 0);
	}
	else
	{
		y[0][0] = df11(x1, x2);
		y[0][1] = df12(x1, x2);
		y[1][0] = df21(x1, x2);
		y[1][1] = df22(x1, x2);
	}
	double det = y[0][0] * y[1][1] - y[0][1] * y[1][0];
	double tmp = y[0][0] / det;
	y[0][0] = y[1][1] / det;
	y[1][1] = tmp;
	y[1][0] = -y[1][0] / det;
	y[0][1] = -y[0][1] / det;
	return (y);
}

double norm_inf_v(vector<double> vec)
{
	double max = fabs(vec[0]);

	for (size_t i = 1; i < vec.size(); i++)
		if (max < fabs(vec[i]))
			max = fabs(vec[i]);
	return (max);
}

int		local2d(double a1, double b1, double a2, double b2, f2p f1, f2p f2)
{
	if (f1(a1, b1) * f1(a2, b2) < 0 && f2(a1, b1) * f2(a2, b2) < 0)
		return (1);
	return (0);
}

vector<vector<double>> newton_method(double r1, double r2, f2p f1, f2p f2, f2p df11, f2p df12, f2p df21, f2p df22)
{
	vector<vector<double>> res;
	vector<vector<double>> Y;
	vector<vector<double>> tabl (2, vector<double> (N + 1));
	vector<double> x(2), iter(0);
	vector<double> x1(2), v(2);
	
	tabl[0] = val_table(-r1, r1, N);
	tabl[1] = val_table(-r2, r2, N);
	int k = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (local2d(tabl[0][i], tabl[1][j], tabl[0][i + 1], tabl[1][j + 1], f1, f2))
			{
				iter.resize(k);
				iter.push_back(0);
				// cout << tabl[0][i] << "   " << tabl[0][i + 1] << endl;
				// cout << tabl[1][j] << "   " << tabl[1][j + 1] << endl << endl;;
				x = {(tabl[0][i] + tabl[0][i + 1]) / 2, (tabl[1][j] + tabl[1][j + 1]) / 2};
				do
				{
					Y = inv_yacoby(x[0], x[1], f1, f2, df11, df12, df21, df22);
					x1[0] = x[0] - (Y[0][0] * f1(x[0], x[1]) + Y[0][1] * f2(x[0], x[1]));
					x1[1] = x[1] - (Y[1][0] * f1(x[0], x[1]) + Y[1][1] * f2(x[0], x[1]));
					v[0] = f1(x1[0], x1[1]);
					v[1] = f2(x1[0], x1[1]);
					x = x1;
					iter[k]++;
				} while (norm_inf_v(v) > eps);
				res.resize(k, vector<double>(2));
				res.push_back(x);
				k++;
				i++;
			}
		}
	}
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << "( x  y ) = (";
		for (size_t j = 0; j < res[i].size(); j++)
		{
			cout << " " << res[i][j] << " ";
		}
		cout << ")" << ", iter = " << iter[i] << endl;
	}
	return (res);
}