#include "DB_books.h"


DB_books::DB_books(void)
{
	//cout<<"析构 db_books";
	//cout<<"析构 db_books OK";
	/*
	string temp=init();
	if(!temp.empty())
		create_table();
		*/
}
void DB_books::DB_books_connect(DB db)
{
	//cout<<"析构 db_books";
	this->db=db;
	//cout<<"析构 db_books OK";
}


DB_books::~DB_books(void)
{
}


string DB_books::add(Books b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	char trans_price[32];
	_itoa_s(b.price,trans_price,10);
	string str_price=trans_price;
	char trans_subID[32];
	_itoa_s(b.subID,trans_subID,10);
	string str_subID=trans_subID;
	char trans_state[32];
	_itoa_s(b.state,trans_state,10);
	string str_state=trans_state;
	
	temp.clear();
	temp+="INSERT INTO";
	temp+=" Books";
	temp+=" (";
	temp+=" "+SQL_book::SQL_ISBN;
	temp+=","+SQL_book::SQL_CLCN;
	temp+=","+SQL_book::SQL_name;
	temp+=","+SQL_book::SQL_writer;
	temp+=","+SQL_book::SQL_printers;
	temp+=","+SQL_book::SQL_price;
	temp+=","+SQL_book::SQL_remark;
	temp+=","+SQL_books::SQL_subID;
	temp+=","+SQL_books::SQL_state;
	temp+=","+SQL_books::SQL_ID;
	temp+=")";
	temp+="VALUES (";
	temp+=" '"+b.ISBN+"'";
	temp+=",'"+b.CLCN+"'";
	temp+=",'"+b.name+"'";
	temp+=",'"+b.writer+"'";
	temp+=",'"+b.printers+"'";
	temp+=","+str_price;
	temp+=",'"+b.remark+"'";
	temp+=","+str_subID;
	temp+=","+str_state;
	temp+=",'"+b.ID+"'";
	temp+=")";

	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	return string("");
}


string DB_books::del(Books b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	Books b_temp=b;
	if(!search(b_temp).empty())
		return string("<DB_Books.del> row isn't exist");


	char trans_subid[32];
	_itoa_s(b.subID,trans_subid,10);
	string str_subID=trans_subid;

	temp.clear();
	temp+="DELETE FROM";

	temp+=" Books";

	temp+=" WHERE";
	temp+=" books."+SQL_book::SQL_ISBN+" = '"+b.ISBN+"'";
	temp+=" AND";
	temp+=" books."+SQL_books::SQL_subID+" = "+str_subID;
	
	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}


string DB_books::up(Books b)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	Books b_temp=b;
	if(!search(b_temp).empty())
		return string("<DB_Books.up> row isn't exist");

	char trans_subid[32];
	_itoa_s(b.subID,trans_subid,10);
	string str_subid=trans_subid;

	temp.clear();
	temp+="UPDATE Books";
	temp+=" SET";

	temp+=" "+SQL_book::SQL_ISBN+" ='"+b.ISBN+"'";
	if(!b.CLCN.empty())
		temp+=","+SQL_book::SQL_CLCN+" ='"+b.CLCN+"'";
	if(!b.name.empty())
		temp+=","+SQL_book::SQL_name+" ='"+b.name+"'";
	if(!b.writer.empty())
		temp+=","+SQL_book::SQL_writer+" ='"+b.writer+"'";
	if(!b.printers.empty())
		temp+=","+SQL_book::SQL_printers+" ='"+b.printers+"'";
	if(b.price)
	{
		char trans_price[32];
		_itoa_s(b.price,trans_price,10);
		string str_price=trans_price;
		temp+=","+SQL_book::SQL_price+" ="+str_price;
	}
	if(!b.remark.empty())
		temp+=","+SQL_book::SQL_remark+" ='"+b.remark+"'";
	if(b.state)
	{
		char trans_state[32];
		_itoa_s(b.state,trans_state,10);
		string str_price=trans_state;
		temp+=","+SQL_book::SQL_price+" ="+str_price;
	}
	if(!b.ID.empty())
		temp+=","+SQL_books::SQL_ID+" ='"+b.ID+"'";


	temp+=" WHERE";
	temp+=" books."+SQL_book::SQL_ISBN+" = '"+b.ISBN+"'";
	temp+=" AND books."+SQL_books::SQL_subID+" = "+str_subid;

	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}

