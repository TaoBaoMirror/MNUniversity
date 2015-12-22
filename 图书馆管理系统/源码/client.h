#pragma once
#include"Books.h"
#include"Borrower.h"
#include"Manager.h"
#include"Privilege.h"
class Client
{
public:
	Client();
	void Client_connect(DB db,Privilege privilege);
	~Client(void);
	bool client_connect_flag;
	string center(int operation_codes, Books &books, Borrower &borrower, Manager &manager);
private:
	DB db;
	Privilege privilege;
	DB_books db_books;
	DB_borrower db_borrower;
	DB_manager db_manager;
};

