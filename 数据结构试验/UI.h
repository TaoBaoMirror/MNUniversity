#ifndef user_interface_h
#define user_interface_h

#include<iostream>
using namespace std;
#include<windows.h>
#include<process.h>

class UI
{
public:
	static void retangle(int,int,int,int,int);
	static void mediate(char*);
	static void setcolor(int,int);
	static void wherexy(int &,int &);
	static void gotoxy(int,int);
	static void dynamic(int,int);
protected:
private:
	static void _gotoxy(int,int);
	static void _wherexy(COORD &);
	static void _retangle(int,int,int,int,int);
	static void _mediate(char*);
	static void _setcolor(int);
	static void _dynamic_heaver(void*);
};

void UI::_dynamic_heaver(void *temp)
{
	COORD *point=(COORD*)temp;
	COORD point_init;
	_wherexy(point_init);
	int x=point->X;//当前光标位置
	int y=point->Y;
	char *frame[4]={"─","╲","│","╱"};
	int frame_count=4;//对frame元素总量的计数
	int time_pause=128;//暂停时间
	while(true)
	{
		for(int i=0;i<frame_count;i++)
		{
			gotoxy(x,y);
			cout<<frame[i];
			gotoxy(point_init.X,point_init.Y);
			Sleep(time_pause);
		}
	}
}

void UI::dynamic(int x,int y)
{
	COORD *temp=new COORD;
	temp->X=x;
	temp->Y=y;
	void (*address_start)(void*)=UI::_dynamic_heaver;
	_beginthread(address_start,0,temp);
}

void UI::gotoxy(int x,int y)
{
	_gotoxy(x,y);
}

void UI::_gotoxy(int x,int y)
{
	COORD position_start={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),position_start);
}

void UI::retangle(int coord_x,int coord_y,int length,int width,int style)
{
	_retangle(coord_x,coord_y,length,width,style);
}

void UI::_retangle(int x,int y,int l,int w,int style)
{
	char *retangle_style[8];
	{//选择一种边线类型
		char *retangle_style_1[8]={"┌","─","┐","│","┘","─","└","│"};
		char *retangle_style_2[8]={"┏","━","┓","┃","┛","━","┗","┃"};
		char *retangle_style_3[8]={"┍","━","┑","│","┙","━","┕","│"};
		char *retangle_style_4[8]={"╔","═","╗","║","╝","═","╚","║"};
		char *retangle_style_5[8]={"┏","━","┓","┫","┛","━","┗","┣"};
		char *retangle_style_6[8]={"╔","═","╗","║","╣","═","╠","║"};
		int index=style;//边线类型开关
		switch(index)
		{
		case 1:
			for(int i=0;i<8;i++)
				retangle_style[i]=retangle_style_1[i];
			break;
		case 2:
			for(int i=0;i<8;i++)
				retangle_style[i]=retangle_style_2[i];
			break;
		case 3:
			for(int i=0;i<8;i++)
				retangle_style[i]=retangle_style_3[i];
			break;
		case 4:
			for(int i=0;i<8;i++)
				retangle_style[i]=retangle_style_4[i];
			break;
		case 5:
			for(int i=0;i<8;i++)
				retangle_style[i]=retangle_style_5[i];
			break;
		case 6:
			for(int i=0;i<8;i++)
				retangle_style[i]=retangle_style_6[i];
			break;
		default:
			cout<<"No Exist Solution!"<<endl;
			exit(0);
		}
	}

	//for(int i=0;i<8;i++)
	//	cout<<retangle_style[i]<<endl;

	{//绘图
		gotoxy(x,y);

		cout<<retangle_style[0];
		for(int i=0;i<l;i++)//构建上行
			cout<<retangle_style[1];

		cout<<retangle_style[2];//构建右上角

		for(int i=0;i<w;i++)//构建右列
		{
			gotoxy(x+l*2+2,y+i+1);
			//cout<<i;
			cout<<retangle_style[3];
		}
		
		gotoxy(x+l*2+2,y+w+1);//构建右下角
		cout<<retangle_style[4];


		for(int i=l*2;i>0;i-=2)//构建下行
		{
			gotoxy(x+i,y+w+1);
			//cout<<i<<" ";
			cout<<retangle_style[5];
			//system("pause");
		}

		gotoxy(x,y+w+1);//构建左下角
		cout<<retangle_style[6];

		for(int i=w;i>0;i--)//构建左列
		{
			gotoxy(x,y+i);
			cout<<retangle_style[7];
		}
	}
}

void UI::_mediate(char*temp)
{
	int length_strings=strlen(temp);//输出流字符串长；
	int length_max=80;//控制台宽度；
	int position_start_x;//居中坐标的x初始值；
	int position_start_y;//居中坐标的y初始值；
	wherexy(position_start_x,position_start_y);//当前坐标；

	position_start_x=(length_max-length_strings)/2;
	gotoxy(position_start_x,position_start_y);
	cout<<temp;

}

void UI::mediate(char*temp)
{
	_mediate(temp);
}

void UI::_wherexy(COORD &temp)
{
	CONSOLE_SCREEN_BUFFER_INFO buffer;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&buffer);
	temp.X=buffer.dwCursorPosition.X;
	temp.Y=buffer.dwCursorPosition.Y;
}

void UI::wherexy(int &x,int &y)
{
	COORD temp;
	_wherexy(temp);
	x=temp.X;
	y=temp.Y;
}

void UI::setcolor(int foreground,int background)
{
	if(foreground>=16||foreground<0)
	{
		cout<<"Error Setting Foreground Parameter";
		exit(0);
	}
	if(background>=16||background<0)
	{
		cout<<"Error Setting Background Parameter";
		exit(0);
	}
	_setcolor(foreground+background*0x10);
}

void UI::_setcolor(int temp)//文字颜色 + 背景颜色 * 0x10 来设置控制台的颜色
{
	//FOREGROUND_BLUE			0x0001 // text color contains blue.
	//FOREGROUND_GREEN		0x0002 // text color contains green.
	//FOREGROUND_RED				0x0004 // text color contains red.
	//FOREGROUND_INTENSITY 0x0008 // text color is intensified.高亮颜色
	if(temp>=256||temp<0)
	{
		cout<<"Error Setting Color Parameter";
		exit(0);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),temp);
}




#endif;