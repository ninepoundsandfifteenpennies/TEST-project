#include<iostream>
#include<string>
//(p.68)
using namespace std;
int judge(unsigned m)
{
	int k = m;
	int n;//接收末位
	int c=0;//接收回文数
	while (m > 0)
	{
		n = m % 10;
		c = 10 * c + n;
		m /= 10;
	}
	if (c == k)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void test03()
{
	unsigned m = 11;
	for (m = 11; m < 1000; m++)
	{
		int a = judge(m);
		int b = judge(m * m);
		int c = judge(m * m * m);
		if (a && b && c)
		{
			cout << "m= " << m << "    m * m = " << m * m << "   m*m*m= " << m * m * m << endl;
		}
	}
}