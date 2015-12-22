#include<iostream>
using namespace std;
#include"UI.h";
#include<conio.h>


int main()
{
	//Anumber a("d:\\1.txt");
	//a.caculate();
	//a.print();
	//cout<<endl;
	UI x;
	x.retangle(0,0,38,22,4);
	x.retangle(0,0,38,1,6);
	
	x.setcolor(0,15);
	x.mediate("欢迎使用学生信息管理系统");

	x.setcolor(15,0);
	x.gotoxy(5,4);
	cout<<"->";
	char a;
	int pre_x;
	int pre_y;
	while(true)
	{
	_getch();
	a=_getch();
	x.wherexy(pre_x,pre_y);
	x.gotoxy(pre_x-2,pre_y);
	cout<<"  ";
	if(a==0x48)
	{
		x.gotoxy(5,5);
		cout<<"↑";
	}
	else if(a==0x50)
	{
		x.gotoxy(5,5);
		cout<<"↓";
	}
	else if(a==0x4B)
	{
		x.gotoxy(5,5);
		cout<<"←";
	}
	else if(a==0x4D)
	{
		x.gotoxy(5,5);
		cout<<"→";
	}
	}
	return 0;
}