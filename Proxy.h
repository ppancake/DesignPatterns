#pragma once
#include <iostream>
#include <string>
using namespace std;
//图片接口抽象类
class Image
{
public:
	Image(string name) :m_imgname(name) {}
	virtual ~Image() {}
	virtual void show() {}

protected:
	string m_imgname;
};

//真实类，被代理角色
class BigImage:public Image
{
public:
	BigImage(string name) :Image(name) {}
	~BigImage() {}
	void show() { cout << "Show big image : " << m_imgname << endl; }
private:

};

//代理类，与被代理者共用一个接口，类内有一个被代理者的成员,没有则创建
class BigImageProxy:public Image
{
public:
	BigImageProxy(string name) :Image(name), m_bigImage(0) {}
	~BigImageProxy() { delete m_bigImage; }
	void show()
	{
		if (m_bigImage == nullptr)
			m_bigImage = new BigImage(m_imgname);
		m_bigImage->show();
	}
private:
	BigImage* m_bigImage;
};
