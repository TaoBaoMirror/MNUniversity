
#include<windows.h>
#include"process.h"
#include"resource.h"
#include"graphic.h"
#include"control.h"

namespace process_data
{
	HINSTANCE hinstance;
	HWND hwnd;
	HWND hwinmain;
	HDC hdc;
	HCURSOR hcursor;
	HICON hicon;
	WNDCLASSEX wndclass;
	MSG msg;
	LPCWSTR caption=TEXT("Greedy Snake - Made By <LiZhi>");
	LPCWSTR classname=TEXT("greedy snake");
	PAINTSTRUCT paintstruct;
}

using namespace process_data;

LRESULT CALLBACK process(HWND hwinmain,UINT message,WPARAM wparam,LPARAM lparam)
{
	switch(message)
	{
	case WM_DESTROY://处理窗口关闭消息
		ReleaseDC(hwnd,hdc);
		DestroyWindow(hwinmain);
		PostQuitMessage(0);
		return 0;
	case WM_CREATE://创建窗口消息
		SetTimer(hwinmain,1,5,NULL);
		return 0;
	case WM_TIMER:
		if(defeat())
		{
			KillTimer(hwnd,1);
		}
		approch_target();
		return 0;
	case WM_CHAR://处理字符型消息
		if(wparam=='w'||wparam=='W')
		{
			up();
			//TextOut(hdc,20,10,TEXT("上"),1);
		}
		else if(wparam=='s'||wparam=='S')
		{
			down();
		}
		else if(wparam=='a'||wparam=='A')
		{
			left();
		}
		else if(wparam=='d'||wparam=='D')
		{
			right();
		}
		return 0;
	case WM_KEYDOWN://虚拟按键消息处理
		switch(wparam)
		{
		case VK_UP:
			up();
			return 0;
		case VK_DOWN:
			down();
			return 0;
		case VK_LEFT:
			left();
			return 0;
		case VK_RIGHT:
			right();
			return 0;
		case VK_SPACE:
			initial_graphic(hwnd,hdc);
			initial_control();
			return 0;
		}
	case WM_PAINT:
		BeginPaint(hwnd,&paintstruct);
		EndPaint(hwnd,&paintstruct);
		return 0;
	}
	return DefWindowProc(hwinmain,message,wparam,lparam);
}
void attribute()
{
	hcursor = LoadCursor(hinstance,IDC_ARROW);
	hicon = LoadIcon(hinstance,MAKEINTRESOURCE(IDI_ICON1));

	wndclass.hIcon=hicon;
	wndclass.hCursor=hcursor;
	wndclass.hInstance = hinstance;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.hbrBackground = (HBRUSH)WHITE_BRUSH;
	wndclass.lpszClassName = classname;
	wndclass.lpfnWndProc = process;
	RegisterClassEx(&wndclass);

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,classname,caption,WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX|WS_DLGFRAME,365,125,683,457,NULL,NULL,hinstance,NULL);
	hdc=GetDC(hwnd);
	
	ShowWindow(hwnd,SW_NORMAL);
	UpdateWindow(hwnd);
}

void win(HINSTANCE hins)
{
	hinstance=hins;
	attribute();
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}