#ifndef _graphic_h
#define _graphic_h
//ͼ�λ�������

#include<windows.h>

void initial_graphic(HWND hwindow,HDC hdevice);
void graphic_layout(HWND hwindow,HDC hdevice);
void basic_red_rect(int x,int y);
void basic_white_rect(int x,int y);
void basic_locate(int x,int y,RECT*rect);
void basic_round(int x,int y);
void basic_tri(int x,int y,int margin);
void end_graphic();
#endif