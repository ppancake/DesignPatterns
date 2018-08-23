#pragma once
#include <iostream> 
#include <list> 
#include <string> 
using namespace std;

class Visitor;
class VStudent;
class Teacher;
//元素（被访问者）,Element接受访问
class VPerson
{
private:
	string m_name;
	int m_gender;
public:
	virtual void Accept(Visitor*){}
	VPerson(string name,int gender):m_name(name), m_gender(gender){}
	string GetName()  {return m_name;}
	int GetGender() {return m_gender;}
};

//访问者
class Visitor
{
public:
	virtual void VisitS(VStudent*) {}
	virtual void VisitT(Teacher*) {}
};


//具体元素
class VStudent : public VPerson
{
private:
	int m_grade; //年级
public:
	VStudent(string name, int gender, int grade) :VPerson(name, gender), m_grade(grade) {}
	virtual void Accept(Visitor* printer) //虚函数
	{
		printer->VisitS(this);
	}

	int GetGrade() { return m_grade; }
};

//具体元素
class Teacher :public VPerson
{
private:
	int m_time;//工龄
public:
	Teacher(string name, int gender, int time) :VPerson(name, gender), m_time(time) {}
	virtual void Accept(Visitor* printer)
	{
		printer->VisitT(this);
	}
	int GetServiceTime() const { return m_time; }
};




//具体访问者
//这里，这个类打印具体元素的信息（就是显示在屏幕上），可根据需要打印不同的内容。
//具体访问者是一种策略，可根据不同需要创建新的具体访问者，而无需修改具体元素（即被访问者）。
class Printer : public Visitor
{
public:
	void VisitS(VStudent *s)
	{
		cout << "VStudent:" << endl;
		cout << " Name:" << s->GetName() << endl;
		if (s->GetGender() == 0)
			cout << " Gender:" << "female" << endl;
		else
			cout << " Gender:" << "male" << endl;
		cout << " 分数:" << s->GetGrade() << endl;
	}

	void VisitT(Teacher *t)
	{
		cout << "Teacher:" << endl;
		cout << " Name:" << t->GetName() << endl;
		if (t->GetGender() == 0)
			cout << " Gender:" << "female" << endl;
		else
			cout << " Gender:" << "male" << endl;
		cout << " 工龄:" << t->GetServiceTime() << endl;
	}
};

//对象结构
//这里，Organization是个组织（如植树节组成一个团队，去植树），有若干老师，若干学生。
class Organization
{
private:
	typedef list<VPerson*> CMemberList;
	CMemberList member_list;

public:

	void Add(VPerson* person) //增加人员
	{
		member_list.push_back(person);
	}


	void PrintMembers(Printer *printer) //输出成员名单
	{
		CMemberList::iterator itr = member_list.begin();
		for (; itr != member_list.end(); ++itr)
		{
			(*itr)->Accept(printer);
		}
	}

	~Organization()
	{
		CMemberList::iterator itr = member_list.begin();
		for (; itr != member_list.end(); ++itr)
		{
			delete *itr;
		}
	}
};

