#pragma once
#include <iostream>
#include <string>
using namespace std;

//有一组很多接口
class Scanner
{
public:
	void Scan() { cout << "词法分析" << endl; }
};
class Parser
{
public:
	void Parse() { cout << "语法分析" << endl; }
};
class GenMidCode
{
public:
	void GenCode() { cout << "产生中间代码" << endl; }
};
class GenMachineCode
{
public:
	void GenCode() { cout << "产生机器码" << endl; }
};


//高层接口，负责对外提供一个接待员，对内子系统更容易调用

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