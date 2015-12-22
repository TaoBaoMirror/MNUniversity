#ifndef LinearList_Chain_h
#define LinearList_Chain_h


#include<iostream>
using namespace std;

#include"LinearList_Virtual.h"


template<class T>
class chain:public LinearList<T>
{
public:
	bool insert(int,T);
	bool update(int,T);
	bool remove(int);
	int search(T);
	int exist(T);
	T backdata(int);
protected:

private:

};
















#endif