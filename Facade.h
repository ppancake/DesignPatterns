#pragma once
#include <iostream>
#include <string>
using namespace std;

//��һ��ܶ�ӿ�
class Scanner
{
public:
	void Scan() { cout << "�ʷ�����" << endl; }
};
class Parser
{
public:
	void Parse() { cout << "�﷨����" << endl; }
};
class GenMidCode
{
public:
	void GenCode() { cout << "�����м����" << endl; }
};
class GenMachineCode
{
public:
	void GenCode() { cout << "����������" << endl; }
};


//�߲�ӿڣ���������ṩһ���Ӵ�Ա��������ϵͳ�����׵���

class Compiler
{
public:
	void Run()
	{
		scanner.Scan();
		parser.Parse();
		genMidCode.GenCode();
		genMacCode.GenCode();
	}
	Scanner scanner;
	Parser parser;
	GenMidCode genMidCode;
	GenMachineCode genMacCode;
};