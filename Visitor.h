#pragma once
#include <iostream> 
#include <list> 
#include <string> 
using namespace std;

class Visitor;
class VStudent;
class Teacher;
//Ԫ�أ��������ߣ�,Element���ܷ���
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

//������
class Visitor
{
public:
	virtual void VisitS(VStudent*) {}
	virtual void VisitT(Teacher*) {}
};


//����Ԫ��
class VStudent : public VPerson
{
private:
	int m_grade; //�꼶
public:
	VStudent(string name, int gender, int grade) :VPerson(name, gender), m_grade(grade) {}
	virtual void Accept(Visitor* printer) //�麯��
	{
		printer->VisitS(this);
	}

	int GetGrade() { return m_grade; }
};

//����Ԫ��
class Teacher :public VPerson
{
private:
	int m_time;//����
public:
	Teacher(string name, int gender, int time) :VPerson(name, gender), m_time(time) {}
	virtual void Accept(Visitor* printer)
	{
		printer->VisitT(this);
	}
	int GetServiceTime() const { return m_time; }
};




//���������
//���������ӡ����Ԫ�ص���Ϣ��������ʾ����Ļ�ϣ����ɸ�����Ҫ��ӡ��ͬ�����ݡ�
//�����������һ�ֲ��ԣ��ɸ��ݲ�ͬ��Ҫ�����µľ�������ߣ��������޸ľ���Ԫ�أ����������ߣ���
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
		cout << " ����:" << s->GetGrade() << endl;
	}

	void VisitT(Teacher *t)
	{
		cout << "Teacher:" << endl;
		cout << " Name:" << t->GetName() << endl;
		if (t->GetGender() == 0)
			cout << " Gender:" << "female" << endl;
		else
			cout << " Gender:" << "male" << endl;
		cout << " ����:" << t->GetServiceTime() << endl;
	}
};

//����ṹ
//���Organization�Ǹ���֯����ֲ�������һ���Ŷӣ�ȥֲ��������������ʦ������ѧ����
class Organization
{
private:
	typedef list<VPerson*> CMemberList;
	CMemberList member_list;

public:

	void Add(VPerson* person) //������Ա
	{
		member_list.push_back(person);
	}


	void PrintMembers(Printer *printer) //�����Ա����
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

