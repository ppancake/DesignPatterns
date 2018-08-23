#pragma once

#include <iostream>
#include <string>
using namespace std;
//����ϵͳ
class OS
{
public:
	virtual void InstallOS_Imp() {}
};
class WindowOS : public OS
{
public:
	void InstallOS_Imp() { cout << "��װWindow����ϵͳ" << endl; }
};
class LinuxOS : public OS
{
public:
	void InstallOS_Imp() { cout << "��װLinux����ϵͳ" << endl; }
};
class UnixOS : public OS
{
public:
	void InstallOS_Imp() { cout << "��װUnix����ϵͳ" << endl; }
};
//�����
class Computer
{
public:
	virtual void InstallOS(OS *os) {}
};
class DellComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};
class AppleComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};
class HPComputer : public Computer
{
public:
	void InstallOS(OS *os) { os->InstallOS_Imp(); }
};
