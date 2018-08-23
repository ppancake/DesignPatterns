#pragma once
#include<iostream>
#include<map>
#include<string>
using namespace std;


//�ⲿ״̬�����ֲ�ͬ
class User
{
public:
	User(string name) :m_name(name) {}
	string getName() { return m_name; }
private:
	string m_name;

};

//�������Ԫ��
class Flyweight
{
public:
	virtual void Operation(int i) {}
	virtual void Use(User user) {}
};



//������Ԫ�࣬����
class ConcreteFlyWeight :public Flyweight
{
public:
	ConcreteFlyWeight(string model) :m_model(model) {}

	void Use(User user) { cout << "ģ��" << m_model << "   ���û��� " << user.getName()<<endl; }
private:
	string m_model;
};

//�����������
class UnsharedConcreteFlyweight :public Flyweight
{
	void Operation()
	{
		cout << "�������FlyWeight:"  << endl;
	}
};


//��Ԫ����
class FlyweightFactory
{
private:
	//ģ�����б��洢���пι����ģ��
	map<string, Flyweight*>flyweights;
public:
	FlyweightFactory()//��ʼ����ģ���б�
	{
		flyweights["X"] = new ConcreteFlyWeight("X");
		flyweights["Y"] = new ConcreteFlyWeight("Y");
		flyweights["Z"] = new ConcreteFlyWeight("Z");//���е�����Ϊ��Z����ģ�鶼ֻ��Ӧ���һ��ʵ��
	}

	Flyweight* GetFlyWeight(string key)
	{
		if (!flyweights.count(key))//�ȼ�����Ƿ����б��У�����������½����б���
		{
			flyweights[key] = new ConcreteFlyWeight(key);
		}
		return flyweights[key];
	}
	map<string, Flyweight*>::size_type countN()//���ص�ǰ�ж��ٸ��ɹ������ģ��
	{
		return flyweights.size();
	}
};
