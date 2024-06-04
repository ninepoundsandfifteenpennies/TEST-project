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
	void show_info();
	int search_by_id(int id);//通过id判断是否存在该职工（删除职工的时候需要用到）
	int search_by_name(string name);//通过姓名
	void delete_emp();
	void modifi_emp();
	void find_emp();
	void sort_emp();//通过编号升序排序
	void clearfile();
}; 