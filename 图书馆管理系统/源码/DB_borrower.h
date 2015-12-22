#pragma once
#include<string>
#include"Borrower.h"
#include"DB.h"
using namespace std;
class DB_borrower
{
public:
	DB_borrower(void);
	void DB_borrower_connect(DB db);
	~DB_borrower(void);
	string add(Borrower b);
	string del(Borrower b);
	string up(Borrower b);
	string search(Borrower &b);
	string init(void);
private:
	DB db;
public:
	string create_table(void);
};

