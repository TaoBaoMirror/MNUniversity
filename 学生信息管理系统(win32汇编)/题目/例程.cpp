#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>

char dbfile[32]="d:\\mydb.txt";
int fileused=0;
int data_modified=0;

class Employee
{
	static int ID_Seq;
	int emp_id;
	char emp_name[20];
    int age;
    float salary;
	char department[30];
	char position[10];

public:
	Employee()
	{
		emp_id = ID_Seq ++;
	}
    void inputdata()
    {
       cout<<"The Employee Id is\t"<<emp_id<<endl;
	   cout<<"Enter Employee Name\t";
       cin>>emp_name;
       cout<<"Enter Employee age\t";
       cin>>age;
       cout<<"Enter Employee salary\t";
       cin>>salary;
       cout<<"Enter Employee department\t";
       cin>>department;
       cout<<"Enter Employee position\t";
       cin>>position;
    } 
    void showdata()
    {
       cout<<emp_id<<'\t'<<emp_name<<'\t'<<age<<'\t'<<salary<<'\t';
	   cout<<department<<'\t'<<position<<'\t';
	   cout<<endl;
    }

	int write_to_dbfile(ofstream& ofil)
	{
		ofil<<emp_id<<'\t'<<emp_name<<'\t'<<age<<'\t'<<salary<<'\t';
		ofil<<department<<'\t'<<position<<endl;
		return 1;
	}
	
	int input_from_dbfile(ifstream& ifil)
    {
		//int i=0;
		ifil>>emp_id>>emp_name>>age>>salary>>department>>position;
		if(ifil ) 
			return 1;
		else 
			return -1;
	}

    int get_emp_id()
    {
       return emp_id;
    }
    char * get_name()
    {
       return emp_name;
    }

};
int Employee::ID_Seq=0;

struct Node
{
  Employee p1;
  Node *next;

  Node(Node * n = NULL)
  {
      next=NULL;
  }
};

class List
{
private:
  Node *head,
       *tail;
public:
  List();
  ~List()
  {
    destroy ();
  }
  void addNode();
  bool delNode_by_name(char name[]);
  bool queryNode_by_name(char name[]);
  bool queryNode_by_id(int id);
  void traverse();
  void destroy();
  int write_list_to_dbfile(char filename[]);
  int read_list_from_dbfile(char filename[]);

};

List::List()
{
   head = tail = NULL;
}

void List::destroy()
{
  Node * cur;
  while(head != NULL)
  {
    cur=head;
    head = head->next;
    delete cur;
  }
  head = tail = NULL;
}

void List::addNode()
{
  Node * p;
  p = new Node();
  p->p1.inputdata();
  if(head == NULL)
  {
    head=p;
	tail=head;
  } 
  else 
  {
    tail->next=p;
	tail=p;
  }
  return;
}

bool List::queryNode_by_name(char name[])
{
   Node * p;
   int flag=0;
   if(head==NULL) return false;
   p=head;
   while(p)
   {
	   if(strcmp(p->p1.get_name(),name)==0) {
		   p->p1.showdata();
		   flag=1;
	   }
	   p=p->next;
   }
   if(flag) return true;
   else return false;
}

bool List::queryNode_by_id(int id)
{
   Node * p;
   int flag=0;
   if(head==NULL) return false;
   p=head;
   while(p)
   {
	   if(p->p1.get_emp_id()==id) {
		   p->p1.showdata();
		   flag=1;
	   }
	   p=p->next;
   }
   if(flag) return true;
   else return false;
}

void List::traverse()
{
   Node * p;
   if(head==NULL) return;
   p=head;
   while(p)
   {		   
	   p->p1.showdata();
	   p=p->next;
   }
}

bool List::delNode_by_name(char name[])
{
   Node *cur,*pre;
   int flag=0;
   if(head==NULL) return false;
   pre=NULL;
   cur=head;
   while(cur)
   {
	   if(strcmp(cur->p1.get_name(),name)==0) {
		   if(cur==head) 
		   {
			   head=cur->next;
			   if(head==NULL) tail=NULL;
		   }
		   else
		   {
			   pre->next=cur->next;
			   if(cur==tail) tail=pre;
		   }
		   delete cur;
		   return true;
	   }
	   pre=cur;
	   cur=cur->next;
   }
   return false;
}

int List::write_list_to_dbfile(char filename[])
{
	ofstream ofil=(filename);
	if(!ofil) {
       cout<<"Can not open output file: "<<filename<<endl;
	   return -1;
	}
   Node * p;
   int i;
   if(head==NULL) return -2;
   p=head;
   while(p)
   {		   
	   i=p->p1.write_to_dbfile(ofil);
	   if(i<=0) {
		   cout<<"Record write error, id="<<p->p1.get_emp_id()<<endl;
		   break;
	   }
	   p=p->next;
   }
   ofil.close();
   return 1;
}

