#include<windows.h>
#include"graphic.h"

namespace graphic_data
{
	HWND hwnd;
	HDC hdc;
	HPEN redpen;
	HPEN blackpen;
	HBRUSH redbrush;
	HBRUSH whitebrush;
	RECT client;
	int basic_edge=3;
	int basic_width;
	int basic_length;
	POINT zero;
}
using namespace graphic_data;

void initial_graphic(HWND hwindow,HDC hdevice)
{
	hwnd=hwindow;
	hdc=hdevice;
	GetClientRect(hwnd,&client);
	redpen=CreatePen(PS_SOLID,basic_edge,RGB(255,0,0));
	blackpen=CreatePen(PS_SOLID,1,RGB(0,0,0));
	redbrush=CreateSolidBrush(RGB(255,0,0));
	whitebrush=CreateSolidBrush(RGB(255,255,255));
	graphic_layout(hwnd,hdc);
}

void graphic_layout(HWND hwindow,HDC hdevice)
{

	//红框
	//MessageBox(hwnd,TEXT("开始绘制"),NULL,MB_OK);
	SelectObject(hdc,redpen);
	Rectangle(hdc,client.left,client.top,client.right,client.bottom);
	//横线
	SelectObject(hdc,blackpen);
	MoveToEx(hdc,0,0,NULL);
	basic_width=(client.bottom-basic_edge*2)/48;
	for(int i=basic_edge;i<client.bottom;i+=basic_width)
	{
		MoveToEx(hdc,basic_edge,i,NULL);
		LineTo(hdc,client.right-basic_edge,i);
	}
	//纵线
	SelectObject(hdc,blackpen);
	MoveToEx(hdc,0,0,NULL);
	basic_length=(client.right-basic_edge*2)/82;
	for(int i=basic_edge;i<client.right;i+=basic_length)
	{
		MoveToEx(hdc,i,basic_edge,NULL);
		LineTo(hdc,i,client.bottom-basic_edge);
	}
}
void basic_locate(int x,int y,RECT*rect)
{
	zero.x=basic_edge;
	zero.y=basic_edge;
	(*rect).left=x*basic_length+zero.x;
	(*rect).top=y*basic_width+zero.y;
	(*rect).right=(x+1)*basic_length+zero.x+1;
	(*rect).bottom=(y+1)*basic_width+zero.y+1;
	//wsprintf(&a[0],b,x,y,basic_length,basic_width,rect.left,rect.top,rect.right,rect.bottom);
	//MessageBox(hwnd,a,NULL,MB_OK);
}
void basic_red_rect(int x,int y)
{
	RECT rect;
	basic_locate(x,y,&rect);
	SelectObject(hdc,redbrush);
	Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
}
void basic_white_rect(int x,int y)
{
	RECT rect;
	basic_locate(x,y,&rect);
	SelectObject(hdc,whitebrush);
	Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
}
void basic_round(int x,int y)
{
	RECT rect;
	basic_locate(x,y,&rect);
	SelectObject(hdc,redbrush);
	Ellipse(hdc,rect.left+1,rect.top+1,rect.right-1,rect.bottom-1);
}
void basic_tri(int x,int y,int margin)
{
	RECT rect;
	POINT tri[3];
	basic_locate(x,y,&rect);
	if(margin==1)
	{
		tri[0].x=rect.right-1;
		tri[0].y=rect.bottom;
		tri[1].x=rect.left;
		tri[1].y=(rect.bottom+rect.top)/2;
		tri[2].x=rect.right-1;
		tri[2].y=rect.top;
	}
	else if(margin==2)
	{
		tri[0].x=rect.right;
		tri[0].y=rect.bottom-1;
		tri[1].x=rect.left;
		tri[1].y=rect.bottom-1;
		tri[2].x=(rect.right+rect.left)/2;
		tri[2].y=rect.top;
	}
	else if(margin==3)
	{
		tri[0].x=rect.left;
		tri[0].y=rect.top;
		tri[1].x=rect.right-1;
		tri[1].y=(rect.bottom+rect.top)/2;
		tri[2].x=rect.left;
		tri[2].y=rect.bottom;

	}
	else if(margin==4)
	{
		//MessageBox(NULL,TEXT("4"),NULL,MB_OK);
		tri[0].x=rect.left;
		tri[0].y=rect.top;
		tri[1].x=rect.right;
		tri[1].y=rect.top;
		tri[2].x=(rect.right+rect.left)/2;
		tri[2].y=rect.bottom-1;

	}
	SelectObject(hdc,redbrush);
	Polygon(hdc,tri,3);
}
void end_graphic()
{
	DeleteObject(redpen);
	DeleteObject(blackpen);
	DeleteObject(whitebrush);
	DeleteObject(redbrush);
}