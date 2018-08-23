// design.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "Decorator.h"
#include "Proxy.h"
#include "AbFactory.h"
#include "Template.h"
#include "Facade.h"
#include  "Builder.h"
#include "Observer.h"
#include "State.h"
#include "Memento.h"
#include "Composite.h"
#include "Iterator.h"
#include "Bridge.h"
#include "Command.h"
#include <windows.h>
#include "Responsibility.h"
#include "Mediator.h"
#include "Flyweight.h"
#include "Interpreter.h"
#include "Visitor.h"
int main()
{
	Organization Planting;//植树组织
	Planting.Add(new Teacher("Johnny", 1, 10));
	Planting.Add(new VStudent("Catherine", 0, 1));
	Planting.Add(new VStudent("peter", 1, 2));

	Printer *printer=new Printer();
	Planting.PrintMembers(printer);

	return 0;
}


/*解释器模式
int main()
{
	Context* c = new Context();
	AbstractExpression* abs = new TerminalExpression("Hello");
	AbstractExpression* nabs = new NonterminalExpression(abs, 5);
	nabs->Interpret(*c);//解释5次hello

	delete nabs;
	delete abs;
	delete c;

}
*/

/*享元模式
int main()
{

	FlyweightFactory f;

	Flyweight *px = f.GetFlyWeight("X");
	User user1("user1");
	px->Use(user1);
	User user4("user4");
	px->Use(user4);

	Flyweight *py = f.GetFlyWeight("Y");//获取Y对应的模块
	User user2("user2");
	py->Use(user2);

	Flyweight *pd = f.GetFlyWeight("D");//D不在初始化列表中，但会自动加入到列表中
	User user3("user3");
	pd->Use(user3);

	cout << "可供共享的模块有:" << f.countN() << "个!" << endl;
	delete px;
	delete py;
	delete pd;

	return 0;
}
*/

/*中介者模式
int main()
{
	Person *person_lord = new Landlord();
	Person *person_renter = new Renter();
	Mediator *mediator = new HouseMediator();

	mediator->SetA(person_lord);
	mediator->SetB(person_renter);
	person_lord->SetMediator(mediator);
	person_renter->SetMediator(mediator);

	person_lord->Sendmessage("我想在南京路附近租套房子，价格800元一个月\n");
	person_renter->Sendmessage("出租房子：南京路100号，70平米，1000元一个月\n");

	delete person_lord;
	delete person_renter;
	delete mediator;
	return 0;
}

*/

/*责任链模式
int main()
{
	//先设置上级
	Manager *zongjingli = new GeneralManager(NULL, "总经理1");
	Manager *zongjian = new Majordomo(zongjingli, "总监1");
	Manager *jingli = new CommonManger(zongjian, "经理1");

	jingli->DealWithRequest("员工1", 300);
	jingli->DealWithRequest("员工2", 600);
	jingli->DealWithRequest("员工3", 1100);

	delete jingli;
	delete zongjian;
	delete zongjingli;
	return 0;
}
*/

/*命令模式
int main()
{
	Receiver cook;
	Command *bake = new BakeMuttonCommand(&cook);
	Command *chiken = new BakeChickenWingCommand(&cook);

	Invoker waiter;
	waiter.SetOrder(bake);
	waiter.SetOrder(chiken);
	waiter.SetOrder(bake);
	waiter.SetOrder(bake);
	Sleep(1);

	waiter.cancelOrder(chiken);
	waiter.notify();
	return 0;
}
*/

/*桥接
int main()
{
	OS *os1 = new WindowOS();
	OS *os2 = new LinuxOS();
	Computer *computer1 = new AppleComputer();
	computer1->InstallOS(os1);
	computer1->InstallOS(os2);
}

*/
/*迭代器模式
int main()
{
	ConcreteAggregate* pName = new ConcreteAggregate();
	pName->Push("hello");
	pName->Push("word");
	pName->Push("cxue");
	Iterator* iter =  pName->CreateIterator();
	if (iter!=NULL)
	{
		string strItem = iter->First();
		while (!iter->IsEnd())
		{
			cout << iter->GetCur() << " is ok" << endl;
			iter->Next();
		}
	}

}
*/

