#pragma once
#include <iostream>
#include <string>
using namespace std;

//抽象管理者 有一个对下家的引用,由于多态，实际是自己

class Manager
{
protected:
	Manager *m_manager;
	string m_name;
public:
	Manager(Manager *manager, string name) :m_manager(manager), m_name(name) {}
	virtual void DealWithRequest(string name, int num) {}
};

//具体管理者,经理
class CommonManger :public Manager
{
public:
	CommonManger(Manager *manager, string name):Manager(manager,name){}
	void DealWithRequest(string requestMame, int num)
	{
		if (num < 500)	//经理有权处理
		{
			cout << "经理" << m_name << "批准" << requestMame << "加薪" << num << "元" << endl;
		}
		else
		{
			cout << "经理" << m_name << "无法处理，交由总监处理" << endl;
			m_manager->DealWithRequest(requestMame, num);

		}
	}

};


//总监
class Majordomo : public Manager
{
public:
	Majordomo(Manager *manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		if (num < 1000) //总监职权之内
		{
			cout << "总监" << m_name << "批准" << name << "加薪" << num << "元" << endl << endl;
		}
		else
		{
			cout << "总监" << m_name << "无法处理，交由总经理处理" << endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};


//总经理
class GeneralManager : public Manager
{
public:
	GeneralManager(Manager *manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)  //总经理可以处理所有请求
	{
		cout << "总经理" << m_name << "批准" << name << "加薪" << num << "元" << endl << endl;
	}
};