#include "DB_borrower.h"


DB_borrower::DB_borrower(void)
{
	/*
	string temp=init();
	if(!temp.empty())
		create_table();
		*/
}

void DB_borrower::DB_borrower_connect(DB db)
{
	this->db=db;
}


DB_borrower::~DB_borrower(void)
{
}


string DB_borrower::add(Borrower b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	char trans_privilege[32];
	_itoa_s(b.privilege,trans_privilege,10);
	string str_privilege=trans_privilege;

	char trans_bookslimit[32];
	_itoa_s(b.privilege,trans_bookslimit,10);
	string str_bookslimit=trans_bookslimit;

	temp.clear();
	temp+="INSERT INTO";
	temp+=" Borrower";
	temp+=" (";
	temp+=" "+SQL_role::SQL_ID;
	temp+=","+SQL_role::SQL_password;
	temp+=","+SQL_role::SQL_name;
	temp+=","+SQL_role::SQL_privilege;
	temp+=","+SQL_role::SQL_address;
	temp+=","+SQL_borrower::SQL_bookslimit;

	temp+=")";
	temp+="VALUES (";
	temp+=" '"+b.ID+"'";
	temp+=",'"+b.password+"'";
	temp+=",'"+b.name+"'";
	temp+=","+str_privilege;
	temp+=",'"+b.address+"'";
	temp+=","+str_bookslimit;
	temp+=")";

	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	return string("");
}


string DB_borrower::del(Borrower b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	Borrower b_temp=b;
	if(!search(b_temp).empty())
		return string("<DB_Borrower.del> row isn't exist");


	temp.clear();
	temp+="DELETE FROM";

	temp+=" Borrower";

	temp+=" WHERE";
	temp+=" borrower."+SQL_role::SQL_ID+" = '"+b.ID+"'";
	
	cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}


string DB_borrower::up(Borrower b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	Borrower b_temp=b;
	if(!search(b_temp).empty())
		return string("<DB_Borrower.up> row isn't exist");


	temp.clear();
	temp+="UPDATE borrower";
	temp+=" SET";

	temp+=" "+SQL_role::SQL_ID+" ='"+b.ID+"'";
	if(!b.password.empty())
		temp+=","+SQL_role::SQL_password+" ='"+b.password+"'";
	if(!b.name.empty())
		temp+=","+SQL_role::SQL_name+" ='"+b.name+"'";
	if(b.privilege)
	{
		char trans_privilege[32];
		_itoa_s(b.privilege,trans_privilege,10);
		string str_privilege=trans_privilege;
		temp+=","+SQL_role::SQL_privilege+" ="+str_privilege;
	}
	if(!b.address.empty())
		temp+=","+SQL_role::SQL_address+" ='"+b.address+"'";
	if(b.bookslimit)
	{
		char trans_bookslimit[32];
		_itoa_s(b.bookslimit,trans_bookslimit,10);
		string str_bookslimit=trans_bookslimit;
		temp+=","+SQL_borrower::SQL_bookslimit+" ="+str_bookslimit;
	}

	temp+=" WHERE";
	temp+=" borrower."+SQL_role::SQL_ID+" = '"+b.ID+"'";

	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}


string DB_borrower::search(Borrower &b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;


	temp.clear();
	temp+="SELECT";
	temp+=" "+SQL_role::SQL_ID;
	temp+=","+SQL_role::SQL_password;
	temp+=","+SQL_role::SQL_name;
	temp+=","+SQL_role::SQL_privilege;
	temp+=","+SQL_role::SQL_address;
	temp+=","+SQL_borrower::SQL_bookslimit;

	temp+=" FROM";
	temp+=" borrower";
	temp+=" WHERE";
	temp+=" borrower."+SQL_role::SQL_ID+" = '"+b.ID+"'";
	
	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	//cout<<"fuck 4"<<endl;

	MYSQL_RES *mysql_res=mysql_store_result(db.mysql);
	MYSQL_ROW row=mysql_fetch_row(mysql_res);
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	//cout<<"cao 1"<<endl;
	if(mysql_num_rows(mysql_res))
	{
		//cout<<"cao 98"<<endl;
		b.ID=row[0];
		//cout<<"cao 99"<<endl;
		b.password=row[1];
		//cout<<"cao 100"<<endl;
		b.name=row[2];
		b.privilege=atoi(row[3]);
		//cout<<"cao 200"<<endl;
		b.address=row[4];
		b.bookslimit=atoi(row[5]);
		return string("");
	}
	else
		return string("<DB_borrower.Search> row isn't exist");
}


string DB_borrower::init(void)
{
	//cout<<"fuck 0"<<endl;

	string temp="information_schema";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	//cout<<"fuck 1"<<endl;

	temp.clear();
	temp+="SELECT TABLE_NAME FROM information_schema.tables WHERE TABLE_NAME='Borrower'";
	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	//cout<<"fuck 2"<<endl;

	MYSQL_RES *mysql_res=mysql_store_result(db.mysql);
	MYSQL_ROW row=mysql_fetch_row(mysql_res);
	
	//cout<<"fuck 3"<<endl;

	if(NULL==row)
		return string("<DB_Borrower.init> TABLE:[ Borrower ] isn't exist");
	else
		return string("");
}


string DB_borrower::create_table(void)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	temp.clear();
	temp+="CREATE TABLE Borrower (";
	temp+=SQL_role::SQL_ID+" CHAR(64)";
	temp+=","+SQL_role::SQL_password+" CHAR(64) NOT NULL";
	temp+=","+SQL_role::SQL_name+" CHAR(64)";
	temp+=","+SQL_role::SQL_privilege+" INTEGER";
	temp+=","+SQL_role::SQL_address+" CHAR(64)";
	temp+=","+SQL_borrower::SQL_bookslimit+" INTEGER";
	temp+=",PRIMARY KEY (ID)";

	temp+=")";
	db.query(temp);

	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}
