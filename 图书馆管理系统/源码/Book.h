#pragma once
#include<iostream>
#include<string>
using namespace std;

#ifndef def_SQL_book
#define def_SQL_book

namespace SQL_book
{
	static string SQL_ISBN="ISBN";
	static string SQL_CLCN="CLCN";
	static string SQL_name="name";
	static string SQL_writer="writer";
	static string SQL_printers="printers";
	static string SQL_remark="remark";
	static string SQL_price="price";
}
#endif

class Book
{
public:
	string ISBN;
	string CLCN;
	string name;
	string writer;
	string printers;
	string remark;
	int price;
	
	Book(void);
	~Book(void);
};

