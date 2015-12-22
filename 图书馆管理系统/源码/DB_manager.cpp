#include "DB_manager.h"


DB_manager::DB_manager(void)
{
	/*
	string temp=init();
	if(!temp.empty())
		create_table();
		*/
}
void DB_manager::DB_manager_connect(DB db)
{
	this->db=db;
}


DB_manager::~DB_manager(void)
{
}


string DB_manager::add(Manager m)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	char trans_privilege[32];
	_itoa_s(m.privilege,trans_privilege,10);
	string str_privilege=trans_privilege;
	
	char trans_salary[32];
	_itoa_s(m.salary,trans_salary,10);
	string str_salary=trans_salary;


	temp.clear();
	temp+="INSERT INTO";
	temp+=" Manager";
	temp+=" (";
	temp+=" "+SQL_role::SQL_ID;
	temp+=","+SQL_role::SQL_password;
	temp+=","+SQL_role::SQL_name;
	temp+=","+SQL_role::SQL_privilege;
	temp+=","+SQL_role::SQL_address;
	temp+=","+SQL_manager::SQL_worktime;
	temp+=","+SQL_manager::SQL_salary;

	temp+=")";
	temp+="VALUES (";
	temp+=" '"+m.ID+"'";
	temp+=",'"+m.password+"'";
	temp+=",'"+m.name+"'";
	temp+=","+str_privilege;
	temp+=",'"+m.address+"'";
	temp+=",'"+m.worktime+"'";
	temp+=","+str_salary;
	temp+=")";

	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	return string("");
}


string DB_manager::del(Manager m)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	Manager m_temp=m;
	if(!search(m_temp).empty())
		return string("<DB_Manager.del> row isn't exist");


	temp.clear();
	temp+="DELETE FROM";

	temp+=" Manager";

	temp+=" WHERE";
	temp+=" manager."+SQL_role::SQL_ID+" = '"+m.ID+"'";
	
	cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
}


string DB_manager::up(Manager m)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	Manager m_temp=m;
	if(!search(m_temp).empty())
		return string("<DB_Manager.up> row isn't exist");


	temp.clear();
	temp+="UPDATE Manager";
	temp+=" SET";

	temp+=" "+SQL_role::SQL_ID+" ='"+m.ID+"'";
	if(!m.password.empty())
		temp+=","+SQL_role::SQL_password+" ='"+m.password+"'";
	if(!m.name.empty())
		temp+=","+SQL_role::SQL_name+" ='"+m.name+"'";
	if(m.privilege)
	{
		char trans_privilege[32];
		_itoa_s(m.privilege,trans_privilege,10);
		string str_privilege=trans_privilege;
		temp+=","+SQL_role::SQL_privilege+" ="+str_privilege;
	}
	if(!m.address.empty())
		temp+=","+SQL_role::SQL_address+" ='"+m.address+"'";
	if(m.salary)
	{
		char trans_salary[32];
		_itoa_s(m.salary,trans_salary,10);
		string str_salary=trans_salary;
		temp+=","+SQL_manager::SQL_salary+" ="+str_salary;
	}
	if(!m.worktime.empty())
		temp+=","+SQL_manager::SQL_worktime+" ='"+m.worktime+"'";


	temp+=" WHERE";
	temp+=" manager."+SQL_role::SQL_ID+" = '"+m.ID+"'";

	//cout<<temp<<endl;

	db.query(temp);
	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
	return string();
}


string DB_manager::search(Manager &m)
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
	temp+=","+SQL_manager::SQL_worktime;
	temp+=","+SQL_manager::SQL_salary;

	temp+=" FROM";
	temp+=" manager";
	temp+=" WHERE";
	temp+=" manager."+SQL_role::SQL_ID+" = '"+m.ID+"'";
	
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

	if(mysql_num_rows(mysql_res))
	{
		m.ID=row[0];
		m.password=row[1];
		m.name=row[2];
		m.privilege=atoi(row[3]);
		m.address=row[4];
		m.worktime=row[5];
		m.salary=atoi(row[6]);
		/*
	cout<<SQL_role::SQL_ID<<":"<<m.ID<<endl;
	cout<<SQL_role::SQL_password<<":"<<m.password<<endl;
	cout<<SQL_role::SQL_name<<":"<<m.name<<endl;
	cout<<SQL_role::SQL_privilege<<":"<<m.privilege<<endl;
	cout<<SQL_role::SQL_address<<":"<<m.address<<endl;
	cout<<SQL_manager::SQL_worktime<<":"<<m.worktime<<endl;
	cout<<SQL_manager::SQL_salary<<":"<<m.salary<<endl;
	*/
		return string("");
	}
	else
		return string("<DB_manager.Search> row isn't exist");
}


string DB_manager::init(void)
{
	string temp="information_schema";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;
	
	//cout<<"fuck 1"<<endl;

	temp.clear();
	temp+="SELECT TABLE_NAME FROM information_schema.tables WHERE TABLE_NAME='Manager'";
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
		return string("<DB_Manager.init> TABLE:[ Manager ] isn't exist");
	else
		return string("");
	return false;
}


string DB_manager::create_table(void)
{
	string temp="library";
	mysql_select_db(db.mysql,temp.c_str());
	temp.clear();
	temp+=mysql_error(db.mysql);
	if(!temp.empty())
		return temp;

	temp.clear();
	temp+="CREATE TABLE Manager (";
	temp+=SQL_role::SQL_ID+" CHAR(64)";
	temp+=","+SQL_role::SQL_password+" CHAR(64) NOT NULL";
	temp+=","+SQL_role::SQL_name+" CHAR(64)";
	temp+=","+SQL_role::SQL_privilege+" INTEGER";
	temp+=","+SQL_role::SQL_address+" CHAR(64)";
	temp+=","+SQL_manager::SQL_worktime+" CHAR(64)";
	temp+=","+SQL_manager::SQL_salary+" INTEGER";
	temp+=",PRIMARY KEY (ID)";

	temp+=")";
	db.query(temp);

	temp.clear();
	temp+=mysql_error(db.mysql);
	return temp;
	return string();
}
