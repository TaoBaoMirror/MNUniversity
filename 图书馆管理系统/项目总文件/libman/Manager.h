#pragma once
#include<string>
using namespace std;
#include "role.h"


#ifndef def_SQL_manager
#define def_SQL_manager

namespace SQL_manager
{
	static string SQL_worktime="worktime";
	static string SQL_salary="salary";
}


#endif

class Manager :
	public Role
{
public:
	string worktime;
	int salary;
	Manager(void);
	~Manager(void);
	void operator=(Manager m);
};

