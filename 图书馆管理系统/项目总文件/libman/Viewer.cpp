#include "Viewer.h"
#include<conio.h>

Viewer::Viewer(void)
{
}


Viewer::~Viewer(void)
{
}


void Viewer::welcome(void)
{
	cout<<"\t\t\t-------------------------"<<endl;
	cout<<"\t\t\tLibrary Management System"<<endl;
	cout<<"\t\t\t-------------------------"<<endl;
}

void Viewer::login(string &user,string &password)
{
	setcursor(viewer_pos::login_x,viewer_pos::login_y);
	cout<<"\t\t\t-------------------------"<<endl;
	cout<<"\t\t\tUser:"<<endl;
	cout<<"\t\t\t-------------------------"<<endl;
	cout<<"\t\t\tPassword:"<<endl;
	cout<<"\t\t\t-------------------------"<<endl;
	setcursor(viewer_pos::login_user_x,viewer_pos::login_user_y);
	char temp[64];
	cin.getline(temp,sizeof(temp));
	user=temp;
	setcursor(viewer_pos::login_password_x,viewer_pos::login_password_y);
	char buf[2]="0";
	do{
		buf[0]=_getch();
		if(buf[0]!=13)
		{
			password+=buf;
			cout<<"*";
		}
	}while(buf[0]!=13);
	//cout<<password<<endl;
	//system("pause");
}

void Viewer::setcursor(int x, int y)
{
    HANDLE hOut;
    COORD pos= {x,y}; 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);
}

void Viewer::getcursor(int &x, int &y)
{
    HANDLE hOut; 
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cursor;
    GetConsoleScreenBufferInfo(hOut,&cursor);
	x=cursor.dwCursorPosition.X;
	y=cursor.dwCursorPosition.Y;
}

int Viewer::menu(void)
{
	setcursor(viewer_pos::menu_x,viewer_pos::menu_y);
	cout<<"\t\t---------------------------------------"<<endl;
	cout<<"\t\tBooks\t\tBorrower\tManager"<<endl;
	cout<<"\t\t---------------------------------------"<<endl;
	cout<<"\t\tSearch\t\tSearch\t\tSearch"<<endl;
	cout<<"\t\tUpdate\t\tUpdate\t\tUpdate"<<endl;
	cout<<"\t\tDelete\t\tDelete\t\tDelete"<<endl;
	cout<<"\t\tAppend\t\tAppend\t\tAppend"<<endl;
	cout<<"\t\t---------------------------------------"<<endl;
	setcursor(viewer_pos::menu_books_search_x,viewer_pos::menu_books_search_y);

	cout<<">";
	int operation=1;
	int keyboard=0;
	int pos=1;
	int pos_x=viewer_pos::menu_books_search_x;
	int pos_y=viewer_pos::menu_books_search_y;
	do{
		pos_x=viewer_pos::menu_books_search_x;
		pos_y=viewer_pos::menu_books_search_y;
		if((keyboard=_getch())==224)
		switch(_getch())
		{
		case 72:
			//cout<<"上"<<endl;
			if(pos==1)
			{
				pos=2048;
			}
			else
			{
				pos/=2;
			}
			break;
		case 75:
			if(pos<=8)
				pos*=256;
			else
				pos/=16;
			//cout<<"左"<<endl;
			break;
		case 77:
			if(pos>=256)
				pos/=256;
			else
				pos*=16;
			//cout<<"右"<<endl;
			break;
		case 80:
			if(pos==2048)
				pos=1;
			else
				pos*=2;
			//cout<<"下"<<endl;
			break;
		}
		//cout<<"pos::"<<pos<<endl;

		int count=-1;
		int temp=pos;
		while(temp)
		{
			temp/=2;
			count++;
		}

		operation=pos;
		//cout<<"2^n:"<<count<<endl;
		{
		int coord[4][3]={0,4,8,1,5,9,2,6,10,3,7,11};
		/*
		for(int i=0;i<4;i++)
			for(int j=0;j<3;j++)
				cout<<"coord["<<i<<"]["<<j<<"]:"<<coord[i][j]<<endl;
				*/
		for(int i=0;i<4;i++)
			for(int j=0;j<3;j++)
				if(coord[i][j]==count)
				{
					//cout<<"i="<<i<<" j="<<j<<endl;
					pos_x+=j*viewer_pos::menu_add_x;
					pos_y+=i;
				}
		int cursor_last_x;
		int cursor_last_y;
		getcursor(cursor_last_x,cursor_last_y);
		setcursor(cursor_last_x-1,cursor_last_y);
		cout<<" ";
		setcursor(pos_x,pos_y);
		cout<<">";
		}
	}while(keyboard!=13);
	
	return operation;
}



