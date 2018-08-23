// design.cpp : �������̨Ӧ�ó������ڵ㡣

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
	Organization Planting;//ֲ����֯
	Planting.Add(new Teacher("Johnny", 1, 10));
	Planting.Add(new VStudent("Catherine", 0, 1));
	Planting.Add(new VStudent("peter", 1, 2));

	Printer *printer=new Printer();
	Planting.PrintMembers(printer);

	return 0;
}


/*������ģʽ
int main()
{
	Context* c = new Context();
	AbstractExpression* abs = new TerminalExpression("Hello");
	AbstractExpression* nabs = new NonterminalExpression(abs, 5);
	nabs->Interpret(*c);//����5��hello

	delete nabs;
	delete abs;
	delete c;

}
*/

/*��Ԫģʽ
int main()
{

	FlyweightFactory f;

	Flyweight *px = f.GetFlyWeight("X");
	User user1("user1");
	px->Use(user1);
	User user4("user4");
	px->Use(user4);

	Flyweight *py = f.GetFlyWeight("Y");//��ȡY��Ӧ��ģ��
	User user2("user2");
	py->Use(user2);

	Flyweight *pd = f.GetFlyWeight("D");//D���ڳ�ʼ���б��У������Զ����뵽�б���
	User user3("user3");
	pd->Use(user3);

	cout << "�ɹ������ģ����:" << f.countN() << "��!" << endl;
	delete px;
	delete py;
	delete pd;

	return 0;
}
*/

/*�н���ģʽ
int main()
{
	Person *person_lord = new Landlord();
	Person *person_renter = new Renter();
	Mediator *mediator = new HouseMediator();

	mediator->SetA(person_lord);
	mediator->SetB(person_renter);
	person_lord->SetMediator(mediator);
	person_renter->SetMediator(mediator);

	person_lord->Sendmessage("�������Ͼ�·�������׷��ӣ��۸�800Ԫһ����\n");
	person_renter->Sendmessage("���ⷿ�ӣ��Ͼ�·100�ţ�70ƽ�ף�1000Ԫһ����\n");

	delete person_lord;
	delete person_renter;
	delete mediator;
	return 0;
}

*/

/*������ģʽ
int main()
{
	//�������ϼ�
	Manager *zongjingli = new GeneralManager(NULL, "�ܾ���1");
	Manager *zongjian = new Majordomo(zongjingli, "�ܼ�1");
	Manager *jingli = new CommonManger(zongjian, "����1");

	jingli->DealWithRequest("Ա��1", 300);
	jingli->DealWithRequest("Ա��2", 600);
	jingli->DealWithRequest("Ա��3", 1100);

	delete jingli;
	delete zongjian;
	delete zongjingli;
	return 0;
}
*/

/*����ģʽ
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

/*�Ž�
int main()
{
	OS *os1 = new WindowOS();
	OS *os2 = new LinuxOS();
	Computer *computer1 = new AppleComputer();
	computer1->InstallOS(os1);
	computer1->InstallOS(os2);
}

*/
/*������ģʽ
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

/*���ģʽ
int main()
{
	Company *root= new ConcreteCompany("�ܹ�˾");
	Company *leaf1 = new FinanceDepartment("����");
	Company *leaf2 = new HRDepartment("������Դ��");
	root->Add(leaf1);
	root->Add(leaf2);

	//�����ֹ�˾
	Company *mid1 = new ConcreteCompany("�ֹ�˾A");
	Company *leaf3 = new FinanceDepartment("����");
	Company *leaf4 = new HRDepartment("������Դ��");
	mid1->Add(leaf3);
	mid1->Add(leaf4);

	root->Add(mid1);	//���ֹ�˾�ӵ��ܹ�˾

	//�ڶ����ֹ�˾
	Company *mid2 = new ConcreteCompany("�ֹ�˾B");
	FinanceDepartment *leaf5 = new FinanceDepartment("����");
	HRDepartment *leaf6 = new HRDepartment("������Դ��");
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

/*����¼ģʽ
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
	cout << "�ָ��浵" << endl;
	player.Show();
	return  0;
}
*/

/*״̬ģʽ
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


/*�۲���ģʽ
int main()
{
	BlogCSDN *csdn = new BlogCSDN("zwk");
	csdn->Attach(new ObserverBlog("�û�1", csdn));
	csdn->Attach(new ObserverBlog("�û�2", csdn));
	csdn->Attach(new ObserverBlog("�û�3", csdn));

	csdn->Notify();
	return 0;
}
*/
/*������ģʽ
int main()
{
	FatBuilder thin;
	Director director(&thin);
	director.Create();
	return 0;
}
*/

/*���ģʽ
int main()
{
	Compiler compiler;
	compiler.Run();
	return 0;
}
*/

/*ģ��ģʽ
int main()
{
	AbstractClass *car = new ConcreteClass();
	car->Run();
	return 0;
}
*/

/*ԭ��ģʽ
int main()
{
	Resume *r1 = new ResumeA("A");
	Resume *r2 = new ResumeB("B");
	Resume *r3 = r1->Clone();
	Resume *r4 = r2->Clone();
	r1->Show(); r2->Show();
	//ɾ��r1,r2
	delete r1; delete r2;
	r1 = r2 = nullptr;
	//������Զ�r3,r4��Ӱ��
	r3->Show(); r4->Show();
	delete r3; delete r4;
	r3 = r4 =nullptr;
}
*/

/*���󹤳�
int main()
{
	//ͳһ�Ĵ󹤳�
	Factory *proA = new FactoryA();
	proA->create1()->show();
	proA->create2()->show();
	return 0;

}
*/

/*�������
int main()
{
	//�û��๤����ȥshow�����
	Factory *proA = new FactoryA();
	proA->create()->show();
	return 0;

}
*/

/*�򵥹������
int main()
{
	TYPE type = A;
	Factory *fac = new Factory();
	Product *pro=fac->create(A);
	pro->show();
	return 0;

}
*/

/*�������
int main()
{
	Image *image = new BigImageProxy("proxy.jpg"); //����
	image->show(); //��Ҫʱ�ɴ������
	delete image;
	return 0;

}
*/

/*װ������
int main()
{
	Phone *xiaomi = new Mi("С��6");
	Phone *decoratorA = new DecaratorA(xiaomi);
	Phone *decoratorB = new DecaratorB(decoratorA);
	decoratorB->showDecorator();
	delete decoratorA;
	delete decoratorB;
	delete xiaomi;
    return 0;
}
*/
