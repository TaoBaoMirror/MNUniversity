#include<windows.h>
#include"cont.h"
#include<vector>
using namespace std;
fs::fs(HDC hdc)
{
	fs::hdc=hdc;
	hsd=10;
	nsi=1;
	frg=RGB(0,255,0);
	bkg=RGB(0,0,0);
	sz_h=12;
	sz_w=12;
	st_x=10;
	st_y=0;
	sty+="symbol";
	fnt+="10";
}
void fs::set_hsd(int buffer)
{
	hsd=buffer;
}
void fs::set_frg(COLORREF buffer)
{
	frg=buffer;
}
void fs::set_bkg(COLORREF buffer)
{
	bkg=buffer;
}
void fs::set_fsz(int height,int weight)
{
	sz_h=height;
	sz_w=weight;
}
void fs::set_nsi(int buffer)
{
	nsi=buffer;
}
void fs::set_stx(int buffer)
{
	st_x=buffer;
}
void fs::action()
{
	SetGraphicsMode(hdc,GM_ADVANCED );
	HGDIOBJ hfont = CreateFontA(sz_h,sz_w,900,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY, VARIABLE_PITCH,fnt.c_str());
	SelectObject(hdc,hfont);
	
	SetTextColor(hdc,frg);
	SetBkColor(hdc,bkg);
	for(int i=st_y ; i < GetSystemMetrics(SM_CYSCREEN)+fnt.size()*sz_h;i+=nsi)
	{
		TextOutA(hdc,st_x,i,fnt.c_str(),fnt.size());
		Sleep(hsd);
	}
	DeleteObject(hfont);
}
void fs::set_sty(string buffer)
{
	sty=buffer;
}
void fs::set_fnt(string buffer)
{
	fnt=buffer;
}