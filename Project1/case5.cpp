#include<iostream>
#include<cstdlib>
using namespace std;
//p70
//rand()生成的是伪随机数，连续调用rand只会生成同一个数，需要用srand(unsigned int seed)使之真正随机

int rolldice()
{
	int r1 = 1 + rand() % 6;
	int r2 = 1 + rand() % 6;
	int sum = r1 + r2;
	cout << "两次点数之和 " << r1 << "+" << r2 << "=" << sum << endl;
	return sum;
}


string judge2(int &sum,int &mypoint)
{
	string status;
	switch (sum)
	{
	case 7:
	case 11:
		status = "win";
		break;

	case 2:
	case 3:
	case 12:
		status = "lose";
		break;

	default:
		status = "playing";
		 sum = mypoint;
		 cout << "我的点数是 " << mypoint << endl;
	}

	return status;
	
}


void test05()
{
	string status;
	unsigned int seed;
	int sum, mypoint;//sum接收第一次点数，mypoint保存sum;
	cout << "输入随机数种子:" << endl;
	cin >> seed;
	srand(seed);
	sum = rolldice();
	status=judge2(sum,mypoint);
	while (status == "playing")
	{
		sum = rolldice();
		if (sum == mypoint)
		{
			status = "win";
		}
		else if (sum == 7)
		{
			status = "lose";
		}

	}
	if (status == "win")
		cout << "你赢了" << endl;
	else
		cout << "你输了" << endl;
}