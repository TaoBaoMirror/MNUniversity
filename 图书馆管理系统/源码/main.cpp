#include<iostream>
#include<string>
#include<winsock2.h>
#include<mysql.h>
#include<conio.h>
#include "Privilege.h"
#include"client.h"
#include"Viewer.h"
using namespace std;
int main()
{

	DB db;
	/*
	cout<<db.connect("localhost","root","lizhi","")<<endl;
	DB_books b;
	DB_borrower br;
	DB_manager m;
	b.DB_books_connect(db);
	br.DB_borrower_connect(db);
	m.DB_manager_connect(db);
	b.create_table();
	br.create_table();
	m.create_table();
	system("pause");
	*/
	Client client;
	Privilege privilege;
	Books books;
	Borrower borrower;
	Manager manager;

	DB_borrower db_borrower;

	Viewer viewer;
	int options=0;
	string user,password;
	string error;
	int menu_operation=0;

	viewer.welcome();

	
	
	while(TRUE)
	{
		switch(options)
		{
		case 0:
			viewer.clear_workspace();
			options=viewer.window();
			break;
		case 1:
			viewer.clear_workspace();
			user.clear();
			password.clear();
			viewer.login(user,password);
			error=db.connect("localhost",user,password,"");
			viewer.user_state("localhost@"+user,error);
			options=0;
			break;
		case 2:
			viewer.clear_workspace();
			if(db.connect_flag==false)
			{
				error="Please connect database";
				viewer.user_state(user,error);
				options=0;
				break;
			}
			user.clear();
			password.clear();
			viewer.login(user,password);
			privilege.Privilege_connect(db);
			error=privilege.login(user,password);
			viewer.user_state(user,error);
			options=0;
			break;
		case 3:
			privilege.logout();
			error="Login out";
			viewer.user_state(user,error);
			options=0;
			break;
		case 4:
			viewer.clear_workspace();
			switch((menu_operation=viewer.menu()))
			{
			case 1:
			case 2:
			case 4:
			case 8:
				
				if(db.connect_flag==false)
				{
					error="Please connect database";
					viewer.user_state(user,error);
					options=0;
					break;
				}
				client.Client_connect(db,privilege);
				if(privilege.privilege_user_flag==false)
				{
					error="Login Requirement";
					viewer.user_state(user,error);
					options=0;
					break;
				}
				viewer.clear_workspace();
				books=viewer.get_books();
				error=client.center(menu_operation,books,borrower,manager);
				viewer.user_state(user,error);
				viewer.clear_workspace();
				if(error.empty())
					viewer.show_books(books);
				options=0;
				_getch();
				break;
			case 16:
			case 32:
			case 64:
			case 128:
				if(db.connect_flag==false)
				{
					error="Please connect database";
					viewer.user_state(user,error);
					options=0;
					break;
				}
				client.Client_connect(db,privilege);
				if(privilege.privilege_user_flag==false)
				{
					error="Login Requirement";
					viewer.user_state(user,error);
					options=0;
					break;
				}
				viewer.clear_workspace();
				borrower=viewer.get_borrower();
				error=client.center(menu_operation,books,borrower,manager);
				viewer.user_state(user,error);
				viewer.clear_workspace();
				if(error.empty())
				viewer.show_borrower(borrower);
				options=0;
				_getch();
				break;
			case 256:
			case 512:
			case 1024:
			case 2048:
				
				if(db.connect_flag==false)
				{
					error="Please connect database";
					viewer.user_state(user,error);
					options=0;
					break;
				}
				client.Client_connect(db,privilege);
				if(privilege.privilege_user_flag==false)
				{
					error="Login Requirement";
					viewer.user_state(user,error);
					options=0;
					break;
				}
				viewer.clear_workspace();
				manager=viewer.get_manager();
				error=client.center(menu_operation,books,borrower,manager);
				viewer.user_state(user,error);
				viewer.clear_workspace();
				if(error.empty())
				viewer.show_manager(manager);
				_getch();
				options=0;
				break;
			}
		}
	}







	/*
	system("pause");
	string user,password;
	viewer.login(user,password);
	viewer.menu();

	viewer.clear_workspace();
	Books b=viewer.get_books();
	viewer.show_books(b);
	system("pause");

	viewer.clear_workspace();
	Borrower br=viewer.get_borrower();
	viewer.show_borrower(br);
	system("pause");
	

	viewer.clear_workspace();
	Manager m=viewer.get_manager();
	viewer.show_manager(m);
	system("pause");
	*/
	/*
	cout<<"���ӳ�ʼ��"<<endl;
	DB db;
	cout<<db.connect("localhost","root","lizhi","")<<endl;
	Privilege pri;
	pri.Privilege_connect(db);
	cout<<pri.login("m12345","m12345")<<endl;
	*/
	/*
	client client(db,pri);

	Books books;
	Borrower borrower;
	Manager manager;
	books.ISBN="98765432";
	borrower.ID="11003117";
	*/
	/*
	borrower.ID="11003116";
	borrower.password="11003116";
	borrower.name="���";
	borrower.privilege=1;
	borrower.address="��Ǩ";
	borrower.bookslimit=8;
	*/

	/*
	books.ISBN="9787111185260";
	books.subID=0;

	books.CLCN="TP34";
	books.name="Software Testing";
	books.writer="Ron";
	books.printers="Machine";
	books.price=30;
	books.remark="book is very good";
	books.state=books_state::LOCK;
	books.ID="11003116";
	*/

	/*
	manager.ID="m12345";
	manager.password="m12345";
	manager.name="����Ա";
	manager.privilege=4095;
	manager.address="һ¥������";
	manager.worktime="9:00~11:00;";
	manager.salary=5000;
	*/
	/*
	cout<<client.center(privilege_codes::DB_borrower_add,books,borrower,manager)<<endl;

	cout<<client.center(privilege_codes::DB_books_add,books,borrower,manager)<<endl;
	//cout<<client.center(privilege_codes::DB_manager_up,books,borrower,manager)<<endl;
	cout<<client.center(privilege_codes::DB_borrower_search,books,borrower,manager)<<endl;
	*/
	/*
	//manager��ʼ��
	cout<<"borrower��ʼ��"<<endl;
	DB_borrower db_borrower(db);
	cout<<db_borrower.init()<<endl;
	cout<<db_borrower.create_table()<<endl;
	*/
	
	/*
	//manager��ʼ��
	cout<<"manager��ʼ��"<<endl;
	DB_manager db_manager(db);
	cout<<db_manager.init()<<endl;
	cout<<db_manager.create_table()<<endl;
	*/

	/*
	//��ʼ��
	cout<<"books��ʼ��"<<endl;
	DB_books db_books(db);
	cout<<db_books.init()<<endl;
	cout<<db_books.create_table()<<endl;
	//��ʼ������
	*/

	/*
	//borrower���
	cout<<"borrower���"<<endl;
	Borrower bz;
	bz.ID="11003117";
	bz.password="11003117";
	bz.name="��־";
	bz.privilege=1;
	bz.address="�Ͼ�";
	bz.bookslimit=5;
	cout<<db_borrower.add(bz)<<endl;
	//��ӽ���
	*/

	/*
	//manager���
	cout<<"manager���"<<endl;
	Manager by;
	by.ID="m12345";
	by.password="m12345";
	by.name="����Ա";
	by.privilege=0xfff;
	by.address="һ¥������";
	by.worktime="9:00~11:00;2:00~5:00";
	by.salary=5000;
	cout<<db_manager.add(by)<<endl;
	//��ӽ���
	*/

	/*
	//books���
	cout<<"books���"<<endl;
	Books ba;
	ba.ISBN="98765432";
	ba.CLCN="TP32";
	ba.name="�������";
	ba.writer="Rose";
	ba.printers="��е��ҵ������";
	ba.price=98;
	ba.remark="greate book";
	ba.subID=0;
	ba.state=1;
	ba.ID="11003117";
	cout<<db_books.add(ba)<<endl;
	//��ӽ���
	*/

	
	/*
	//ɾ��
	cout<<"booksɾ��"<<endl;
	Books bb;
	bb.ISBN="98765432";
	bb.subID=0;
	bb.ID="3116";
	cout<<db_books.del(bb)<<endl;
	//ɾ������
	*/


	/*
	//borrowerɾ��
	cout<<"borrowerɾ��"<<endl;
	Borrower br1;
	br1.ID="11003117";
	cout<<db_borrower.del(br1)<<endl;
	//ɾ������
	*/

	
	/*
	//borrowerɾ��
	cout<<"managerɾ��"<<endl;
	Manager mr1;
	mr1.ID="m12345";
	cout<<db_manager.del(mr1)<<endl;
	//ɾ������
	*/



	/*
	//����
	cout<<"books����"<<endl;
	Books bc;
	bc.ISBN="987652";
	bc.CLCN="TP31";
	bc.name="�����ԭ��";
	bc.writer="��־";
	bc.printers="���ӳ�����";
	bc.price=980;
	bc.remark="jyjy";
	bc.subID=0;
	bc.state=1;
	bc.ID="11003117";
	cout<<db_books.up(bc)<<endl;
	//���Ľ���
	*/


	/*
	//����
	cout<<"borrower����"<<endl;
	Borrower brg;
	brg.ID="110031";
	brg.password="lizhi";
	brg.name="С����";
	brg.privilege=7;
	brg.address="����";
	brg.bookslimit=100;
	cout<<db_borrower.up(brg)<<endl;
	//���Ľ���
	*/


	/*
	//����
	cout<<"manager����"<<endl;
	Manager mrg;
	mrg.ID="m123";
	mrg.password="lissa";
	mrg.name="С���ӹ���Ա";
	mrg.privilege=7;
	mrg.address="����154";
	mrg.salary=100000;
	mrg.worktime="18:00~19:00";
	cout<<db_manager.up(mrg)<<endl;
	//���Ľ���
	*/


	
	/*
	////books��ѯ
	cout<<"books��ѯ"<<endl;
	cout<<SQL_book::SQL_ISBN<<":"<<books.ISBN<<endl;
	cout<<SQL_book::SQL_CLCN<<":"<<books.CLCN<<endl;
	cout<<SQL_book::SQL_name<<":"<<books.name<<endl;
	cout<<SQL_book::SQL_writer<<":"<<books.writer<<endl;
	cout<<SQL_book::SQL_printers<<":"<<books.printers<<endl;
	cout<<SQL_book::SQL_price<<":"<<books.price<<endl;
	cout<<SQL_book::SQL_remark<<":"<<books.remark<<endl;
	cout<<SQL_books::SQL_subID<<":"<<books.subID<<endl;
	cout<<SQL_books::SQL_state<<":"<<books.state<<endl;
	cout<<SQL_books::SQL_ID<<":"<<books.ID<<endl;
	//��ѯ����
	*/
	
	/*
	//borrower��ѯ
	cout<<"borrower��ѯ"<<endl;
	cout<<SQL_role::SQL_ID<<":"<<borrower.ID<<endl;
	cout<<SQL_role::SQL_password<<":"<<borrower.password<<endl;
	cout<<SQL_role::SQL_name<<":"<<borrower.name<<endl;
	cout<<SQL_role::SQL_privilege<<":"<<borrower.privilege<<endl;
	cout<<SQL_role::SQL_address<<":"<<borrower.address<<endl;
	cout<<SQL_borrower::SQL_bookslimit<<":"<<borrower.bookslimit<<endl;
	//��ѯ����
	*/
	/*
	//manager��ѯ
	cout<<"manager��ѯ"<<endl;
	cout<<SQL_role::SQL_ID<<":"<<manager.ID<<endl;
	cout<<SQL_role::SQL_password<<":"<<manager.password<<endl;
	cout<<SQL_role::SQL_name<<":"<<manager.name<<endl;
	cout<<SQL_role::SQL_privilege<<":"<<manager.privilege<<endl;
	cout<<SQL_role::SQL_address<<":"<<manager.address<<endl;
	cout<<SQL_manager::SQL_worktime<<":"<<manager.worktime<<endl;
	cout<<SQL_manager::SQL_salary<<":"<<manager.salary<<endl;
	//��ѯ����
	*/


	return 0;
}