#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;


//外部状态，名字不同
class User
{
public:
	User(string name) :m_name(name) {}
	string getName() { return m_name; }
private:
	string m_name;

};

//抽象的享元类
class Flyweight
{
public:
	virtual void Operation(int i) {}
	virtual void Use(User user) {}
};



//具体享元类，共享
class ConcreteFlyWeight :public Flyweight
{
public:
	ConcreteFlyWeight(string model) :m_model(model) {}

	void Use(User user) { cout << "模块" << m_model << "   有用户： " << user.getName()<<endl; }
private:
	string m_model;
};

//不共享的子类
class UnsharedConcreteFlyweight :public Flyweight
{
	void Operation()
	{
		cout << "不共享的FlyWeight:"  << endl;
	}
};


//享元工厂
class FlyweightFactory
{
private:
	//模块名列表，存储所有课共享的模块
	map<string, Flyweight*>flyweights;
public:
	FlyweightFactory()//初始共享模块列表
	{
		flyweights["X"] = new ConcreteFlyWeight("X");
		flyweights["Y"] = new ConcreteFlyWeight("Y");
		flyweights["Z"] = new ConcreteFlyWeight("Z");//所有的属性为“Z”的模块都只对应这个一个实例
	}

	Flyweight* GetFlyWeight(string key)
	{
		if (!flyweights.count(key))//先检查下是否在列表中，如果不在则新建该列表项
		{
			flyweights[key] = new ConcreteFlyWeight(key);
		}
		return flyweights[key];
	}
	map<string, Flyweight*>::size_type countN()//返回当前有多少个可供共享的模块
	{
		return flyweights.size();
	}
};
