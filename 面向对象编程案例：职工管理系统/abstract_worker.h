#pragma once
#include<string>
#include<iostream>
using namespace std;
//职工属性：职工编号，职工姓名，职工所在部门编号（部门编号目前默认从上往下为1，2，3）
//职工行为：岗位职责信息描述（即员工，老板，经理3种人的职责），获取岗位名称

class worker
{
public:
	virtual void show_info() = 0;//显示个人信息
	virtual string get_department_name() = 0;//获取岗位名称

	int m_id;//自身编号
	string m_name;//名字
	int m_department_id;//部门编号
};