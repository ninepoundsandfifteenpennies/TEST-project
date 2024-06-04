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
			m.show_info();
			break;

		case 3:
			m.delete_emp();
			break;

		case 4:
			m.modifi_emp();
			break;

		case 5:
			m.find_emp();
			break;

		case 6:
			m.sort_emp();
			break;

		case 7:
			m.clearfile();
			break;


		default:
			system("cls");
		}

	}

	m.addperson();

	return 0;
}