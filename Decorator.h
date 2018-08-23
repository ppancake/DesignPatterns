#pragma once
#include <iostream>
#include <string>
using namespace std;
//������������ֻ���
class Phone
{
public:
	Phone() {}
	virtual ~Phone() {}
	virtual void showDecorator() {}
private:

};

//װ����
class DecoratorPhone:public Phone
{
public:
	//Ҫͨ�����������г�ʼ��
	DecoratorPhone(Phone *phone):m_phone(phone) {}
	virtual ~DecoratorPhone() {}
	virtual void showDecorator() { m_phone->showDecorator(); }
private:
	Phone *m_phone;
};

//�����װ����
class DecaratorA:public DecoratorPhone
{
public:
	DecaratorA(Phone *phone) :DecoratorPhone(phone) {}
	~DecaratorA() {}
	virtual void showDecorator() { DecoratorPhone::showDecorator();  AddDecorate(); }
private:
	//���ӵ�װ��
	void AddDecorate() { cout << "���ӹҼ�" << endl; } 
};
class DecaratorB :public DecoratorPhone
{
public:
	DecaratorB(Phone *phone) :DecoratorPhone(phone) {}
	~DecaratorB() {}
	virtual void showDecorator() { DecoratorPhone::showDecorator();  AddDecorate(); }
private:
	//���ӵ�װ��
	void AddDecorate() { cout << "������Ĥ" << endl; }
};


//�����ֻ���
class Mi:public Phone
{
public:
	Mi(string name):phone_name(name){}
	~Mi(){}
	void showDecorator() { cout << phone_name << "��װ��:" << endl; }
private:
	string phone_name;
};


