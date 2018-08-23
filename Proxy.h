#pragma once
#include <iostream>
#include <string>
using namespace std;
//ͼƬ�ӿڳ�����
class Image
{
public:
	Image(string name) :m_imgname(name) {}
	virtual ~Image() {}
	virtual void show() {}

protected:
	string m_imgname;
};

//��ʵ�࣬�������ɫ
class BigImage:public Image
{
public:
	BigImage(string name) :Image(name) {}
	~BigImage() {}
	void show() { cout << "Show big image : " << m_imgname << endl; }
private:

};

//�����࣬�뱻�����߹���һ���ӿڣ�������һ���������ߵĳ�Ա,û���򴴽�
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
