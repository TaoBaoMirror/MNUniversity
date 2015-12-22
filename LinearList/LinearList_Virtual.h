#ifndef LinearList_Virtual_h
#define LinearList_Virtual_h


#include<iostream>
using namespace std;

template<class T>
class LinearList
{
public:
	int length();

	virtual bool insert(int,T)=0;
	virtual bool update(int,T)=0;
	virtual bool remove(int)=0;
	virtual int search(T)=0;
	virtual int exist(T)=0;
	virtual T backdata(int)=0;

	LinearList();
	~LinearList();
	
protected:
	int len;			//节点数
private:
};

template<class T>
LinearList<T>::LinearList()
{
	cout<<"LinearList 正在构造______>"<<endl;
	len=0;
	cout<<"LinearList 构造完成______>"<<endl;
}


template<class T>
LinearList<T>::~LinearList()
{
	cout<<"LinearList 正在析构______>"<<endl;
	cout<<"LinearList 析构完成______>"<<endl;
}



template<class T>
int LinearList<T>::length()
{
	return len;
}














#endif