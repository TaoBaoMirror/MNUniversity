#pragma once

#include"DB_books.h"
#include"DB_borrower.h"
#include"DB_manager.h"

namespace privilege_codes
{
	static unsigned int DB_books_search=1;
	static unsigned int DB_books_up=2;
	static unsigned int DB_books_del=4;
	static unsigned int DB_books_add=8;
	static unsigned int DB_borrower_search=16;
	static unsigned int DB_borrower_up=32;
	static unsigned int DB_borrower_del=64;
	static unsigned int DB_borrower_add=128;
	static unsigned int DB_manager_search=256;
	static unsigned int DB_manager_up=512;
	static unsigned int DB_manager_del=1024;
	static unsigned int DB_manager_add=2048;
}

namespace privilege_id_states
{
	static string ONLINE="online";
	static string OUTLINE="outline";
}


class Privilege
{
public:
	Privilege(void);
	void Privilege_connect(DB db);
	~Privilege(void);
	string login(string ID,string password);
	string logout(void);
	string access(int sutmitprivilege);//Access identify
	bool privilege_user_flag;
	string RecentID;
private:
	string RecentIDState;
	DB db;
	DB_books db_books;
	DB_borrower db_borrower;
	DB_manager db_manager;

};

