#pragma once
#include <iostream>
#include <string>
using namespace std;
//公共抽象基类手机类
class Phone
{
public:
	Phone() {}
	virtual ~Phone() {}
	virtual void showDecorator() {}
private:

};

//装饰类
class DecoratorPhone:public Phone
{
public:
	//要通过抽象基类进行初始化
	DecoratorPhone(Phone *phone):m_phone(phone) {}
	virtual ~DecoratorPhone() {}
	virtual void showDecorator() { m_phone->showDecorator(); }
private:
	Phone *m_phone;
};

//具体的装饰类
class DecaratorA:public DecoratorPhone
{
public:
	DecaratorA(Phone *phone) :DecoratorPhone(phone) {}
	~DecaratorA() {}
	virtual void showDecorator() { DecoratorPhone::showDecorator();  AddDecorate(); }
private:
	//增加的装饰
	void AddDecorate() { cout << "增加挂件" << endl; } 
};
class DecaratorB :public DecoratorPhone
{
public:
	DecaratorB(Phone *phone) :DecoratorPhone(phone) {}
	~DecaratorB() {}
	virtual void showDecorator() { DecoratorPhone::showDecorator();  AddDecorate(); }
private:
	//增加的装饰
	void AddDecorate() { cout << "增加贴膜" << endl; }
};


//具体手机类
class Mi:public Phone
{
public:
	Mi(string name):phone_name(name){}
	~Mi(){}
	void showDecorator() { cout << phone_name << "的装饰:" << endl; }
private:
	string phone_name;
};


