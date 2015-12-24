#ifndef _Graphic_Matrix_h
#define _Graphic_Matrix_h
#include<cstdlib>
#include<iostream>
using namespace std;

#include"Graphic_Virtual.h"


template<class T>
class MGraphic:public Graphic<T>
{
public:
	MGraphic(int);
	MGraphic(int,T);
	~MGraphic();
	void print();
	int exist(int,int);
	int remove(int,int);
	int insert(int,int);
	int insert(int,int,T);
protected:
	T **matrix;						//指针数组
	T Noedges_user;
private:
	T Noedges_system;
};

template<class T>
MGraphic<T>::MGraphic(int maxsize)
{
	//cout<<"MGraphic正在构造______>"<<endl;
	e=0;
	n=maxsize;
	Noedges_system=0x7fff;
	Noedges_user=Noedges_system;
	//cout<<"sizeof(Noedges_system)"<<sizeof(Noedges_system)<<endl;
	matrix=new T*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new T[n];
		for(int j=0;j<n;j++)
			matrix[i][j]=Noedges_system;
		matrix[i][i]=0;
	}
	//cout<<"MGraphic构造完毕______>"<<endl;
}

template<class T>
MGraphic<T>::MGraphic(int maxsize,T _noedges)
{
	e=0;
	n=maxsize;
	Noedges_user=_noedges;
	Noedges_system=Noedges_user;
	matrix=new T*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new T[n];
		for(int j=0;j<n;j++)
			matrix[i][j]=Noedges_user;
		matrix[i][i]=0;
	}
}

template<class T>
MGraphic<T>::~MGraphic()
{
	delete[] matrix;
}

template<class T>
int MGraphic<T>::exist(int u,int v)
{
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1)||matrix[u][v]==Noedges_user)
		return 0;
	else
		return 1;
}

template<class T>
int MGraphic<T>::insert(int u,int v)
{
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
	{
		cout<<"MGraphic<T>::insert("<<u<<","<<v<<")溢出______>"<<endl;
		return 0;
	}
	else
	{
		//cout<<"MGraphic<T>::insert("<<u<<","<<v<<")成功______>"<<endl;
		matrix[u][v]=1;
		e++;
		return 1;
	}
		
}

template<class T>
int MGraphic<T>::insert(int u,int v,T w)
{
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
	{
		cout<<"MGraphic<T>::insert("<<u<<","<<v<<")溢出______>"<<endl;
		return 0;
	}
	else
	{
		matrix[u][v]=w;
		e++;
		//cout<<"MGraphic<T>::insert("<<u<<","<<v<<")成功______>"<<endl;
		return 1;
	}
}

template<class T>
int MGraphic<T>::remove(int u,int v)
{
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
		return 0;
	else if(matrix[u][v]==Noedges_user)
		return 2;
	else
	{
		matrix[u][v]=Noedges_user;
		e--;
		return 1;
	}
}

template<class T>
void MGraphic<T>::print()
{
	cout<<"Matrix数组："<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]>=Noedges_user)
				cout<<"*"<<"\t";
			else
				cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<"数组打印完毕______>"<<endl;
}

#endif