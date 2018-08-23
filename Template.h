#pragma once
#include <iostream>
#include <string>
using namespace std;
class AbstractClass
{
public:
	//һϵ�в����Ǽܣ�����ʵ��
	void Run()
	{
		DoA();
		DoB();
		DoC();

	}
	virtual void DoA() = 0;
	virtual void DoB() = 0;
	virtual void DoC() = 0;

};

class ConcreteClass :public AbstractClass
{
public:
	void DoA()
	{
		cout << "������" << endl;
	}
	void DoB()
	{
		cout << "�س���" << endl;
	}
	void DoC()
	{
		cout << "��������" << endl;
	}
};
