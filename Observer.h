#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

//观察者的抽象类
class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {}
};


//博客观察的主题类
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


//具体的主题类
class BlogCSDN :public Blog
{
public:
	BlogCSDN(string name) :m_blogname(name) {}
	~BlogCSDN() {}
	string get() { return m_blogname; }
protected:
private:
	string m_blogname;//博客名
};

//具体的观察者
class ObserverBlog : public Observer
{
public:
	ObserverBlog(string name, BlogCSDN *blog) : m_name(name), m_blogcsdn(blog) {}
	~ObserverBlog() {}
	void Update()  //获得更新状态
	{
		m_status = m_blogcsdn->get()+"已更新";
		cout << "观察者：" << m_name << "关注的博客" << m_status << endl;
	}
	

private:
	string m_name;
	BlogCSDN* m_blogcsdn;
	string m_status;

};