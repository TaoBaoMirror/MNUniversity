#ifndef binarynode_h
#define binarynode_h

#include<iostream>
using namespace std;


template<class T>
class binarynode//二叉树的节点类
{
public:
	binarynode();//构造函数1
	binarynode(T&);//构造函数2
	binarynode(T&,binarynode<T>*,binarynode<T>*);//构造函数3
	void inccount();//节点元素重复个数增1
	void visit();//把节点元素送到输出流

	void update_left(binarynode<T>*);//更新本节点的左节点
	void update_right(binarynode<T>*);//更新本节点的右节点
	binarynode<T>* back_left();//返回本节点的左指针
	binarynode<T>* back_right();//返回本节点的右指针

	bool operator >(binarynode<T>);//类运算符>重载，返回1则this->element大
	bool operator <(binarynode<T>);//类运算符<重载，返回1则this->element大
	bool operator ==(binarynode<T>);//类运算符==重载，返回1则相等
protected:
private:
	enum info{small=-1,equal=0,big=1};
	int compare(char*,char*);//大小比较主函数
	int count;//本节点的重复节点计数，0为没有重复，n代表重复n个
	
	binarynode<T>*left;//左节点指针
	binarynode<T>*right;//右节点
	T element;//节点元素
};

template<class T>
binarynode<T>::binarynode()
{
	left=right=0;
	count=0;
}
template<class T>
binarynode<T>::binarynode(T&x)
{
	element=x;
	left=right=NULL;
	count=0;
}
template<class T>
binarynode<T>::binarynode(T&x,binarynode<T>*l,binarynode<T>*r)
{
	element=x;
	left=l;
	right=r;
}
template<class T>
void binarynode<T>::visit()
{
	for(int i=0;i<=count;i++)
		cout<<element<<" ";
}

template<class T>
bool binarynode<T>::operator <(binarynode<T> temp)
{
	if(compare(this->element,temp.element)==-1)
		return true;
	else
		return false;
}

template<class T>
bool binarynode<T>::operator >(binarynode<T> temp)
{
	if(compare(this->element,temp.element)==1)
		return true;
	else
		return false;
}

template<class T>
bool binarynode<T>::operator==(binarynode<T> temp)
{
	if(this->element==temp->element)
		return true;
	else
		return false;
}

template<class T>
int binarynode<T>::compare(char*x,char*y)
{
	//cout<<"将要比较的字符串："<<x<<"\t"<<y<<endl;
	int len=0;
	int lenx=strlen(x);
	int leny=strlen(y);
	if(lenx>leny)
		len=leny;
	else
		len=lenx;
	int i;
	for(i=0;i<len&&x[i]==y[i];i++);
	if(i!=len)//短串不等于长串的前i位
	{
		if(x[i]>y[i])
			return big;
		else
			return small;
	}
	else// if(i==len)//短串等于长串的前I位
	{
		if(lenx>leny)
		{
			if(compare(&x[i],&y[0])==0)
				return big;
		}
		else if(lenx==leny)//长度相等则相同
			return equal;
		else
		{
			if(compare(&x[0],&y[i])==0)
				return big;
		}
	}
}

template<class T>
void binarynode<T>::inccount()
{
	count++;
}

template<class T>
binarynode<T>* binarynode<T>::back_left()
{
	return left;
}

template<class T>
binarynode<T>* binarynode<T>::back_right()
{
	return right;
}

template<class T>
void binarynode<T>::update_left(binarynode<T>* p)
{
	left=p;
}

template<class T>
void binarynode<T>::update_right(binarynode<T>* p)
{
	right=p;
}


#endif