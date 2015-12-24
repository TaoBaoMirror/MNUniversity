#ifndef _Graphic_Linear_h
#define _Graphic_Linear_h

#include<iostream>
using namespace std;

#include"Graphic_Linear_Node.h"
#include"Graphic_Virtual.h"

template<class T>/*图的邻接表存储形式*/
class LGraphic:public Graphic<T>
{
public:
	int exist(int,int);
	int insert(int,int);
	int insert(int,int,T);
	int remove(int,int);

	LGraphic(int);
	~LGraphic();
protected:
	LGNode<T>**t;			//数组指针
private:
};

template<class T>
LGraphic<T>::LGraphic(int maxsize)
{
	//cout<<"LGraphic 正在构造______>"<<endl;
	n=maxsize;
	e=0;
	t=new LGNode<T>*[n];
	memset(t,0,n*sizeof(int));
	//cout<<"LGraphic 构造完成______>"<<endl;
}

template<class T>
LGraphic<T>::~LGraphic()
{
	LGNode<T>*p,*temp;
	//cout<<"LGraphic 正在析构______>"<<endl;
	for(int i=0;i<n;i++)
	{
		p=t[i];
		while(p)
		{
			temp=p->next;
			delete p;
			p=temp;
		}
	}
	delete[]t;
	//cout<<"LGraphic 析构完成_______<"<<endl;
}

template<class T>
int LGraphic<T>::exist(int u,int v)
{
	//cout<<"检测存在性______>"<<endl;
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
	{
		cout<<"("<<u<<","<<v<<") 溢出______>"<<endl;
		return 2;				//错误
	}
	else
	{
		LGNode<T>*p=t[u];
		//cout<<"查找中______>"<<endl;
		while(p&&p->v!=v)
			p=p->next;
		if(p)
		{
			//cout<<"已存在______>"<<endl;
			return 1;			//存在
		}
		else
		{
			//cout<<"不存在______>"<<endl;
			return 0;			//不存在
		}
	}
}

template<class T>
int LGraphic<T>::insert(int u,int v,T w)
{
	if(exist(u,v)!=0)
	{
		cout<<"LGraphic<T>::insert("<<u<<","<<v<<")溢出______>"<<endl;
		return 0;								//插入错误
	}
	else
	{
		//cout<<"LGraphic<T>::insert("<<u<<","<<v<<")成功______<"<<endl;
		t[u]=new LGNode<T>(v,w,t[u]);
		e++;
		return 1;
	}
}

template<class T>
int LGraphic<T>::insert(int u,int v)
{
	//cout<<"即将插入______>"<<endl;
	if(exist(u,v)!=0)
	{
		//cout<<"无法插入______>"<<endl;
		return 0;								//插入错误
	}
	else
	{
		//cout<<"正在新建节点______>"<<endl;
		t[u]=new LGNode<T>(v,1,t[u]);
		e++;
		//cout<<"插入完成______>"<<endl;
		return 1;
	}
}

template<class T>
int LGraphic<T>::remove(int u,int v)
{
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
	{
		cout<<"移除失败______>"<<endl;
		return 0;											//错误
	}
	else
	{
		LGNode<T>*p=t[u],*prep=NULL;
		while(p&&p->v!=v)
		{
			prep=p;
			p=p->next;
		}
		if(p==NULL)										//不存在(u,v)
		{
			//cout<<"不存在无法移除______>"<<endl;
			return 2;
		}
		else													//存在(u,v)
		{
			if(prep)
				prep->next=p->next;
			else
				t[u]=p->next;
			delete p;
			e--;
			//cout<<"移除成功______>"<<endl;
			return 1;
		}
	}

}

#endif