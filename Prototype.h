#pragma once
#include <cstring>
#include <iostream>
//����
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
	ResumeA(const char *str);  //���ƹ��캯��
	ResumeA(const ResumeA &r); //�������캯��
	~ResumeA();                //��������
	ResumeA* Clone();          //��¡���ؼ�����
	void Show();               //��ʾ����
};
ResumeA::ResumeA(const char *str)	//ֵ���ͣ�����������Ҫ���ƹ���
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
ResumeA::ResumeA(const ResumeA &r) {		//�������ͣ����
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
	ResumeB(const char *str);  //���ƹ��캯��
	ResumeB(const ResumeB &r); //�������캯��
	~ResumeB();                //��������
	ResumeB* Clone();          //��¡���ؼ�����
	void Show();               //��ʾ����
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
ResumeB::ResumeB(const ResumeB &r) {		//�������ͣ����
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
}
ResumeB* ResumeB::Clone() {
	return new ResumeB(*this);
}
void ResumeB::Show() {
	std::cout << "ResumeB name : " << name << std::endl;
}


