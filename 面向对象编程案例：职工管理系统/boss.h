#pragma once
#include "abstract_worker.h"
class boss :public worker
{
public:
	void show_info();
	string get_department_name();
	boss(int id, string name, int did);
};

