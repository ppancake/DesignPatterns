#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

//命令的接受者，执行和实施一个操作，相当于烧烤师傅
class Receiver
{
public:

	void BakeMutton() { cout << "烤羊肉" << endl; }
	void BakeChickenWing() { cout << "烤鸡翅" << endl; }
};

//命令的抽象类，可以让执行者执行的虚函数
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

//具体的命令类，绑定一个接收者(烧烤师傅)
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

//Invoker 相当于服务员，对命令进行管理
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

	//设置订单
	void SetOrder(Command* command)
	{
		//判断命令的类型并分别做不同的处理
		if (typeid(*command) == typeid(BakeChickenWingCommand))
		{
			cout << "日志：服务员：鸡翅没有了，请点别的烧烤！" << endl;
		}
		else
		{
			orders->push_back(command);
			time_t t = time(nullptr);
			cout << "增加订单： " << typeid(*command).name() << "\t" << asctime(localtime(&t));
		}
	}

	//取消订单
	void cancelOrder(Command * cmd)
	{
		auto iter = orders->begin();
		for (iter; iter != orders->end(); iter++)
		{
			if (*iter == cmd) {
				orders->erase(iter);
				time_t t = time(nullptr);
				cout << "取消订单： " << typeid(*cmd).name() << "\t" << std::asctime(localtime(&t));
				break;
			}
		}
		if (iter == orders->end())
		{
			cout << "没有此订单" << endl;
		}
	}

	//通知全部执行
	void notify() 
	{
		for (auto &it : (*orders))
			it->Execute();
	}
};