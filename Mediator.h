#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person;
//抽象中介机构;
class Mediator
{
public:
	virtual void Send(string message, Person *person) {}
	virtual void SetA(Person *A) {}  //设置其中一方
	virtual void SetB(Person *B) {}
};

//抽象对象
class Person
{
protected:
	Mediator *m_mediator; //中介
public:
	virtual void SetMediator(Mediator *mediator) {} //设置中介
	virtual void Sendmessage(string message) {}    //向中介发送信息
	virtual void Getmessage(string message) {}     //从中介获取信息
};

//房屋中介
class HouseMediator : public Mediator
{
private:
	Person *m_A; //租房者
	Person *m_B; //房东
public:
	HouseMediator() : m_A(nullptr), m_B(nullptr) {}
	void SetA(Person *A) { m_A = A; }
	void SetB(Person *B) { m_B = B; }
	void Send(string message, Person *person)
	{
		if (person == m_A) //租房者给房东发信息
			m_B->Getmessage(message); //房东收到信息
		else
			m_A->Getmessage(message);
	}
};

//租房者
class Renter : public Person
{
public:
	void SetMediator(Mediator *mediator) { m_mediator = mediator; }
	void Sendmessage(string message) { m_mediator->Send(message, this); }	//向中介发消息
	void Getmessage(string message) { cout << "租房者收到信息:  " << message; }
};

//房东
class Landlord : public Person
{
public:
	void SetMediator(Mediator *mediator) { m_mediator = mediator; }
	void Sendmessage(string message) { m_mediator->Send(message, this); }
	void Getmessage(string message) { cout << "房东收到信息： " << message; }
};



