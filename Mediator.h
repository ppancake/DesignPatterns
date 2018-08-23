#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person;
//�����н����;
class Mediator
{
public:
	virtual void Send(string message, Person *person) {}
	virtual void SetA(Person *A) {}  //��������һ��
	virtual void SetB(Person *B) {}
};

//�������
class Person
{
protected:
	Mediator *m_mediator; //�н�
public:
	virtual void SetMediator(Mediator *mediator) {} //�����н�
	virtual void Sendmessage(string message) {}    //���н鷢����Ϣ
	virtual void Getmessage(string message) {}     //���н��ȡ��Ϣ
};

//�����н�
class HouseMediator : public Mediator
{
private:
	Person *m_A; //�ⷿ��
	Person *m_B; //����
public:
	HouseMediator() : m_A(nullptr), m_B(nullptr) {}
	void SetA(Person *A) { m_A = A; }
	void SetB(Person *B) { m_B = B; }
	void Send(string message, Person *person)
	{
		if (person == m_A) //�ⷿ�߸���������Ϣ
			m_B->Getmessage(message); //�����յ���Ϣ
		else
			m_A->Getmessage(message);
	}
};

//�ⷿ��
class Renter : public Person
{
public:
	void SetMediator(Mediator *mediator) { m_mediator = mediator; }
	void Sendmessage(string message) { m_mediator->Send(message, this); }	//���н鷢��Ϣ
	void Getmessage(string message) { cout << "�ⷿ���յ���Ϣ:  " << message; }
};

//����
class Landlord : public Person
{
public:
	void SetMediator(Mediator *mediator) { m_mediator = mediator; }
	void Sendmessage(string message) { m_mediator->Send(message, this); }
	void Getmessage(string message) { cout << "�����յ���Ϣ�� " << message; }
};



