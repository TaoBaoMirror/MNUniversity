#ifndef _Graphic_Linear_h
#define _Graphic_Linear_h

#include<iostream>
using namespace std;

#include"Graphic_Linear_Node.h"
#include"Graphic_Virtual.h"

template<class T>/*ͼ���ڽӱ�洢��ʽ*/
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
	LGNode<T>**t;			//����ָ��
private:
};

template<class T>
LGraphic<T>::LGraphic(int maxsize)
{
	//cout<<"LGraphic ���ڹ���______>"<<endl;
	n=maxsize;
	e=0;
	t=new LGNode<T>*[n];
	memset(t,0,n*sizeof(int));
	//cout<<"LGraphic �������______>"<<endl;
}

template<class T>
LGraphic<T>::~LGraphic()
{
	LGNode<T>*p,*temp;
	//cout<<"LGraphic ��������______>"<<endl;
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
	//cout<<"LGraphic �������_______<"<<endl;
}

template<class T>
int LGraphic<T>::exist(int u,int v)
{
	//cout<<"��������______>"<<endl;
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
	{
		cout<<"("<<u<<","<<v<<") ���______>"<<endl;
		return 2;				//����
	}
	else
	{
		LGNode<T>*p=t[u];
		//cout<<"������______>"<<endl;
		while(p&&p->v!=v)
			p=p->next;
		if(p)
		{
			//cout<<"�Ѵ���______>"<<endl;
			return 1;			//����
		}
		else
		{
			//cout<<"������______>"<<endl;
			return 0;			//������
		}
	}
}

template<class T>
int LGraphic<T>::insert(int u,int v,T w)
{
	if(exist(u,v)!=0)
	{
		cout<<"LGraphic<T>::insert("<<u<<","<<v<<")���______>"<<endl;
		return 0;								//�������
	}
	else
	{
		//cout<<"LGraphic<T>::insert("<<u<<","<<v<<")�ɹ�______<"<<endl;
		t[u]=new LGNode<T>(v,w,t[u]);
		e++;
		return 1;
	}
}

template<class T>
int LGraphic<T>::insert(int u,int v)
{
	//cout<<"��������______>"<<endl;
	if(exist(u,v)!=0)
	{
		//cout<<"�޷�����______>"<<endl;
		return 0;								//�������
	}
	else
	{
		//cout<<"�����½��ڵ�______>"<<endl;
		t[u]=new LGNode<T>(v,1,t[u]);
		e++;
		//cout<<"�������______>"<<endl;
		return 1;
	}
}

template<class T>
int LGraphic<T>::remove(int u,int v)
{
	if(u<0||u>(n-1)||u==v||v<0||v>(n-1))
	{
		cout<<"�Ƴ�ʧ��______>"<<endl;
		return 0;											//����
	}
	else
	{
		LGNode<T>*p=t[u],*prep=NULL;
		while(p&&p->v!=v)
		{
			prep=p;
			p=p->next;
		}
		if(p==NULL)										//������(u,v)
		{
			//cout<<"�������޷��Ƴ�______>"<<endl;
			return 2;
		}
		else													//����(u,v)
		{
			if(prep)
				prep->next=p->next;
			else
				t[u]=p->next;
			delete p;
			e--;
			//cout<<"�Ƴ��ɹ�______>"<<endl;
			return 1;
		}
	}

}

#endif