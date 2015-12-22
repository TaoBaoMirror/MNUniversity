#pragma once
#include "role.h"
#include<iostream>
using namespace std;

#ifndef def_SQL_borrower
#define def_SQL_borrower

namespace SQL_borrower
{
	static string SQL_bookslimit="bookslimit";
}
#endif

class Borrower :
	public Role
{
public:
	int bookslimit;
	Borrower(void);
	~Borrower(void);
};

