#pragma once
#include <iostream>
#include <string>
using namespace std;

class War;

//状态类
class State
{
public:
	State() {}
	~State() {}
	virtual void Prophase() {}	//前
	virtual void Metaphase() {}	//中	
	virtual void Anaphase() {}	//后
	virtual void End() {}		//结束
	virtual void CurrentState(War *war) {}	//目前的战争状态

private:

};

//状态管理类
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


//具体的战争类

//战争结束
class EndState : public State
{
public:
	void End(War *war) //结束阶段的具体行为
	{
		cout << "战争结束" << endl;
	}
	void CurrentState(War *war) { End(war); }
};
//后期
class AnaphaseState : public State
{
public:
	void Anaphase(War *war) //后期的具体行为
	{
		if (war->getTime() < 30)
			cout << "第" << war->getTime() << "天：战争后期，双方拼死一搏" << endl;
		else
		{
			war->setState(new EndState());
			war->getState();
		}
	}
	void CurrentState(War *war) { Anaphase(war); }
};
//中期
class MetaphaseState : public State
{
public:
	void Metaphase(War *war) //中期的具体行为
	{
		if (war->getTime() < 20)
			cout << "第" << war->getTime() << "天：战争中期，进入相持阶段，双发各有损耗" << endl;
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
			cout << "第" << war->getTime() << "天：战争初期，双方你来我往，互相试探对方" << endl;
		else
		{
			war->setState(new MetaphaseState());
			war->getState();
		}

	}
	void CurrentState(War *war) { Prophase(war); }

};