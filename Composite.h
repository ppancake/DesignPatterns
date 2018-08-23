#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

//公司 抽象类
class Company
{
public:
	Company(string name) { m_name = name; }
	virtual ~Company() {}
	virtual void Add(Company *pCom) {}
	virtual void Show(int depth) {}
protected:
	string m_name;
};

//具体的公司
class ConcreteCompany : public Company
{
public:
	ConcreteCompany(string name) : Company(name) {}
	virtual ~ConcreteCompany() {}
	void Add(Company *pCom) { m_listCompany.push_back(pCom); } //位于树的中间，可以增加子树
	void Show(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
		list<Company *>::iterator iter = m_listCompany.begin();
		for (; iter != m_listCompany.end(); iter++) //显示下层结点
			(*iter)->Show(depth + 2);
	}
private:
	list<Company *> m_listCompany;
};

//公司的部门：财务部
class FinanceDepartment : public Company
{
public:
	FinanceDepartment(string name) :Company(name) {}
	virtual ~FinanceDepartment() {}
	virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
	}
};
//具体的部门，人力资源部
class HRDepartment :public Company
{
public:
	HRDepartment(string name) :Company(name) {}
	virtual ~HRDepartment() {}
	virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
	{
		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << m_name << endl;
	}
};


