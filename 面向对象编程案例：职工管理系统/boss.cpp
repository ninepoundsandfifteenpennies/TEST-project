#include "boss.h"

boss::boss(int id, string name,int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_department_id = did;
}

void boss::show_info()
{
	cout << "\t职工姓名：" << this->m_name << endl;
	cout << "\t职工编号: " << this->m_id << endl;
	cout << "\t岗位编号: " << this->m_department_id << endl;
	cout << "\t岗位职责: 布置任务给经理" << endl;
}

string boss::get_department_name()
{
	return string("老板");
}