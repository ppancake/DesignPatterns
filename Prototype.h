#pragma once
#include <cstring>
#include <iostream>
//父类
class Resume
{
protected:
	char *name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return nullptr; }
	virtual void Set(char *n) {}
	virtual void Show() {}
};

class ResumeA : public Resume
{
public:
	ResumeA(const char *str);  //复制构造函数
	ResumeA(const ResumeA &r); //拷贝构造函数
	~ResumeA();                //析构函数
	ResumeA* Clone();          //克隆，关键所在
	void Show();               //显示内容
};
ResumeA::ResumeA(const char *str)	//值类型，不管怎样都要复制过来
{
	if (str == nullptr) {
		name = new char[1];
		name[0] = '\0';
	}
	else {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeA::~ResumeA() { delete[] name; }
ResumeA::ResumeA(const ResumeA &r) {		//引用类型，深复制
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeA* ResumeA::Clone() {
	return new ResumeA(*this);
}
void ResumeA::Show() {
	std::cout << "ResumeA name : " << name << std::endl;
}


class ResumeB : public Resume
{
public:
	ResumeB(const char *str);  //复制构造函数
	ResumeB(const ResumeB &r); //拷贝构造函数
	~ResumeB();                //析构函数
	ResumeB* Clone();          //克隆，关键所在
	void Show();               //显示内容
};
ResumeB::ResumeB(const char *str)
{
	if (str == nullptr) {
		name = new char[1];
		name[0] = '\0';
	}
	else {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
}
ResumeB::~ResumeB() { delete[] name; }
ResumeB::ResumeB(const ResumeB &r) {		//引用类型，深复制
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeB* ResumeB::Clone() {
	return new ResumeB(*this);
}
void ResumeB::Show() {
	std::cout << "ResumeB name : " << name << std::endl;
}