int List::read_list_from_dbfile(char filename[])
{
	ifstream ifil=(filename);
	if(!ifil) {
       cout<<"Can not open read file: "<<filename<<endl;
	   return -1;
	}
  Node * p;
  int i;
  do { 
    p = new Node();
    i=p->p1.input_from_dbfile(ifil);
    if(i<=0) {
		delete p;
		continue;
	}
    if(head == NULL)
	{
      head=p;
	  tail=head;
	} 
    else 
	{
      tail->next=p;
	  tail=p;
	}
  } while(i>0);

  ifil.close();
  return 1;
}
 
int main()
{
/*
	List db_list;
	db_list.addNode();
	db_list.addNode();
	db_list.traverse();
    db_list.write_list_to_dbfile(dbfile);
	db_list.destroy();
	db_list.read_list_from_dbfile(dbfile);
	db_list.traverse();
*/

	List db_list;
    char ch;
    while(1)
    {
       cout << endl;
	   cout << "---------Database file operation:--" << endl;
       cout << '\t'<<"1. Create" << endl;
       cout << '\t'<<"2. Use" << endl;
       cout << '\t'<<"3. Copy" << endl;
       cout << "---------Record operation:---------" << endl;
       cout << '\t'<<"4. Insert" << endl;
       cout << '\t'<<"5. Search" << endl;
       cout << '\t'<<"6. Delete" << endl;
       cout << '\t'<<"7. Read all" << endl;
       cout << '\t'<<"8. Commit" << endl;
       cout << '\t'<<"9. Rollback" << endl;
       cout << "---------System operation:---------" << endl;
       cout << '\t'<<"x. Exit" << endl<<endl;

	   cin >> ch;
       switch(ch)
       {
          case '1':
		  { 
			  char filename[32];      
			  cout << "Enter a database file name to create: ";
			  cin.ignore();
			  cin>>filename;
              ofstream ofil=(filename);
              ofil.close();
			  char cc;
			  while(1) 
			  {
			      cout<<"Do you want to add records to the database file now (Y/N)?"<<endl;
			      cin.ignore();
			      cin>>cc;
                  if (cc=='Y' || cc=='y') {
                      db_list.addNode();
					  data_modified=1;
				  }
				  else
					  break;
			  }
              break;
		  }
          case'2':
		  { 
			  char filename[32];      
			  cout << "Enter a database file name to use: ";
			  cin.ignore();
			  cin>>filename;
              strcpy(dbfile,filename);
              break;
		  }
          case '3':
		  { 
			  cout << "Copy a dbfile ...\n"<<endl;
              break;
		  }
          case '4':
		  { 
			  db_list.addNode();
              break;
		  }
          case '5':
		  { 
			  
			  char smode;
			  char name[20];
			  int id;
			  cout << "Search by :\n\t1. NAME \n\t2. EMP_ID"<<endl;
			  cin.ignore();
			  cin>>smode;
			  switch (smode)
			  {
			     case '1':
					cout<<"Enter a name:"<<endl;
					cin.ignore();
					cin>>name;
					db_list.queryNode_by_name(name);
					break;
				 case '2':
					cout<<"Enter a id:"<<endl;
					cin.ignore();
					cin>>id;
					db_list.queryNode_by_id(id);
					break;
				 default:
					cout<<"Search mode unspported"<<endl;
					break;
			  }
              break;
		  }
          case '6':
		  { 
		     char name[20];
			 cout<<"Enter a name:"<<endl;
			 cin.ignore();
			 cin>>name;
		     db_list.delNode_by_name(name);
             break;
		  }
          case '7':
		  { 
			  cout<<"All record list :"<<endl;
			  db_list.traverse();
              break;
		  }
          case '8':
		  { 
			  char cc;
			  cout<<"Do you really to COMMIT all chanages to dbfile (Y/N)?"<<endl;
			  cin.ignore();
			  cin>>cc;
              if (cc=='Y' || cc=='y') {
				  int i=db_list.write_list_to_dbfile(dbfile);
				  if(i>0) 
					  cout<<"Commit successfully!"<<endl;
				  else
					  cout<<"Commit failed!"<<endl;
			  }
			  db_list.traverse();
              break;
		  }
          case '9':
		  { 
			  char cc;
			  int i;
			  cout<<"Do you really to CANCEL all chanages (Y/N)?"<<endl;
			  cin.ignore();
			  cin>>cc;
              if (cc=='Y' || cc=='y') {
				  db_list.destroy();
				  i=db_list.read_list_from_dbfile(dbfile);
				  if(i>0) 
				  {
					  cout<<"All chanages have been cancelled,"<<endl;
				      cout<<"Records have been reset to the point before last change!"<<endl;
				  }
				  else
					  cout<<"Rollback failed!"<<endl;
				  db_list.traverse();
			  }
              break;
		  }
          case 'x':
                exit(0);
                break;
          default:
                cout << endl << "Enter a correct choice ";
                break;
       }

	}
		
        return 0;
}
