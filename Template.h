#pragma once
#include <iostream>
#include <string>
using namespace std;
class AbstractClass
{
public:
	//一系列操作骨架，子类实现
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
		cout << "开车门" << endl;
	}
	void DoB()
	{
		cout << "关车门" << endl;
	}
	void DoC()
	{
		cout << "发车走人" << endl;
	}
};
