#include "employee.h"
using namespace std;
//构造函数初始化信息
employee::employee(int id, string name, int did)
{
	this->m_id = id;
	this->m_name = name;
	this->m_department_id = did;
}

void employee::show_info()
{
	cout << "\t职工姓名：" << this->m_name << endl;
	cout << "\t职工编号: " << this->m_id << endl;
	cout << "\t岗位编号: " << this->m_department_id << endl;
	cout << "\t岗位职责: 完成经理布置的任务" << endl;
}

string employee::get_department_name()
{
	return string("普通职工");
}