Books Viewer::get_books(void)
{
	setcursor(viewer_pos::books_x,viewer_pos::books_y);
	cout<<"---------------Books---------------"<<endl;
	cout<<SQL_book::SQL_ISBN<<":"<<endl;
	cout<<SQL_books::SQL_subID<<":"<<endl;
	cout<<SQL_book::SQL_CLCN<<":"<<endl;
	cout<<SQL_book::SQL_name<<":"<<endl;
	cout<<SQL_book::SQL_price<<":"<<endl;
	cout<<SQL_book::SQL_writer<<":"<<endl;
	cout<<SQL_book::SQL_printers<<":"<<endl;
	cout<<SQL_book::SQL_remark<<":"<<endl;
	cout<<SQL_books::SQL_ID<<":"<<endl;
	cout<<SQL_books::SQL_state<<":"<<endl;
	cout<<"-----------------------------------"<<endl;
	Books b;
	char temp[64];
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y);
	cin.getline(temp,sizeof(temp));
	b.ISBN=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+1);
	cin.getline(temp,sizeof(temp));
	b.subID=atoi(temp);
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+2);
	cin.getline(temp,sizeof(temp));
	b.CLCN=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+3);
	cin.getline(temp,sizeof(temp));
	b.name=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+4);
	cin.getline(temp,sizeof(temp));
	b.price=atoi(temp);
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+5);
	cin.getline(temp,sizeof(temp));
	b.writer=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+6);
	cin.getline(temp,sizeof(temp));
	b.printers=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+7);
	cin.getline(temp,sizeof(temp));
	b.remark=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+8);
	cin.getline(temp,sizeof(temp));
	b.ID=temp;
	setcursor(viewer_pos::books_ISBN_x,viewer_pos::books_ISBN_y+9);
	cin.getline(temp,sizeof(temp));
	b.state=atoi(temp);
	return Books(b);
}


Borrower Viewer::get_borrower(void)
{
	setcursor(viewer_pos::borrower_x,viewer_pos::borrower_y);
	cout<<"---------------Borrower------------"<<endl;
	cout<<SQL_role::SQL_ID<<":"<<endl;
	cout<<SQL_role::SQL_password<<":"<<endl;
	cout<<SQL_role::SQL_name<<":"<<endl;
	cout<<SQL_role::SQL_privilege<<":"<<endl;
	cout<<SQL_role::SQL_address<<":"<<endl;
	cout<<SQL_borrower::SQL_bookslimit<<":"<<endl;
	cout<<"-----------------------------------"<<endl;
	Borrower b;
	char temp[64];
	setcursor(viewer_pos::borrower_ID_x,viewer_pos::borrower_ID_y);
	cin.getline(temp,sizeof(temp));
	b.ID=temp;
	setcursor(viewer_pos::borrower_ID_x,viewer_pos::borrower_ID_y+1);
	cin.getline(temp,sizeof(temp));
	b.password=temp;
	setcursor(viewer_pos::borrower_ID_x,viewer_pos::borrower_ID_y+2);
	cin.getline(temp,sizeof(temp));
	b.name=temp;
	setcursor(viewer_pos::borrower_ID_x,viewer_pos::borrower_ID_y+3);
	cin.getline(temp,sizeof(temp));
	b.privilege=atoi(temp);
	setcursor(viewer_pos::borrower_ID_x,viewer_pos::borrower_ID_y+4);
	cin.getline(temp,sizeof(temp));
	b.address=temp;
	setcursor(viewer_pos::borrower_ID_x,viewer_pos::borrower_ID_y+5);
	cin.getline(temp,sizeof(temp));
	b.bookslimit=atoi(temp);
	return Borrower(b);
}


