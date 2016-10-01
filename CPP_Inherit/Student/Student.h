#pragma once
#include <iostream>
#include <afxtempl.h>

using namespace std;

struct SUser{
	int num;
	char name[20];
	char sex[4];
	int type;   //1 理科    0 文科
	void input();
	void print();
};

struct Sci : SUser{
	float phy;		//物理
	float chemi;	//化学
	float math;		//数学
	void input();
	void print();
};

struct Art :SUser{
	float che;		//语文
	float eng;		//英语
	float geo;		//地理
	float com;		//计算机
	void input();
	void print();
};




class Student
{

	CList<SUser*> mCList;
	typedef bool(*FUNC)(SUser & a, SUser & b);

public:
	Student();
	~Student();

	void add();
	void print();
	void input();
};

