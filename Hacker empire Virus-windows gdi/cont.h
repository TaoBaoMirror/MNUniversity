#pragma once
#include<windows.h>
#include<vector>
using namespace std;
class fs	//font stream
{
public:
	fs(HDC);
	void set_hsd(int);	//set holistic speed;
	void set_nsi(int);	//set next stream interval;
	void set_stx(int);	//set start x;
	void set_fsz(int,int);	//set font size;
	void set_bkg(COLORREF);	//set background color;
	void set_frg(COLORREF);	//set foreground color;
	void set_sty(string);	//set style;
	void set_fnt(string);	//set font;
	void action();	//define action;
	void load_bkg();	//load background
protected:
	HDC hdc;
private:
	int hsd;	//holistic speed;
	int nsi;	//next stream interval;
	int sz_h;	//font size height;
	int sz_w;	//font size weight;
	int st_x;	//start x;
	int st_y;	//start y;
	string sty;	//font style;
	string fnt;	//font
	COLORREF bkg;	//background;
	COLORREF frg;	//foreground;
};