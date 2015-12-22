#ifndef LinearList_Sequence_h
#define LinearList_Sequence_h


#include<iostream>
using namespace std;

#include"LinearList_Virtual.h"

//֧��int,char,int*,char*,���͵ı���
template<class T>
class Sequence:public LinearList<T>
{
public:
	Sequence(int);
	Sequence(T*,int,int);
	~Sequence();
	
	bool insert(int,T);
	bool update(int,T);
	bool remove(int);
	int search(T);
	int exist(T);
	T backdata(int);
protected:
private:
	T*matrix;
	int maxsize;

	int check_error(int);
	enum error{noexist=-1,overflow=1};
};

template<class T>
Sequence<T>::Sequence(int max_size)
{
	cout<<"Sequence ���ڹ���______>"<<endl;
	matrix=new T[max_size];
	maxsize=max_size;
	cout<<"Sequence �������______>"<<endl;
}

template<class T>
Sequence<T>::Sequence(T*temp,int max_size,int length)//�˹��캯��ֻ����new��temp�������������������
{
	cout<<"Sequence ���ڹ���______>"<<endl;
	unsigned int is=0,ok=0;
	matrix=new T[max_size];
	maxsize=max_size;
	len=length;
	for(int i=0;i<length;i++)
	{
		matrix[i]=temp[i];
	}
	cout<<"Sequence �������______>"<<endl;
}



template<class T>
Sequence<T>::~Sequence()
{
	cout<<"Sequence ��������______>"<<endl;
	delete[]matrix;
	cout<<"Sequence �������______>"<<endl;
}

template<class T>
int Sequence<T>::exist(T x)
{
	int count=0;
	for(int i=0;i<maxsize;i++)
	{
		if(x==matrix[i])
			count++;
	}
	return count;
}

template<class T>
bool Sequence<T>::update(int index,T temp)
{
	cout<<"���ڸ���______> ("<<index<<","<<temp<<")"<<endl;
	if(check_error(index))
		exit(0);
	matrix[index]=temp;
	cout<<"�������______>"<<endl;
	return true;
}


template<class T>
bool Sequence<T>::insert(int index,T temp)
{
	cout<<"���ڲ���______> ("<<index<<","<<temp<<")"<<endl;
	if(check_error(index))
		exit(0);
	for(int i=len-1;i>index;i--)
		matrix[i+1]=matrix[i];
	matrix[index]=temp;
	len++;
	cout<<"�������______>"<<endl;
	return true;
}


template<class T>
bool Sequence<T>::remove(int index)
{
	cout<<"�����Ƴ�______> ["<<index<<"]"<<endl;
	if(check_error(index))
		exit(0);
	for(int i=index;i<len-1;i++)
		matrix[i]=matrix[i+1];
	len--;
	cout<<"�Ƴ����______>"<<endl;
	return true;
}

template<class T>
int Sequence<T>::search(T temp)
{
	if(exist(temp))
	{
		int i=0;
		while(i<len&&matrix[i]!=temp)
			i++;
		return i;
	}
	else
		return noexist;
}

template<class T>
T Sequence<T>::backdata(int index)
{
	if(check_error(index))
		exit(0);
	if(index<len)
		return matrix[index];
	else
	{
		cout<<"�Ƿ�����______> ["<<index<<"]"<<endl;
		exit(0);
	}
}

template<class T>
int Sequence<T>::check_error(int index)//����±��������
{
	if(index>maxsize-1||index<0)
	{
		cout<<"���______>"<<endl;
		return overflow;
	}
	else
		return 0;//0����û����
}


#endif