Manager Viewer::get_manager(void)
{
	setcursor(viewer_pos::manager_x,viewer_pos::manager_y);
	cout<<"---------------Manager------------"<<endl;
	cout<<SQL_role::SQL_ID<<":"<<endl;
	cout<<SQL_role::SQL_password<<":"<<endl;
	cout<<SQL_role::SQL_name<<":"<<endl;
	cout<<SQL_role::SQL_privilege<<":"<<endl;
	cout<<SQL_role::SQL_address<<":"<<endl;
	cout<<SQL_manager::SQL_salary<<":"<<endl;
	cout<<SQL_manager::SQL_worktime<<":"<<endl;
	cout<<"-----------------------------------"<<endl;
	Manager b;
	char temp[64];
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y);
	cin.getline(temp,sizeof(temp));
	b.ID=temp;
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y+1);
	cin.getline(temp,sizeof(temp));
	b.password=temp;
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y+2);
	cin.getline(temp,sizeof(temp));
	b.name=temp;
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y+3);
	cin.getline(temp,sizeof(temp));
	b.privilege=atoi(temp);
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y+4);
	cin.getline(temp,sizeof(temp));
	b.address=temp;
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y+5);
	cin.getline(temp,sizeof(temp));
	b.salary=atoi(temp);
	setcursor(viewer_pos::manager_ID_x,viewer_pos::manager_ID_y+6);
	cin.getline(temp,sizeof(temp));
	b.worktime=temp;
	return Manager(b);
}


void Viewer::clear_workspace(void)
{
	setcursor(viewer_pos::menu_x,viewer_pos::menu_y);
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
	cout<<"                                                             "<<endl;
}


void Viewer::show_books(Books b)
{
	setcursor(viewer_pos::books_x,viewer_pos::books_y);
	cout<<"---------------Books---------------"<<endl;
	cout<<SQL_book::SQL_ISBN<<":\t\t"<<b.ISBN<<endl;
	cout<<SQL_books::SQL_subID<<":\t\t"<<b.subID<<endl;
	cout<<SQL_book::SQL_CLCN<<":\t\t"<<b.CLCN<<endl;
	cout<<SQL_book::SQL_name<<":\t\t"<<b.name<<endl;
	cout<<SQL_book::SQL_price<<":\t\t"<<b.price<<endl;
	cout<<SQL_book::SQL_writer<<":\t\t"<<b.writer<<endl;
	cout<<SQL_book::SQL_printers<<":\t"<<b.printers<<endl;
	cout<<SQL_book::SQL_remark<<":\t\t"<<b.remark<<endl;
	cout<<SQL_books::SQL_ID<<":\t\t"<<b.ID<<endl;
	cout<<SQL_books::SQL_state<<":\t\t"<<b.state<<endl;
	cout<<"-----------------------------------"<<endl;
}


void Viewer::show_borrower(Borrower b)
{
	setcursor(viewer_pos::borrower_x,viewer_pos::borrower_y);
	cout<<"---------------Borrower------------"<<endl;
	cout<<SQL_role::SQL_ID<<":\t\t"<<b.ID<<endl;
	cout<<SQL_role::SQL_password<<":\t"<<b.password<<endl;
	cout<<SQL_role::SQL_name<<":\t\t"<<b.name<<endl;
	cout<<SQL_role::SQL_privilege<<":\t"<<b.privilege<<endl;
	cout<<SQL_role::SQL_address<<":\t"<<b.address<<endl;
	cout<<SQL_borrower::SQL_bookslimit<<":\t"<<b.bookslimit<<endl;
	cout<<"-----------------------------------"<<endl;
}


