#pragma once
#include"Books.h"
#include"Borrower.h"
#include"Manager.h"

#include<windows.h>
#include<iostream>
#include<string>
using namespace std;
namespace viewer_pos
{
	static int login_x=0;
	static int login_y=8;
	static int login_user_x=34;
	static int login_user_y=9;
	static int login_password_x=34;
	static int login_password_y=11;

	static int menu_x=0;
	static int menu_y=5;
	static int menu_books_search_x=15;
	static int menu_books_search_y=8;
	static int menu_add_x=16;

	static int books_x=0;
	static int books_y=5;
	static int books_ISBN_x=15;
	static int books_ISBN_y=6;

	static int borrower_x=0;
	static int borrower_y=5;
	static int borrower_ID_x=15;
	static int borrower_ID_y=6;

	
	static int manager_x=0;
	static int manager_y=5;
	static int manager_ID_x=15;
	static int manager_ID_y=6;

	static int user_state_x=0;
	static int user_state_y=30;

	static int window_x=0;
	static int window_y=8;
	static int window_connect_x=27;
	static int window_connect_y=9;


}
class Viewer
{
public:
	Viewer(void);
	~Viewer(void);
	void welcome(void);
	void login(string &user,string &password);
	void setcursor(int x, int y);
	int menu(void);
	void getcursor(int &x, int &y);
	Books get_books(void);
	Borrower get_borrower(void);
	Manager get_manager(void);
	void clear_workspace(void);
	void show_books(Books b);
	void show_borrower(Borrower b);
	void show_manager(Manager m);
	void user_state(string user, string state);
	int window(void);
	int borrower_menu(void);
};

