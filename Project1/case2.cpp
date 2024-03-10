#include<iostream>
#include<string>
using namespace std;

//编写函数求pi(67)


double power(double a, int b)
{
	while (b--)
	{
		a /= 10;
	}
	return a;
}

double power2(double x, int n)
{
	double val = 1.0;
	while (n--)
	{
		val *= x;
	}
	return val;
}

double calclulate_arctan(double x)
 {
	double flag, result = 0;
	flag = power(1.0, 15);
	double i = x;
	int n = 1;
	while (i/n >= flag)
	{
		double f = i / n;
		if ((n + 1) % 4 == 0)//负号
		{
			result -= f;
		}
		else if ((n + 1) % 4 != 0)
		{
			result += f;
		}
		n =n+2;
		i = power2(x, n);

	}


		return  result;
	}

double calculate_pi()
{
	double x = 1 / 5.0;
	double y = 1/239.0;
	double b= 16 * calclulate_arctan(x) - 4 * calclulate_arctan(y);
	return b;
}

void test02()
{
	double b = calculate_pi();
	cout << "pi的值为" << b << endl;
}