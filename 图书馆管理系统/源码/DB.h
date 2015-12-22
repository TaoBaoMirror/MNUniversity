#pragma once
#include<winsock2.h>
#include<mysql.h>
#include<string>
using namespace std;

class DB
{
public:
	DB(void);
	~DB(void);
	MYSQL *mysql;
	bool connect_flag;
	string connect(string host, string user, string password, string database);

	string query(string operation);
	void operator =(DB db);
private:
	MYSQL inner_mysql;
	unsigned int port;//connecting port
	string unix_socket;//connecting pipe
	unsigned long client_flag;//connecting additional attributes
};

