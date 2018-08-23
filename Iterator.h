#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;


//迭代器抽象类
class Iterator
{
public:
	Iterator() {};
	virtual ~Iterator() {};
	virtual string First() = 0;
	virtual string Next() = 0;
	virtual string GetCur() = 0;
	virtual bool IsEnd() = 0;
};

//聚集类的抽象类
class Aggregate
{
public:
	virtual int Count() = 0;
	virtual void Push(const string& strValue) = 0;
	virtual string Pop(const int nIndex) = 0;
	virtual Iterator* CreateIterator() = 0;
};

//具体的迭代器类
class  ConcreteIterator :public Iterator
{
public:
	ConcreteIterator(Aggregate *aggregate) :m_nCurrent(0), Iterator() { m_Aggregate = aggregate; }
	string First(){	return m_Aggregate->Pop(0);}
	string Next()
	{
		string strRet;
		m_nCurrent++;
		if (m_nCurrent < m_Aggregate->Count())
		{
			strRet = m_Aggregate->Pop(m_nCurrent);
		}
		return strRet;
	}
	string GetCur(){return m_Aggregate->Pop(m_nCurrent);}
	bool IsEnd(){return ((m_nCurrent >= m_Aggregate->Count()) ? true : false);}



private:
	Aggregate* m_Aggregate;
	int m_nCurrent=0;
};


//具体的聚集类
class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate() :m_pIterator(NULL){m_vecItems.clear();}
	~ConcreteAggregate()
	{
		if (NULL != m_pIterator)
		{
			delete m_pIterator;
			m_pIterator = NULL;
		}
	}
	Iterator* CreateIterator()
	{
		if (NULL == m_pIterator)
		{
			m_pIterator = new ConcreteIterator(this);
		}
		return m_pIterator;
	}
	int Count()
	{
		return m_vecItems.size();
	}
	void Push(const string& strValue)
	{
		m_vecItems.push_back(strValue);
	}
	string Pop(const int nIndex){
		string strRet;
		if (nIndex < Count())
		{
			strRet = m_vecItems[nIndex];
		}
		return strRet;
	}
private:
	vector<string> m_vecItems;
	Iterator* m_pIterator;

};