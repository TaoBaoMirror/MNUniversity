#ifndef codernode_h
#define codernode_h

//¹þ¸¥Âü±àÂëÀà
#include<iostream>
#include<cstring>
using namespace std;

template<class T>
class codernode
{
public:
	void updateweight(T);
	void updatecode(char*);
	void updatechar(char*);
	void print();
	T weight;
	char strings[10];
	char *code;
protected:
private:
};
template<class T>
void codernode<T>::print()
{
	cout<<weight<<"     "<<character<<"    "<<code<<"     ";
}
template<class T>
void codernode<T>::updateweight(T x)
{
	weight=x;
}
template<class T>
void codernode<T>::updatecode(char*p)
{
	code=p;
}
template<class T>
void codernode<T>::updatechar(char*s)
{
	strcpy_s(strings,strlen(s),s);
}

#endif