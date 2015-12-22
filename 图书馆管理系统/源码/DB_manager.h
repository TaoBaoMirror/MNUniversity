#pragma once
#include<iostream>
#include<string>
#include"Manager.h"
#include"DB.h"
using namespace std;
class DB_manager
{
public:
	DB_manager(void);
	void DB_manager_connect(DB db);
	~DB_manager(void);
	string add(Manager m);
	string del(Manager m);
	string up(Manager m);
	string search(Manager &m);
	string init(void);
private:
	DB db;
public:
	string create_table(void);
};

