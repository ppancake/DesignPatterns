#pragma once
#include <iostream>
#include <string>
using namespace std;

class War;

//״̬��
class State
{
public:
	State() {}
	~State() {}
	virtual void Prophase() {}	//ǰ
	virtual void Metaphase() {}	//��	
	virtual void Anaphase() {}	//��
	virtual void End() {}		//����
	virtual void CurrentState(War *war) {}	//Ŀǰ��ս��״̬

private:

};

//״̬������
class War
{
public:
	War(State* state) :m_state(state), m_time(0) {}
	~War() {}
	int getTime() { return m_time; }
	void setTime(int time) { m_time = time; }
	void setState(State* state) { delete m_state; m_state = state; }
	void getState() { return m_state->CurrentState(this); }


private:
	State* m_state;
	int m_time;
};


//�����ս����

//ս������
class EndState : public State
{
public:
	void End(War *war) //�����׶εľ�����Ϊ
	{
		cout << "ս������" << endl;
	}
	void CurrentState(War *war) { End(war); }
};
//����
class AnaphaseState : public State
{
public:
	void Anaphase(War *war) //���ڵľ�����Ϊ
	{
		if (war->getTime() < 30)
			cout << "��" << war->getTime() << "�죺ս�����ڣ�˫��ƴ��һ��" << endl;
		else
		{
			war->setState(new EndState());
			war->getState();
		}
	}
	void CurrentState(War *war) { Anaphase(war); }
};
//����
class MetaphaseState : public State
{
public:
	void Metaphase(War *war) //���ڵľ�����Ϊ
	{
		if (war->getTime() < 20)
			cout << "��" << war->getTime() << "�죺ս�����ڣ�������ֽ׶Σ�˫���������" << endl;
		else
		{
			war->setState(new AnaphaseState());
			war->getState();
		}
	}
	void CurrentState(War *war) { Metaphase(war); }
};

class ProPhaseState :public State
{
public:
	void Prophase(War* war)
	{
		if(war->getTime()<10)
			cout << "��" << war->getTime() << "�죺ս�����ڣ�˫������������������̽�Է�" << endl;
		else
		{
			war->setState(new MetaphaseState());
			war->getState();
		}

	}
	void CurrentState(War *war) { Prophase(war); }

};