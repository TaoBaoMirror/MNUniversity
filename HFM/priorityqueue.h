#ifndef priorityqueue_h
#define priorityqueue_h
#include<iostream>
using namespace std;
template<class T>
class priorityqueue
{
public:
	priorityqueue(int);
	~priorityqueue();
	bool isempty();
	bool isfull();
	void push(T&);
	void pop(T&);
	void adjustup(int);
	void adjustdown(T *,int,int);
	void createheap(T *,int);
protected:

private:
	int maxsize,size;
	T *front;
};
template<class T>
priorityqueue<T>::priorityqueue(int msize=30)
{
	maxsize=msize;
	size=0;
	front=new T[msize];
}
template<class T>
priorityqueue<T>::~priorityqueue()
{
	//cout<<"!!!——————即将删除队列。。。"<<endl;
	delete[]front;
	//cout<<"!!!——————删除队列完毕。。。"<<endl;
}
template<class T>
bool priorityqueue<T>::isempty()
{
	if(size==0)
		return 1;
	else
		return 0;
}
template<class T>
bool priorityqueue<T>::isfull()
{
	if(size==maxsize)
		return 1;
	else
		return 0;
}
template<class T>
void priorityqueue<T>::push(T&x)
{
	if(isfull())
		cout<<"队列已经满。。。";
	else
	{
		front[size++]=x;
		adjustup(size-1);
	}
}
template<class T>
void priorityqueue<T>::pop(T&x)
{
	if(isempty())
		cout<<"空队列。。。";
	x=*front;
	*front=front[--size];
	adjustdown(front,0,size-1);
}
template<class T>
void priorityqueue<T>::adjustup(int current)
{
	int i=current;
	T temp=front[current];
	while(i>0&&temp<front[(i-1)/2])
	{
		front[i]=front[(i-1)/2];
		i=(i-1)/2;
	}
	front[i]=temp;
}
template<class T>
void priorityqueue<T>::adjustdown(T *heap,int current,int maxn)
{
	int child=2*current+1;
	T temp=heap[current];
	while(child<=maxn)
	{
		if(child<maxn&&heap[child]>heap[child+1])//若right<left,child是right下标
			child++;
		if(temp<heap[child])//满足子节点比temp大退出
			break;
		heap[(child-1)/2]=heap[child];//把子节点的element给母节点（向上调整）
		child=2*child+1;
	}
	heap[(child-1)/2]=temp;
}
template<class T>
void priorityqueue<T>::createheap(T heap[],int n)
{
	for(int i=(n-2)/2;i>=0;i--)
		adjustdown(heap,i,n-1);
}



#endif