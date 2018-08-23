#pragma once
#include <iostream>
#include <string>
using namespace std;

//包含解释器以外的全局信息
class Context
{
public:
	Context() {}
	~Context() {}
};


//抽象解释器
class AbstractExpression
{
public:
	virtual ~AbstractExpression() {}
	virtual void Interpret(const Context& c) {}
protected:
	AbstractExpression() {}
};


class TerminalExpression :public AbstractExpression
{
public:
	TerminalExpression(const string& statement)
	{
		m_statement = statement;
	}
	~TerminalExpression() {}
	void Interpret(const Context& c)
	{
		cout << "终端解释器" << endl;
	}
private:
	string m_statement;
};

//非终端解释器
class NonterminalExpression :public AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression* ex, int times)
	{
		m_ex = ex;
		m_times = times;
	}
	~NonterminalExpression() {};
	void Interpret(const Context& c)
	{
		for (int i = 0; i < m_times; i++)
			m_ex->Interpret(c);
	}
private:
	AbstractExpression* m_ex;
	int m_times;
};


