#include "DB.h"
#include<iostream>
using namespace std;

DB::DB(void)
{
	port=0;
	unix_socket="";
	client_flag=0;
	mysql_init(&inner_mysql);
	mysql=&inner_mysql;
	connect_flag=false;
}


DB::~DB(void)
{
}

void DB::operator=(DB db)
{
	this->mysql=db.mysql;
	this->client_flag=db.client_flag;
	this->port=db.port;
	this->unix_socket=db.unix_socket;
}

//connect to database
string DB::connect(string host, string user, string password, string database)
{
	//cout<<user<<endl;
	//cout<<password<<endl;
	mysql_real_connect(mysql,\
		host.c_str(),\
		user.c_str(),\
		password.c_str(),\
		database.c_str(),
		port,\
		unix_socket.c_str(),\
		client_flag);

	string temp=mysql_error(mysql);
	if(temp.empty())
	{
		temp+="Connecting DataBase ";
		temp+=database;
		temp+=" OK";
		connect_flag=true;
		return temp;
	}
	else
		return temp;
}

//SQL QL&DDL syntax
string DB::query(string operation)
{
	mysql_real_query(mysql,operation.c_str(),operation.size());
	string temp=mysql_error(mysql);
	return temp;
}
