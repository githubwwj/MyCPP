// Student.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Student.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Student stu;
	while (true){
		stu.input();
		stu.print();
		cout << "��#�ż�����" << endl;
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
	cout << "������\t" << "ѧ��\t" << "����\t" << "�Ա�\t" << "\t";
	cin >> num >> name >> sex;
}


void Sci::input()
{
	type = 1;
	SUser::input();
	cout << "������\t" << "����\t" << "��ѧ\t" << "��ѧ\t" << "\t";
	cin >> phy >> chemi >> math;
}

void Art::input()
{
	type = 0;
	SUser::input();
	cout << "������\t" << "����\t" << "Ӣ��\t" << "����\t" << "�����\t" << "\t";
	cin >> che >> eng >> geo >> com;
	
}

void SUser::print()
{
	cout << "ѧ��\t" << "����\t" << "�Ա�\t" << "\t" << endl;
	cout <<  num	 << "\t"	 << name	 << "\t" << sex << "\t" << endl;
}

void Sci::print()
{
	SUser::print();
	cout << "����\t" << "��ѧ\t" << "��ѧ\t" << "\t" <<endl;
	cout << phy << "\t" << chemi << "\t" << math << "\t" << endl;
}

void Art::print()
{
	SUser::print();
	cout << "����\t" << "Ӣ��\t" << "����\t" << "�����\t" << "\t" << endl;
	cout <<  che	 << "\t"	 << eng		 << "\t"	   << geo << "\t" << com << "\t" << endl;
}

void Student::input()
{
	cout << "��ѡ������� 1���   0�Ŀ�" << endl;
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
