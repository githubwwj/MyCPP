// Student.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Student.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Student stu;
	while (true){
		stu.input();
		stu.print();
		cout << "按#号键结束" << endl;
		char c;
		cin >> c;
		if (c == '#'){
			break;
		}
	}
	
	system("pause");
	return 0;
}



Student::Student()
{
}


Student::~Student()
{
}

void SUser::input()
{
	cout << "请输入\t" << "学号\t" << "姓名\t" << "性别\t" << "\t";
	cin >> num >> name >> sex;
}


void Sci::input()
{
	type = 1;
	SUser::input();
	cout << "请输入\t" << "物理\t" << "化学\t" << "数学\t" << "\t";
	cin >> phy >> chemi >> math;
}

void Art::input()
{
	type = 0;
	SUser::input();
	cout << "请输入\t" << "语文\t" << "英语\t" << "地理\t" << "计算机\t" << "\t";
	cin >> che >> eng >> geo >> com;
	
}

void SUser::print()
{
	cout << "学号\t" << "姓名\t" << "性别\t" << "\t" << endl;
	cout <<  num	 << "\t"	 << name	 << "\t" << sex << "\t" << endl;
}

void Sci::print()
{
	SUser::print();
	cout << "物理\t" << "化学\t" << "数学\t" << "\t" <<endl;
	cout << phy << "\t" << chemi << "\t" << math << "\t" << endl;
}

void Art::print()
{
	SUser::print();
	cout << "语文\t" << "英语\t" << "地理\t" << "计算机\t" << "\t" << endl;
	cout <<  che	 << "\t"	 << eng		 << "\t"	   << geo << "\t" << com << "\t" << endl;
}

void Student::input()
{
	cout << "请选择文理科 1理科   0文科" << endl;
	int i;
	cin >> i;
	SUser *pData = NULL;
	if (i == 0){
		Art *art = new Art;
		art->input();
		pData = art;
	}
	else if (i == 1){
		Sci *sci = new Sci;
		sci->input();
		pData = sci;
	}
	mCList.AddTail(pData);
}

void Student::add()
{

}



void Student::print()
{
	cout << "===============================" << endl;
	POSITION position=mCList.GetHeadPosition();
	while (position){
		SUser *data = mCList.GetAt(position);
		if (data->type == 0){
			Art *art = (Art*)data;
			art->print();
		}else if (data->type == 1){
			Sci * sci= (Sci*)data;
			sci->print();
		}
		mCList.GetNext(position);
		cout << "===============================" << endl;
	}
}
