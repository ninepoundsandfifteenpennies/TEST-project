#include"management.h"

using namespace std;
int status;
management m;


int main()
{
    while (1)
	{
		management::display_menu();
		cin >> status;
		switch (status)
		{
		case 0:
			exit (0);

		case 1:
			m.addperson();
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;


		default:
			system("cls");
		}

	}

	m.addperson();

	return 0;
}