//¿ØÖÆÖÐÐÄ
#ifndef _control_h
#define _control_h

#include<windows.h>

void initial_control();
void left();
void right();
void up();
void down();
void paint_snake();
void paint();
void retrospect(LONG *x,LONG *y);
bool defeat();
void create_target();
void approch_target();
bool permision_revision(int direction);
#endif