#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//����Ľ����ߣ�ִ�к�ʵʩһ���������൱���տ�ʦ��
class Receiver
{
public:

	void BakeMutton() { cout << "������" << endl; }
	void BakeChickenWing() { cout << "������" << endl; }
};

//����ĳ����࣬������ִ����ִ�е��麯��
class Command
{
public:
	Command() {};
	Command(Receiver *receiver) : m_receiver(receiver) {};
	virtual void Execute() {};
protected:
	Receiver *m_receiver;
private:
};

//����������࣬��һ��������(�տ�ʦ��)
class BakeMuttonCommand :public Command
{
public:
	BakeMuttonCommand(Receiver* receiver) :Command(m_receiver) {}
	void ExcuteCommand()
	{
		m_receiver->BakeMutton();
	}
};
class BakeChickenWingCommand :public Command
{
public:
	BakeChickenWingCommand(Receiver* receiver) :Command(m_receiver) {}
	void ExcuteCommand()
	{
		m_receiver->BakeChickenWing();
	}
};

//Invoker �൱�ڷ���Ա����������й���
class Invoker
{
private:
	vector<Command*> *orders;
public:
	Invoker()
	{
		orders = new vector<Command*>;
	}
	~Invoker()
	{
		delete orders;
	}

	//���ö���
	void SetOrder(Command* command)
	{
		//�ж���������Ͳ��ֱ�����ͬ�Ĵ���
		if (typeid(*command) == typeid(BakeChickenWingCommand))
		{
			cout << "��־������Ա������û���ˣ�������տ���" << endl;
		}
		else
		{
			orders->push_back(command);
			time_t t = time(nullptr);
			cout << "���Ӷ����� " << typeid(*command).name() << "\t" << asctime(localtime(&t));
		}
	}

	//ȡ������
	void cancelOrder(Command * cmd)
	{
		auto iter = orders->begin();
		for (iter; iter != orders->end(); iter++)
		{
			if (*iter == cmd) {
				orders->erase(iter);
				time_t t = time(nullptr);
				cout << "ȡ�������� " << typeid(*cmd).name() << "\t" << std::asctime(localtime(&t));
				break;
			}
		}
		if (iter == orders->end())
		{
			cout << "û�д˶���" << endl;
		}
	}

	//֪ͨȫ��ִ��
	void notify() 
	{
		for (auto &it : (*orders))
			it->Execute();
	}
};