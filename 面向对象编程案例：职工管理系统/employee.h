#pragma once
#include "abstract_worker.h"//∆’Õ®÷∞‘±
class employee :public worker
{public:
	void show_info();
	string get_department_name();
	employee(int id, string name, int did);
	
};

