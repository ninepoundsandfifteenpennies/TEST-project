#include"management.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#include"abstract_worker.h"
#define FILENAME "emp.txt "
using namespace std;
void management::display_menu()
{
	cout << "------------------------------------------------------------------" << endl;
	cout << "              选择你需要用的功能并输入对应数字:" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "              0.退出                                          "<<endl;
	cout << "              1.增加职工信息                                          " << endl;
	cout << "              2.显示职工信息                                          " << endl;
	cout << "              3.删除离职职工                                          " << endl;
	cout << "              4.修改职工信息                                          " << endl;
	cout << "              5.查找职工信息                                   " << endl;
	cout << "              6.按照职工编号进行排序                                          " << endl;
	cout << "              7.清空文件中记录的职工信息                                          " << endl;
	cout << "------------------------------------------------------------------" << endl;
}


int management::get_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	int did;
	string name;

	int num = 0;//记录人数
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

void management::emp_init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* w = NULL;
		if (did == 1)
		{
			w = new employee(id, name, did);
		}
		else if (did == 2)
		{
			w = new manager(id, name, did);
		}
		else
		{
			w = new boss(id, name, did);
		}
		this->emp_array[index] = w;
		index ++;
	}
	ifs.close();
}

management::management()
{   //文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->emp_array = NULL;
		this->emp_num = 0;
		is_empty = true;
		ifs.close();
		return;
	}
	//文件存在且数据为空
	char ch;
	ifs >>ch;//右移读一个字符
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->emp_array = NULL;
		this->emp_num = 0;
		is_empty = true;
		ifs.close();
		return;
	}
	//文件存在且有数据
	int num = this->get_num();
	cout << "文件中有" << num << "人" << endl;
	this->emp_num = num;
	this->emp_array = new worker * [this->emp_num];//根据已有文件初始化空间
	this->emp_init();//将文件数据储存到数组中
}


void management::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i <this-> emp_num; i++)
	{
		ofs << this->emp_array[i]->m_id << " " <<
			this->emp_array[i]->m_name << " " <<			
			this->emp_array[i]->m_department_id << endl;
	}
	ofs.close();
}


void management::addperson()
{
	int add_num = 0;
	cout << "输入加入职工的数量" << endl; out:
	cin >> add_num;
	if (add_num > 0)
	{
		int new_num = this->emp_num + add_num;//记录加入后的总人数;

		//记录添加的新空间
		worker** new_size = new worker * [new_num];//new_size是指向worker指针的指针
		//将原来空间的人放进新空间
		if (this->emp_array != NULL)
		{
			for (int i = 0; i < this->emp_num; i++)
			{
				new_size[i] = this->emp_array[i];
			}
		}
		//添加数据
		for (int i = 0; i < add_num; i++)
		{
			string name;
			int id;
			int did;

			cout << "输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;

			cout << "输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;

			cout << "输入第" << i + 1 << "个职工的岗位编号" << endl;
			cout << "1.普通职员" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl; out2:
			cin >> did;
			worker* w = NULL;//创建父类对象指针以指向子类对象实现多态
			switch (did)
			{
			case 1:
				w = new employee(id, name, did);
				break;
			case 2:
				w = new manager(id, name, did);
				break;
			case 3:
				w = new boss(id, name, did);
				break;
			default:
				cout << "输入错误，重新输入!" << endl;
				goto out2;
			}
			new_size[this->emp_num+i] = w;//将已经指向了职工对象并初始化完成的指针w存入新空间对应的位置
		}
		//删去原来的空间
		delete[]emp_array;
		//更新职工数量
		emp_num = new_num;
		this->emp_array = new_size;
		cout << "成功添加" << add_num << "名职工" << endl;
		this->save();
	}

	else
	{
		cout << "输入错误,重新输入" << endl;
		goto out;
	}
	system("pause");
	system("cls");

}

management::~management()
{
	if (this->emp_array != NULL)
	{
		delete[]this->emp_array;
		this->emp_array = NULL;
	}
}
