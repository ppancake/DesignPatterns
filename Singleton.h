#pragma once
#include <iostream>
#include <string>
using namespace std;


//��ͨ����
class singleton
{
protected:
	singleton() {}
private:
	static singleton* p;
public:
	static singleton* instance();
};
singleton* singleton::p = NULL;
singleton* singleton::instance()
{
	if (p == NULL)
		p = new singleton();
	return p;
}

//