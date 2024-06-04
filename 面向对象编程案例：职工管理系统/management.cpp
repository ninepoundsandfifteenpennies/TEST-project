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


int management::search_by_id(int id)
{
	int index = -1;//如果不存在，返回-1,否则返回对应emp_array数组下标
	for (int i = 0; i < emp_num; i++)
	{
		if (id == this->emp_array[i]->m_id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int management::search_by_name(string name)
{
	int index = -1;//如果不存在，返回-1,否则返回对应emp_array数组下标
	for (int i = 0; i < emp_num; i++)
	{
		if (name == this->emp_array[i]->m_name)
		{
			index = i;
			break;
		}
	}
	return index;
}

void management::delete_emp()
{
	if (this->is_empty)
	{
		cout << "文件不存在或为空" << endl;
		system("pause");
		system("cls");
    }
	else {
		int status = 0;
		int index;
		cout << "通过姓名索引输入1，通过id索引输入2: "; out:
		cin >> status;
		if (status == 1)
		{
			string name;
			cout << "输入需要删除职员的姓名: ";
			cin >> name;
			index = this->search_by_name(name);
		}
		else if (status == 2)
		{
			int id;
			cout << "输入需要删除职员的id: ";
			cin >> id;
			index = this->search_by_id(id);
		}
		else
		{
			cout << "输入错误，重新输入!" << endl;
			goto out;
		}
		if (index == -1)
		{
			cout << "该职员不存在!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			delete this->emp_array[index];
			this->emp_array[index] = NULL;
			for (int i = index; i < this->emp_num - 1; i++)
			{
				this->emp_array[i] = this->emp_array[i + 1];
			}
			this->emp_num--;
			this->save();//把修改保存到文件
			cout << "成功删除一个职员" << endl;
			system("pause");
			system("cls");
		}
	}
}

void management::modifi_emp()
{
	if (this->is_empty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int status = 0;
		int index;
		cout << "通过姓名索引输入1，通过id索引输入2: "; out:
		cin >> status;
		if (status == 1)
		{
			string name;
			cout << "输入需要修改职员的姓名: ";
			cin >> name;
			index = this->search_by_name(name);
		}
		else if (status == 2)
		{
			int id;
			cout << "输入需要修改职员的id: ";
			cin >> id;
			index = this->search_by_id(id);
		}
		else
		{
			cout << "输入错误，重新输入!" << endl;
			goto out;
		}
		if (index == -1)
		{
			cout << "该职员不存在!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			int n_id;
			string n_name;
			int n_did;
			cout << "输入修改后的id" << endl;
			cin >> n_id;
			cout << "输入修改后的名字" << endl;
			cin >> n_name; 
			cout << "输入修改后的部门编号" << endl;
			cout << "1.普通职员" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;out2:
			cin >> n_did;
			worker* w = NULL;
			switch (n_did)
			{
			case 1:
				w = new employee(n_id, n_name, n_did);
				break;
			case 2:
				w = new manager(n_id, n_name, n_did);
				break;
			case 3:
				w = new boss(n_id, n_name, n_did);
				break;
			default:
				cout << "输入错误，重新输入!" << endl;
				goto out2;
			}
			delete this->emp_array[index];
			this->emp_array[index] = w;
			this->save();
			cout << "成功修改该职员信息" << endl;
			system("pause");
			system("cls");
		}
	}

}

void management::find_emp()
{
	if (this->is_empty)
	{
		cout << "文件不存在或者为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		int status = 0;
		int index;
		cout << "通过姓名索引输入1，通过id索引输入2: "; out:
		cin >> status;
		if (status == 1)
		{
			string name;
			cout << "需要查找职工的姓名" << endl;
			cin >> name;
			index = this->search_by_name(name);
		}
		else if (status == 2)
		{
			int id;
			cout << "需要查找职工的id ";
			cin >> id;
			index = this->search_by_id(id);
		}
		else
		{
			cout << "输入错误，重新输入" << endl;
				goto out;
		}
		if (index == -1)
		{
			cout << "查无此人" << endl;
		}
		else
		{
			cout << "查询成功，该人的信息如下:" << endl;
			this->emp_array[index]->show_info();
			system("pause");
			system("cls");
		}
	}
}
void management::show_info()
{
	if (this->is_empty)
	{
		cout << "文件为空或文件不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->emp_num; i++)
	{
		this->emp_array[i]->show_info();
	}
	system("pause");
	system("cls");
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
	if (ifs.eof())//读到的字符为eof
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
			cout << "3.老板" << endl;out2: 
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
		this->is_empty = false;
	}

	else
	{
		cout << "输入错误,重新输入" << endl;
		goto out;
	}
	system("pause");
	system("cls");

}

void management::sort_emp()
{
	if (this->is_empty)
	{
		cout << "文件为空或文件不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "升序排序选1，降序选2" << endl;
		int choice;
		cin >> choice;
		for (int i = 0; i < this->emp_num; i++)
		{
			int maxormin = i;
			for (int j = i + 1; j < this->emp_num; j++)
			{
				if (choice == 1)
				{
					if (this->emp_array[i]->m_id > this->emp_array[j]->m_id)
						maxormin = j;
				}
				else if (choice == 2)
				{
					if (this->emp_array[i]->m_id < this->emp_array[j]->m_id)
						maxormin = j;
				}
				
			}
			if (maxormin!=i)
			{
				worker* temp;
				temp = this->emp_array[i];
				this->emp_array[i] = this->emp_array[maxormin];
				this->emp_array[maxormin] =temp;
			}
		}
		this->save();
		cout << "排序成功" << endl;
		//this->show_info();
		system("pause");
		system("cls");
	}
}

void management::clearfile()
{
	cout << "确认清空？y/n" << endl;
	string choice;out:
	cin >> choice;
	if (choice == "n")
	{
		return;
	}
	else if (choice == "y")
	{
		ofstream ofs(FILENAME, ios::trunc);//如果存在删除并重建文件
		ofs.close();
		if (this->emp_array != NULL)
		{
			for (int i = 0; i < this->emp_num; i++)
			{  
				if(this->emp_array[i]!=NULL)
				delete this->emp_array[i];
			}

		}
		this->emp_num = 0;
		delete[]this->emp_array;
		this->emp_array = NULL;
		this->is_empty = true;
		cout << "清除成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入错误,重新输入" << endl;
		goto out;
	}
}
management::~management()
{
	if (this->emp_array != NULL)
	{
		delete[]this->emp_array;
		this->emp_array = NULL;
	}
}