//search a book by its ISBN and subID
string DB_books::search(Books &b)
{
	//cout<<"fuck 0"<<endl;
	
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	//cout<<"fuck 1"<<endl;

	char trans_subid[32];
	_itoa_s(b.subID,trans_subid,10);
	//cout<<trans_subid<<endl;
	string str_subid=trans_subid;

	//cout<<str_subid<<endl;
	//cout<<"fuck 2"<<endl;

	temp.clear();
	temp+="SELECT";
	temp+=" "+SQL_book::SQL_ISBN;
	temp+=","+SQL_book::SQL_CLCN;
	temp+=","+SQL_book::SQL_name;
	temp+=","+SQL_book::SQL_writer;
	temp+=","+SQL_book::SQL_printers;
	temp+=","+SQL_book::SQL_price;
	temp+=","+SQL_book::SQL_remark;
	temp+=","+SQL_books::SQL_subID;
	temp+=","+SQL_books::SQL_state;
	temp+=","+SQL_books::SQL_ID;

	temp+=" FROM";
	temp+=" books";
	temp+=" WHERE";
	temp+=" books."+SQL_book::SQL_ISBN+" = '"+b.ISBN+"'";
	temp+=" AND books."+SQL_books::SQL_subID+" = "+str_subid;
	
	//cout<<temp<<endl;

	//cout<<"fuck 3"<<endl;
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
		b.ISBN=row[0];
		//cout<<"cao 99"<<endl;
		b.CLCN=row[1];
		//cout<<"cao 100"<<endl;
		b.name=row[2];
		b.writer=row[3];
		//cout<<"cao 200"<<endl;
		b.printers=row[4];
		b.price=atoi(row[5]);
		//cout<<"cao 400"<<endl;
		b.remark=row[6];
		b.subID=atoi(row[7]);
		//cout<<"cao 800"<<endl;
		b.state=atoi(row[8]);
		b.ID=row[9];
		//cout<<"cao 1000"<<endl;
		return string("");
	}
	else
		return string("<DB_books.Search> row isn't exist");
	//cout<<"cao 2"<<endl;
}

//whether the books table is exist;
string DB_books::init(void)
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
	temp+="SELECT TABLE_NAME FROM information_schema.tables WHERE TABLE_NAME='Books'";
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
		return string("<DB_books.init> TABLE:[ Books ] isn't exist");
	else
		return string("");
	
}


string DB_books::create_table(void)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	temp.clear();
	temp+="CREATE TABLE Books (";
	temp+=SQL_book::SQL_ISBN+" CHAR(16)";
	temp+=","+SQL_book::SQL_CLCN+" CHAR(64)";
	temp+=","+SQL_book::SQL_name+" CHAR(64)";
	temp+=","+SQL_book::SQL_writer+" CHAR(64) NOT NULL";
	temp+=","+SQL_book::SQL_printers+" CHAR(64)";
	temp+=","+SQL_book::SQL_price+" INTEGER";
	temp+=","+SQL_book::SQL_remark+" VARCHAR(64)";
	temp+=","+SQL_books::SQL_subID+" INTEGER";
	temp+=","+SQL_books::SQL_state+" INTEGER NOT NULL CHECK(state BETWEEN 1 AND 3)";
	temp+=","+SQL_books::SQL_ID+" CHAR(64)";

	temp+=",PRIMARY KEY(";
	temp+=" "+SQL_book::SQL_ISBN;
	temp+=","+SQL_books::SQL_subID;
	temp+=" )";

	//temp+=",FOREIGN KEY("+SQL_books::SQL_ID+")REFERENCES borrower("+SQL_books::SQL_ID+")";

	temp+=")";
	db.query(temp);

	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}

