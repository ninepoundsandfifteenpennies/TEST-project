#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include"abstract_worker.h"
class management
{
public:
	static void display_menu();
	void addperson();//此处演示用非链表的方式动态扩充数据
	management();
	~management();
	void save();//保存到文件
    int emp_num;//记录职工人数
	worker** emp_array;
	bool is_empty;//判断文件是否存在/是否为空
	int get_num();
	void emp_init();
};