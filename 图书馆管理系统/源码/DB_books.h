#pragma once
#include"DB.h"
#include"Books.h"
#include<string>
using namespace std;

class DB_books
{
public:
	DB_books();
	void DB_books_connect(DB db);
	~DB_books(void);
	string add(Books b);
	string del(Books b);
	string up(Books b);
	string search(Books &b);
	string init(void);

	string create_table(void);
private:
	DB db;
};
