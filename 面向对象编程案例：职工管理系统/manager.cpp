#include "manager.h"

manager::manager(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_department_id = did;
}

void manager::show_info()
{
	cout << "\t职工姓名：" << this->m_name << endl;
	cout << "\t职工编号: " << this->m_id << endl;
	cout << "\t岗位编号: " << this->m_department_id << endl;
	cout << "\t岗位职责: 完成老板布置的任务并下发给员工" << endl;
}

string manager::get_department_name()
{
	return string("经理");
}
