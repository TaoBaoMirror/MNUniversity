#include "Manager.h"


Manager::Manager(void)
{
	ID="";
	password="";
	name="";
	privilege=0;
	address="";
	worktime="";
	salary=0;
}


Manager::~Manager(void)
{
}

void Manager::operator=(Manager m)
{
	this->ID=m.ID;
	this->address=m.address;
	this->name=m.name;
	this->password=m.password;
	this->privilege=m.privilege;
	this->salary=m.salary;
	this->worktime=m.worktime;
}