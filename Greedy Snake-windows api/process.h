#ifndef _process_h
#define _process_h
//���ڴ�������
#include<windows.h>

void win(HINSTANCE);
void attribute();
LRESULT CALLBACK process(HWND hwinmain,UINT message,WPARAM wparam,LPARAM lparam);
#endif