#pragma once
#include <iostream>
#include <afxtempl.h>

using namespace std;

struct SUser{
	int num;
	char name[20];
	char sex[4];
	int type;   //1 ���    0 �Ŀ�
	void input();
	void print();
};

struct Sci : SUser{
	float phy;		//����
	float chemi;	//��ѧ
	float math;		//��ѧ
	void input();
	void print();
};

struct Art :SUser{
	float che;		//����
	float eng;		//Ӣ��
	float geo;		//����
	float com;		//�����
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

