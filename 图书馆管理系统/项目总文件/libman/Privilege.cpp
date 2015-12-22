#include "Privilege.h"

Privilege::Privilege(void)
{
	privilege_user_flag=false;
	RecentID=string("");
	RecentIDState=privilege_id_states::OUTLINE;
}


void Privilege::Privilege_connect(DB db)
{
	this->db=db;
	db_books.DB_books_connect(this->db);
	db_manager.DB_manager_connect(this->db);
	db_borrower.DB_borrower_connect(this->db);
}


Privilege::~Privilege(void)
{
}


string Privilege::login(string ID,string password)
{
	Borrower b;
	Manager m;
	b.ID=ID;
	m.ID=ID;
	db_borrower.search(b);
	db_manager.search(m);

	//cout<<SQL_role::SQL_ID<<":"<<b.ID<<endl;
	//cout<<SQL_role::SQL_password<<":"<<b.password<<endl;
	//cout<<SQL_role::SQL_privilege<<":"<<b.privilege<<endl;


	//cout<<SQL_role::SQL_ID<<":"<<m.ID<<endl;
	//cout<<SQL_role::SQL_password<<":"<<m.password<<endl;
	//cout<<SQL_role::SQL_privilege<<":"<<m.privilege<<endl;

	if(b.password==password)
	{
		privilege_user_flag=true;
		RecentID=ID;
		RecentIDState=privilege_id_states::ONLINE;
		return string("");
	}
	else if(m.password==password)
	{
		privilege_user_flag=true;
		RecentID=ID;
		RecentIDState=privilege_id_states::ONLINE;
		return string("");
	}
	else
		return string("Login [FALSE]");
}

string Privilege::logout(void)
{
	RecentID.clear();
	RecentIDState=privilege_id_states::OUTLINE;
	privilege_user_flag=false;
	return string("");
}

string Privilege::access(int sutmitprivilege)//just submit one kind of privilege_codes;
{
	//cout<<"------------->>>>>>sutmitprivilege:"<<sutmitprivilege<<endl;
	if(RecentID.empty())
		return string("Login Requirement");
	Borrower b;
	Manager m;
	b.ID=RecentID;
	m.ID=RecentID;
	db_borrower.search(b);
	db_manager.search(m);

	
	//cout<<"-------------borrower_privilege:"<<b.privilege<<endl;
	//cout<<"-------------manager_privilege:"<<m.privilege<<endl;

	int real_privilege=0;
	if(b.privilege>m.privilege)
		real_privilege=b.privilege;
	else
		real_privilege=m.privilege;
	//cout<<"-------------real_privilege:"<<real_privilege<<endl;
	//cout<<"-------------sutmitprivilege:"<<sutmitprivilege<<endl;
	int identified=real_privilege & sutmitprivilege;

	if(identified)
		return string("");
	else
		return string("Access denied");
}