#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

//�۲��ߵĳ�����
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {}
};


//���͹۲��������
class Blog
{
public:
	Blog() {}
	virtual ~Blog() {}
	void Attach(Observer *ob) { m_obList.push_back(ob); }
	void Detach(Observer *ob) { m_obList.remove(ob); }
	void Notify()
	{
		list<Observer*>::iterator it = m_obList.begin();
		for (; it != m_obList.end(); it++)
			(*it)->Update();
	}
	virtual string get() { return m_blog; }
protected:
	string m_blog;
private:
	list<Observer*>m_obList;
};


//�����������
class BlogCSDN :public Blog
{
public:
	BlogCSDN(string name) :m_blogname(name) {}
	~BlogCSDN() {}
	string get() { return m_blogname; }
protected:
private:
	string m_blogname;//������
};

//����Ĺ۲���
class ObserverBlog : public Observer
{
public:
	ObserverBlog(string name, BlogCSDN *blog) : m_name(name), m_blogcsdn(blog) {}
	~ObserverBlog() {}
	void Update()  //��ø���״̬
	{
		m_status = m_blogcsdn->get()+"�Ѹ���";
		cout << "�۲��ߣ�" << m_name << "��ע�Ĳ���" << m_status << endl;
	}
	

private:
	string m_name;
	BlogCSDN* m_blogcsdn;
	string m_status;

};