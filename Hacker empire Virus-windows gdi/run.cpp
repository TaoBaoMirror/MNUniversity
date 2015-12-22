//启动中心
#include<windows.h>
#include<process.h>
#include"resource.h"
#include"cont.h"
#include"file.h"
#include<cstdlib>
#include<ctime>
using namespace std;
LRESULT CALLBACK process(HWND hwinmain,UINT message,WPARAM wparam,LPARAM lparam);
void onefont(void *buffer);
void general(struct pbt*);
void rdbf();
int rdt();
void action();

#define timer_1 1
#define timer_2 2
HCURSOR hcursor;
HICON hicon;
WNDCLASSEX wndclass;
MSG msg;
HWND hwnd;
LPCWSTR caption=TEXT("Virus");
LPCWSTR classname=TEXT("VIRUS");
PAINTSTRUCT paintstruct;
HDC hdc;
int FPS=16;	//fps
int RPS=16;	//random per s;

int max_fs=28;	//maximum fs class;
int max_spd=32;	//maximum speed;
int min_spd=5;	//minimum speed;
int max_str=108;	//maximum length string
int min_str=5;	//minimum length string
int ret_fs=0;	//recent fs number;
int bsc=12;	//basic x weight;
bool *busy;	//is a row busy;
file f;	//file stream
struct pbt	//point beginthread
{
	string str;
	int speed;
	int st_x;
};

pbt *buffer;

void attribute(HINSTANCE hinstance);
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	f.openoutfile("D:\\log.log");
	busy=new bool [GetSystemMetrics(SM_CXSCREEN)/bsc];
	for(int i=0;i<GetSystemMetrics(SM_CXSCREEN)/bsc;i++)
		busy[i]=false;
	attribute(hInstance);
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	ExitProcess(0);
}
void attribute(HINSTANCE hinstance)
{
	hcursor = LoadCursor(hinstance,IDC_ARROW);
	hicon = LoadIcon(hinstance,MAKEINTRESOURCE(IDI_ICON1));
	wndclass.hIcon=hicon;
	wndclass.hCursor=hcursor;
	wndclass.hInstance = hinstance;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.hbrBackground = (HBRUSH)COLOR_HIGHLIGHT;
	wndclass.lpszClassName = classname;
	wndclass.lpfnWndProc = process;
	RegisterClassEx(&wndclass);
	hwnd = CreateWindowEx(WS_EX_TOPMOST,
		classname,
		NULL,
		WS_POPUP | WS_EX_LAYERED,//WS_OVERLAPPEDWINDOW
		0,
		0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		NULL,
		NULL,
		hinstance,
		NULL);
	ShowWindow(hwnd,SW_NORMAL);
}

LRESULT CALLBACK process(HWND hwinmain,UINT message,WPARAM wparam,LPARAM lparam)
{
	switch(message)
	{
	case WM_DESTROY:
		DestroyWindow(hwinmain);
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		SetTimer(hwinmain,timer_1,RPS,NULL);
		SetTimer(hwinmain,timer_2,FPS,NULL);
		return 0;
	case WM_TIMER:
		if(wparam==timer_1)
			action();
		else
			SetWindowPos(hwnd,
				HWND_TOPMOST,
				0,
				0,
				GetSystemMetrics(SM_CXSCREEN),
				GetSystemMetrics(SM_CYSCREEN),
				SWP_SHOWWINDOW);
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hwinmain,&paintstruct);
		
		HGDIOBJ brh=CreateSolidBrush(RGB(0,0,0));
		SelectObject(hdc,brh);
		Rectangle(hdc,0,0,GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));
		DeleteObject(brh);
		
		EndPaint(hwinmain,&paintstruct);
		return 0;
	}
	return DefWindowProc(hwinmain,message,wparam,lparam);
}

void general(pbt *buffer)
{
	char a[64];
	itoa(buffer->st_x/bsc,a,10);
	f.writefile(a);
	f.writefile("\t\t\t\t\t");
	f.writefile("OK\n");
	f.flush();
	_beginthread(onefont,0,buffer);
}
void onefont(void *buffer)
{
	busy[((struct pbt*)buffer)->st_x/bsc]=true;
	ret_fs++;
	fs virus(GetDC(hwnd));
	virus.set_fnt(((struct pbt*)buffer)->str);
	((struct pbt*)buffer)->str.clear();
	virus.set_hsd(((struct pbt*)buffer)->speed);
	virus.set_stx(((struct pbt*)buffer)->st_x);
	virus.action();
	ret_fs--;
	busy[((struct pbt*)buffer)->st_x/bsc]=false;


	
	char a[64];
	itoa((((struct pbt*)buffer)->st_x/bsc),a,10);
	f.writefile(a);
	f.writefile("\t\t\t\t\t");
	f.writefile("FALSE\n");
	_endthread();
}
int srdt()	//random a data
{
	srand((unsigned)time(NULL));
	return rand();
}
int rdt()
{
	return rand();
}
void rdbf()	//random pbt strcut buffer;
{
	pbt *buf_pbt=new pbt;
	int temp=srdt()%(max_str-min_str)+min_str;
	for(int i=0;i<temp;i++)
	{
		if(1==rdt()%2)
			buf_pbt->str+="1";
		else
			buf_pbt->str+="0";
	}
	buf_pbt->speed=rdt()*srdt()%(max_spd-min_spd)+min_spd;
	buf_pbt->st_x=(rdt()%(GetSystemMetrics(SM_CXSCREEN)/bsc))*bsc;
	buffer=buf_pbt;
}
void action()
{
	rdbf();
	pbt *temp=buffer;
	if(false==busy[temp->st_x/bsc] && ret_fs<max_fs)
		general(temp);//创建线程
	else
		temp->str.clear();
}