/*组合模式
int main()
{
	Company *root= new ConcreteCompany("总公司");
	Company *leaf1 = new FinanceDepartment("财务部");
	Company *leaf2 = new HRDepartment("人力资源部");
	root->Add(leaf1);
	root->Add(leaf2);

	//建立分公司
	Company *mid1 = new ConcreteCompany("分公司A");
	Company *leaf3 = new FinanceDepartment("财务部");
	Company *leaf4 = new HRDepartment("人力资源部");
	mid1->Add(leaf3);
	mid1->Add(leaf4);

	root->Add(mid1);	//将分公司加到总公司

	//第二个分公司
	Company *mid2 = new ConcreteCompany("分公司B");
	FinanceDepartment *leaf5 = new FinanceDepartment("财务部");
	HRDepartment *leaf6 = new HRDepartment("人力资源部");
	mid2->Add(leaf5);
	mid2->Add(leaf6);

	root->Add(mid2);

	root->Show(0);

	delete leaf1; delete leaf2;
	delete leaf3; delete leaf4;
	delete leaf5; delete leaf6;
	delete mid1; delete mid2;
	delete root;
	return 0;
}
*/

/*备忘录模式
int main()
{
	GameRole player;
	Caretake care;
	player.Show();
	care.Save(player.Save());
	player.Attack();
	player.Show();
	care.Save(player.Save());
	player.Load(care.Load(0));
	cout << "恢复存档" << endl;
	player.Show();
	return  0;
}
*/

/*状态模式
int  main()
{
	War* war = new War(new ProPhaseState());
	for (int i = 1; i < 40; i += 5)
	{
		war->setTime(i);
		war->getState();
	}
	delete war;

	return 0;
}
*/


/*观察者模式
int main()
{
	BlogCSDN *csdn = new BlogCSDN("zwk");
	csdn->Attach(new ObserverBlog("用户1", csdn));
	csdn->Attach(new ObserverBlog("用户2", csdn));
	csdn->Attach(new ObserverBlog("用户3", csdn));

	csdn->Notify();
	return 0;
}
*/
/*建造者模式
int main()
{
	FatBuilder thin;
	Director director(&thin);
	director.Create();
	return 0;
}
*/

/*外观模式
int main()
{
	Compiler compiler;
	compiler.Run();
	return 0;
}
*/

/*模板模式
int main()
{
	AbstractClass *car = new ConcreteClass();
	car->Run();
	return 0;
}
*/

/*原型模式
int main()
{
	Resume *r1 = new ResumeA("A");
	Resume *r2 = new ResumeB("B");
	Resume *r3 = r1->Clone();
	Resume *r4 = r2->Clone();
	r1->Show(); r2->Show();
	//删除r1,r2
	delete r1; delete r2;
	r1 = r2 = nullptr;
	//深拷贝所以对r3,r4无影响
	r3->Show(); r4->Show();
	delete r3; delete r4;
	r3 = r4 =nullptr;
}
*/

/*抽象工厂
int main()
{
	//统一的大工厂
	Factory *proA = new FactoryA();
	proA->create1()->show();
	proA->create2()->show();
	return 0;

}
*/

/*工厂类的
int main()
{
	//用基类工厂类去show具体的
	Factory *proA = new FactoryA();
	proA->create()->show();
	return 0;

}
*/

/*简单工厂类的
int main()
{
	TYPE type = A;
	Factory *fac = new Factory();
	Product *pro=fac->create(A);
	pro->show();
	return 0;

}
*/

/*代理类的
int main()
{
	Image *image = new BigImageProxy("proxy.jpg"); //代理
	image->show(); //需要时由代理负责打开
	delete image;
	return 0;

}
*/

/*装饰器的
int main()
{
	Phone *xiaomi = new Mi("小米6");
	Phone *decoratorA = new DecaratorA(xiaomi);
	Phone *decoratorB = new DecaratorB(decoratorA);
	decoratorB->showDecorator();
	delete decoratorA;
	delete decoratorB;
	delete xiaomi;
    return 0;
}
*/
