#pragma once
#include<string>
using namespace std;
#include"Book.h"

#ifndef def_SQL_books
#define def_SQL_books
namespace SQL_books
{
	static string SQL_subID="subID";
	static string SQL_state="state";
	static string SQL_ID="ID";
}
#endif

#ifndef def_books_state
#define def_books_state
namespace books_state
{
	static unsigned int WAIT=1;
	static unsigned int RENT=2;
	static unsigned int LOCK=3;
}

#endif

class Books
	:public Book
{
public:
	int subID;//duplicates ID
	int state;//one book's state
	string ID;//who borrowe the book;
	Books(void);
	~Books(void);
};

