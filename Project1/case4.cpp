#include<iostream>
#include<string>
#include<cmath>
#include"test.h"
using namespace std;

//p.69


int factorial(int n)
{
	int b = 1;
	for (int i = 1; i <= n; i++)
	{
		b *= i;
	}
	return b;
}

double flag = 1e-10;
double tsin(double x)
{
	double g = 0;
	double t = x;//ГїТ»По
	int n = 1;
	do
	{
		g += t;
		n++;
		t = -t * x * x / (2 * n - 1) / (2 * n - 2);
	} while (fabs(t) >= flag);
		return g;
}

double f(double r, double s)
{
	double k;
	if (r * r <= s * s)
	{
		k = sqrt(tsin(r) * tsin(r)+tsin(s)*tsin(s));
	}
	else if (r * r > s * s)
	{
		k = 0.5 * tsin(r * s);
	}
	return k;
}





void test04()
{
	double r, s;
	cout << "r= ";
	cin >> r;
	cout << "s= "; 
	cin >> s;
	double k = f(r, s);
	cout << "k= " << k << endl;
}