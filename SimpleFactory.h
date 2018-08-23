#pragma once
#include <iostream>
#include <string>
using namespace std;

enum TYPE { A, B };
class Product
{
public:
	Product(){}
	~Product() {}
	virtual void show() = 0;
private:

};

class ProductA:public Product
{
public:
	void show() { cout << "ProductA" << endl; }
};

class ProductB :public Product
{
public:
	void show() { cout << "ProductB" << endl; }
};

//工厂，然后内部判断
class Factory 
{
public:
	Product* create(enum TYPE type)
	{
		switch (type)
		{
		case A:
			return new ProductA;
			break;
		case B:
			return new ProductB;
			break;
		default:
			break;
		}
	}
};