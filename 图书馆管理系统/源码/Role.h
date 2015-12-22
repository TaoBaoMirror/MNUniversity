#pragma once
#include<string>
using namespace std;

#ifndef def_SQL_role
#define def_SQL_role

namespace SQL_role
{
	static string SQL_ID="ID";
	static string SQL_password="password";
	static string SQL_name="name";
	static string SQL_privilege="privilege";
	static string SQL_address="address";
}

#endif

class Role
{
public:
	string ID;
	string password;
	string name;
	int privilege;
	string address;
	Role(void);
	~Role(void);
};

