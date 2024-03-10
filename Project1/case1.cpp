#include<iostream>
#include<string>

using namespace std;

void test01()//输出ascii码32~127对应的字符
{

	char c;
	for (int i = 32; i <= 127; i++)
	{
		c = i;
		cout << c << endl;
	}

}

