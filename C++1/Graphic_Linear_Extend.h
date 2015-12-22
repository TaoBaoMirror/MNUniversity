#ifndef _Graphic_Linear_Extend_h
#define _Graphic_Linear_Extend_h

#include<iostream>
using namespace std;
#include<queue>
#include<stack>

#include"Graphic_Matrix.h"
#include"Graphic_Linear.h"

//
template<class T>
class ELMGraphic:private LGraphic<T>,private MGraphic<T>
{
public:
	ELMGraphic(int);
	ELMGraphic(int,T);
	~ELMGraphic();
	void DFS();
	void BFS();
	int insert(int,int);
	int insert(int,int,T);
	void MINPATH(int,int);
protected:

private:
	void DFS(int,bool*);
	void BFS(int,bool*);
	int choose(int*,bool*);
	int MINPATH(int,T*,int*);
};

template<class T>
int ELMGraphic<T>::insert(int u,int v)
{
		LGraphic<T>::insert(u,v);
		MGraphic<T>::insert(u,v);
	return 0;
}
template<class T>
int ELMGraphic<T>::insert(int u,int v,T w)
{
	LGraphic<T>::insert(u,v,w);
	MGraphic<T>::insert(u,v,w);
	return 0;
}

template<class T>
ELMGraphic<T>::ELMGraphic(int maxsize):LGraphic<T>(maxsize),MGraphic<T>(maxsize)
{
	//LGraphic<T>(maxsize);
	//MGraphic<T>(maxsize);
	//cout<<"ELMGraphic构造完成。。。"<<endl;
}

template<class T>
ELMGraphic<T>::ELMGraphic(int maxsize,T w):LGraphic<T>(maxsize),MGraphic<T>(maxsize,w)
{
	//LGraphic<T>(maxsize);
	//MGraphic<T>(maxsize);
	//cout<<"ELMGraphic构造完成。。。"<<endl;
}


template<class T>
ELMGraphic<T>::~ELMGraphic()
{
	//cout<<"ELMGraphic析构完成。。。"<<endl;
}

template<class T>
void ELMGraphic<T>::DFS()
{
	cout<<"DFS：";
	bool* visited=new bool [LGraphic<T>::n];
	memset(visited,0,LGraphic<T>::n*sizeof(bool));
	for(int i=0;i<LGraphic<T>::n;i++)
		if(!visited[i])
			DFS(i,visited);
	cout<<endl;
	delete[]visited;
}

template<class T>
void ELMGraphic<T>::DFS(int v,bool*visited)
{
	cout<<v<<" ";
	visited[v]=1;
	for(LGNode<T>*p=t[v];p;p=p->next)
		if(!visited[p->v])									//若没有访问过
			DFS(p->v,visited);
}

template<class T>
void ELMGraphic<T>::BFS()
{
	cout<<"BFS：";
	bool *visited=new bool[LGraphic<T>::n];
	memset(visited,0,LGraphic<T>::n*sizeof(bool));
	//for(int i=0;i<LGraphic<T>::n;i++)
	//	cout<<visited[i];
	for(int i=0;i<LGraphic<T>::n;i++)
		if(!visited[i])
			BFS(i,visited);
	cout<<endl;
	delete[]visited;
}

template<class T>
void ELMGraphic<T>::BFS(int v,bool*visited)
{
	queue<int> que;						//STL队列
	LGNode<T>*p;
	
	cout<<v<<" ";
	visited[v]=1;
	que.push(v);

	while(!que.empty())
	{
		p=t[que.front()];
		que.pop();
		while(p)
		{
			if(!visited[p->v])
			{
				cout<<p->v<<" ";//如果没有曾经访问就输出
				visited[p->v]=1;
				que.push(p->v);
			}
			p=p->next;
		}
	}
	//cout<<"宽度优先搜索结束。。。"<<endl;
}

template<class T>
void ELMGraphic<T>::MINPATH(int u,int v)
{
	T*direction=new T[LGraphic<T>::n];
	int*path=new int[LGraphic<T>::n];
	MINPATH(u,direction,path);

	if(path[v]!=-1)
	{
		cout<<"Mini Path "<<u<<"->"<<v<<" :";
		stack<int> temp;
		while(u!=v)
		{
			temp.push(v);
			//cout<<" "<<path[v];
			v=path[v];
		}
		temp.push(u);
		while(!temp.empty())
		{
			cout<<temp.top()<<" ";
			temp.pop();
		}
		cout<<endl;
	}
	else
		cout<<"No Exist Path:  "<<u<<"->"<<v<<endl;
	delete[]path;
	delete[]direction;
}

template<class T>
int ELMGraphic<T>::MINPATH(int v,T*d,int*path)
{
	int i,k,w;
	if(v<0||v>LGraphic<T>::n-1)
		return 0;
	bool *s=new bool[LGraphic<T>::n];
	for(int i=0;i<LGraphic<T>::n;i++)
	{
		s[i]=false;
		d[i]=matrix[v][i];
		if(i!=v&&d[i]<Noedges_user)
			path[i]=v;
		else
			path[i]=-1;
	}
	s[v]=true;
	d[v]=0;

	for(int i=1;i<LGraphic<T>::n;i++)
	{
		k=choose(d,s);
		s[k]=true;
		for(w=0;w<LGraphic<T>::n;w++)
			if(!s[w]&&d[k]+matrix[k][w]<d[w])
			{
				d[w]=d[k]+matrix[k][w];
				path[w]=k;
			}
	}
	delete[]s;
}

template<class T>
int ELMGraphic<T>::choose(int*d,bool*s)
{
	int minpos=-1;
	T min=Noedges_user;
	for(int i=0;i<LGraphic<T>::n;i++)
		if(d[i]<=min&&!s[i])
		{
			min=d[i];
			minpos=i;
		}
	return minpos;
}




#endif