#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
	Product() {}
	~Product() {}
	virtual void show() = 0;
private:

};

class ProductA :public Product
{
public:
	void show() { cout << "ProductA" << endl; }
};

class ProductB :public Product
{
public:
	void show() { cout << "ProductB" << endl; }
};

//�����࣬��Ϊ�����࣬ʵ�־���Ĺ�����
class Factory
{
public:
	virtual Product* create() = 0;
};

//ר������A�Ĺ���
class FactoryA :public Factory
{
public:
	ProductA* create() { return new ProductA; }
};

class FactoryB :public Factory
{
public:
	ProductB* create() { return new ProductB; }
};