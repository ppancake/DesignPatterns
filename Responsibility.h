#pragma once
#include <iostream>
#include <string>
using namespace std;

//��������� ��һ�����¼ҵ�����,���ڶ�̬��ʵ�����Լ�

class Manager
{
protected:
	Manager *m_manager;
	string m_name;
public:
	Manager(Manager *manager, string name) :m_manager(manager), m_name(name) {}
	virtual void DealWithRequest(string name, int num) {}
};

//���������,����
class CommonManger :public Manager
{
public:
	CommonManger(Manager *manager, string name):Manager(manager,name){}
	void DealWithRequest(string requestMame, int num)
	{
		if (num < 500)	//������Ȩ����
		{
			cout << "����" << m_name << "��׼" << requestMame << "��н" << num << "Ԫ" << endl;
		}
		else
		{
			cout << "����" << m_name << "�޷����������ܼദ��" << endl;
			m_manager->DealWithRequest(requestMame, num);

		}
	}

};


//�ܼ�
class Majordomo : public Manager
{
public:
	Majordomo(Manager *manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)
	{
		if (num < 1000) //�ܼ�ְȨ֮��
		{
			cout << "�ܼ�" << m_name << "��׼" << name << "��н" << num << "Ԫ" << endl << endl;
		}
		else
		{
			cout << "�ܼ�" << m_name << "�޷����������ܾ�����" << endl;
			m_manager->DealWithRequest(name, num);
		}
	}
};


//�ܾ���
class GeneralManager : public Manager
{
public:
	GeneralManager(Manager *manager, string name) :Manager(manager, name) {}
	void DealWithRequest(string name, int num)  //�ܾ�����Դ�����������
	{
		cout << "�ܾ���" << m_name << "��׼" << name << "��н" << num << "Ԫ" << endl << endl;
	}
};