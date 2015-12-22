#ifndef hfmtree_h
#define hfmtree_h

#include"binarytree.h"
#include"priorityqueue.h"
#include<iostream>
using namespace std;

template<class T>class codernode;
template<class T>
class hfmtree:public binarytree<T>
{
public:
	void updateweight(T);
	void leaftrack(char *,codernode<T>**);
	hfmtree<T>* createhfmtree(T*,int);
	int operator<(const hfmtree<T>&);
	int operator>(const hfmtree<T>&);
protected:
private:
	void _leaftrack(binarynode<T>*,char *,codernode<T>**);
	T weight;
};
template<class T>
void hfmtree<T>::updateweight(T x)
{
	weight=x;
}
template<class T>
void hfmtree<T>::leaftrack(char *s,codernode<T>**temp)
{
	//cout<<"!!!������������Ѱ��Ҷ��·��������"<<endl;
	//system("pause");
	//cout<<root<<endl;
	_leaftrack(root,s,temp);
	//cout<<"!!!������������·��Ѱ����ϡ�����"<<endl;
}
template<class T>
hfmtree<T>* hfmtree<T>::createhfmtree(T *w,int maxn)
{
	//cout<<"!!!����������������hfmtree������"<<endl;
	priorityqueue<hfmtree<T>> treequeue(maxn);//������hfm��ΪԪ�ص�����Ȩ����
	hfmtree<T> x,y,z;
	//cout<<"!!!����������������hfm���ڵ㡣����"<<endl;
	for(int i=0;i<maxn;i++)
	{
		z.maketree(w[i],0,0);
		z.updateweight(w[i]);
		treequeue.push(z);
		z.setnull();
	}
	//cout<<"!!!���������������ڹ���hfmtree������"<<endl;
	for(int i=1;i<maxn;i++)
	{
		treequeue.pop(x);
		treequeue.pop(y);
		z.maketree(x.weight+y.weight,x,y);
		z.updateweight(x.weight+y.weight);
		treequeue.push(z);
		z.setnull();
	}
	treequeue.pop(z);
	hfmtree *temp=new hfmtree<T>;
	*temp=z;
	//cout<<"!!!����������������hfmtree��ϡ�����"<<endl;
	return temp;
}
template<class T>
int hfmtree<T>::operator<(const hfmtree<T>& tree)
{
	if(weight<tree.weight)
		return 1;
	else
		return 0;
}
template<class T>
int hfmtree<T>::operator>(const hfmtree<T>& tree)
{
	if(weight>tree.weight)
		return 1;
	else
		return 0;
}
template<class T>
void hfmtree<T>::_leaftrack(binarynode<T>*p,char *s,codernode<T>**temp)
{
	char*one="1";
	char*zero="0";
	if(p)
	{
		if(p->left)
		{
			//cout<<"!!!������������������·��������"<<endl;
			char *now=new char[strlen(s)+2];
			strcpy_s(now,strlen(s),s);//now=strcpy(now,s);
			strcat_s(now,strlen(zero),zero);//now=strcat(now,zero);
			_leaftrack(p->left,now,temp);
		}
		if(p->right)
		{
			//cout<<"!!!������������������·��������"<<endl;
			char *now=new char[strlen(s)+2];
			strcpy_s(now,strlen(s),s);//now=strcpy(now,s);
			strcat_s(now,strlen(one),one);//now=strcat(now,one);
			_leaftrack(p->right,now,temp);
		}
		if(p->left==NULL&&p->right==NULL)
		{
			//cout<<"!!!�������������ҵ�Ҷ�ӡ�����"<<endl;
			(*temp)->updateweight(p->element);
			(*temp)->updatecode(s);
			(*temp)++;
		}
	}
}
#endif