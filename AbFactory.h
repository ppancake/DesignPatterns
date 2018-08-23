#pragma once
#include <iostream>
#include <string>
using namespace std;

//�ȶ���ò�Ʒ1��A1 B1���ٶ����Ʒ2��A2��B2
class Product1
{
public:
	Product1() {}
	~Product1() {}
	virtual void show() = 0;
private:

};

class ProductA1 :public Product1
{
public:
	void show() { cout << "ProductA1" << endl; }
};

class ProducB1 :public Product1
{
public:
	void show() { cout << "ProductB1" << endl; }
};

class Product2
{
public:
	Product2() {}
	~Product2() {}
	virtual void show() = 0;
private:

};

class ProductA2 :public Product2
{
public:
	void show() { cout << "ProductA2" << endl; }
};

class ProductB2 :public Product2
{
public:
	void show() { cout << "ProductB2" << endl; }
};


//�����࣬��������2������
class Factory
{
public:
	virtual Product1* create1() = 0;
	virtual Product2* create2() = 0;
};

//ר������A�Ĺ���
class FactoryA :public Factory
{
public:
	Product1* create1() { return new ProductA1(); }
	Product2* create2() { return new ProductA2(); }
};

class FactoryB :public Factory
{
public:
	Product1* create1() {return new ProducB1();}
	Product2* create2() { return new ProductB2(); }
};

