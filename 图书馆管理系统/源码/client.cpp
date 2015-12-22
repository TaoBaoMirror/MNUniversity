#include "client.h"


Client::Client()
{
	client_connect_flag=false;
}

void Client::Client_connect(DB db,Privilege privilege)
{
	this->db=db;
	this->privilege=privilege;
	this->privilege.Privilege_connect(db);
	db_books.DB_books_connect(db);
	db_borrower.DB_borrower_connect(db);
	db_manager.DB_manager_connect(db);
	if(privilege.privilege_user_flag==true)
		client_connect_flag=true;
}


Client::~Client(void)
{
}


string Client::center(int operation_codes, Books &books, Borrower &borrower, Manager &manager)
{
	//cout<<"operation_codes:"<<operation_codes<<endl;
	string temp=privilege.access(operation_codes);
	if(!temp.empty())
		return temp;

	if(operation_codes==privilege_codes::DB_books_search)
		temp=db_books.search(books);
	else if(operation_codes==privilege_codes::DB_books_up)
		temp=db_books.up(books);
	else if(operation_codes==privilege_codes::DB_books_add)
		temp=db_books.add(books);
	else if(operation_codes==privilege_codes::DB_books_del)
		temp=db_books.del(books);
	else if(operation_codes==privilege_codes::DB_borrower_search)
		temp=db_borrower.search(borrower);
	else if(operation_codes==privilege_codes::DB_borrower_up)
		temp=db_borrower.up(borrower);
	else if(operation_codes==privilege_codes::DB_borrower_add)
		temp=db_borrower.add(borrower);
	else if(operation_codes==privilege_codes::DB_borrower_del)
		temp=db_borrower.del(borrower);
	else if(operation_codes==privilege_codes::DB_manager_search)
		temp=db_manager.search(manager);
	else if(operation_codes==privilege_codes::DB_manager_del)
		temp=db_manager.del(manager);
	else if(operation_codes==privilege_codes::DB_manager_add)
		temp=db_manager.add(manager);
	else if(operation_codes==privilege_codes::DB_manager_up)
		temp=db_manager.up(manager);
	else
		temp=string("Operation code [ERROR]");
	
	return temp;
}