void Viewer::show_manager(Manager m)
{
	setcursor(viewer_pos::manager_x,viewer_pos::manager_y);
	cout<<"---------------Manager------------"<<endl;
	cout<<SQL_role::SQL_ID<<":\t\t"<<m.ID<<endl;
	cout<<SQL_role::SQL_password<<":\t"<<m.password<<endl;
	cout<<SQL_role::SQL_name<<":\t\t"<<m.name<<endl;
	cout<<SQL_role::SQL_privilege<<":\t"<<m.privilege<<endl;
	cout<<SQL_role::SQL_address<<":\t"<<m.address<<endl;
	cout<<SQL_manager::SQL_salary<<":\t\t"<<m.salary<<endl;
	cout<<SQL_manager::SQL_worktime<<":\t"<<m.worktime<<endl;
	cout<<"-----------------------------------"<<endl;
}


void Viewer::user_state(string user, string state)
{
	setcursor(viewer_pos::user_state_x,viewer_pos::user_state_y);
	cout<<"                                                                                                  "<<endl;
	setcursor(viewer_pos::user_state_x,viewer_pos::user_state_y);
	cout<<"["<<user<<"]:"<<state<<endl;
}


int Viewer::window(void)
{
	setcursor(viewer_pos::window_x,viewer_pos::window_y);
	cout<<"\t\t\t    ----------------"<<endl;
	cout<<"\t\t\t    Connect Database"<<endl;
	cout<<"\t\t\t    Login User"<<endl;
	cout<<"\t\t\t    Logout User"<<endl;
	cout<<"\t\t\t    Menu"<<endl;
	cout<<"\t\t\t    ----------------"<<endl;
	setcursor(viewer_pos::window_connect_x,viewer_pos::window_connect_y);
	cout<<">";

	int keyboard;
	int operation=1;
	do{
		if((keyboard=_getch())==224)
		switch(_getch())
		{
		case 72:
			if(operation==1)
				operation=4;
			else
				operation--;
			//cout<<"上"<<endl;
			break;
		case 75:
			//cout<<"左"<<endl;
			break;
		case 77:
			//cout<<"右"<<endl;
			break;
		case 80:
			if(operation==4)
				operation=1;
			else
				operation++;
			//cout<<"下"<<endl;
			break;
		}
		
		int cursor_last_x;
		int cursor_last_y;
		getcursor(cursor_last_x,cursor_last_y);
		setcursor(cursor_last_x-1,cursor_last_y);
		cout<<" ";
		setcursor(viewer_pos::window_connect_x,viewer_pos::window_connect_y+operation-1);
		cout<<">";
	}while(keyboard!=13);
	return operation;
}


int Viewer::borrower_menu(void)
{
	setcursor(viewer_pos::window_x,viewer_pos::window_y);
	cout<<"\t\t\t    ----------------"<<endl;
	cout<<"\t\t\t    Borrow"<<endl;
	cout<<"\t\t\t    Return"<<endl;
	cout<<"\t\t\t    Borrowed"<<endl;
	cout<<"\t\t\t    ----------------"<<endl;
	setcursor(viewer_pos::window_connect_x,viewer_pos::window_connect_y);
	cout<<">";

	int keyboard;
	int operation=1;
	do{
		if((keyboard=_getch())==224)
		switch(_getch())
		{
		case 72:
			if(operation==1)
				operation=3;
			else
				operation--;
			//cout<<"上"<<endl;
			break;
		case 75:
			//cout<<"左"<<endl;
			break;
		case 77:
			//cout<<"右"<<endl;
			break;
		case 80:
			if(operation==3)
				operation=1;
			else
				operation++;
			//cout<<"下"<<endl;
			break;
		}
		int cursor_last_x;
		int cursor_last_y;
		getcursor(cursor_last_x,cursor_last_y);
		setcursor(cursor_last_x-1,cursor_last_y);
		cout<<" ";
		setcursor(viewer_pos::window_connect_x,viewer_pos::window_connect_y+operation-1);
		cout<<">";
	}while(keyboard!=13);
	return operation;
}