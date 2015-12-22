#ifndef binarytree_h
#define binarytree_h

#include<iostream>
#include<list>
#include"treenode.h"
using namespace std;
//二叉树的类
template<class T>
class binarytree
{
public:
	binarytree();
	~binarytree();

	void order_pre();
	void order_in();
	void order_post();
	void order_grade();
	
	void make(T,binarytree<T>&,binarytree<T>&);
	void del();
	void swap_left_right();

	bool isempty();
	int height();
	int sum_leaf();
	binarytree<T>& operator = (const binarytree<T>&);
protected:
	treenode<T>*root;
private:
	void _del(treenode<T>*);
	void _swap_left_right(treenode<T>*);

	void _order_pre(treenode<T>*);
	void _order_in(treenode<T>*);
	void _order_post(treenode<T>*);

	int _height(treenode<T>*);
	int _sum_leaf(treenode<T>*);
	treenode<T>*_copy(treenode<T>*)const;
};
template<class T>
binarytree<T>::binarytree()
{
	root=NULL;
}
template<class T>
binarytree<T>::~binarytree()
{
	_del(root);
	root=NULL;
	//cout<<"!!!二叉树析构完成。。。"<<endl;
}

template<class T>
bool binarytree<T>::isempty()
{
	if(root==NULL)
		return true;
	else
		return false;
}
template<class T>
void binarytree<T>::make(T element,binarytree<T>&l,binarytree<T>&r)
{
	root=new treenode<T>(element,l.root,r.root);
	l.root=r.root=NULL;
}

template<class T>
void binarytree<T>::order_pre()
{
	_order_pre(root);
}
template<class T>
void binarytree<T>::order_in()
{
	_order_in(root);
}
template<class T>
void binarytree<T>::order_post()
{
	_order_post(root);
}
template<class T>
void binarytree<T>::order_grade()//按层次遍历所有节点
{
	if(root)
	{
		list<treenode<T>*> temp;//用STL声明一个队列
		treenode<T>*p;
		temp.push_back(root);
		while(!temp.empty())
		{
			p=temp.front();
			p->print();
			temp.pop_front();
			if(p->back_left())
				temp.push_back(p->back_left());
			if(p->back_right())
				temp.push_back(p->back_right());
		}
	}
}


template<class T>
void binarytree<T>::del()
{
	_del(root);
	root=NULL;
}
template<class T>
void binarytree<T>::swap_left_right()
{
	_swap_left_right(root);
}
template<class T>
int binarytree<T>::height()
{
	return _height(root);
}
template<class T>
int binarytree<T>::sum_leaf()
{
	return _sum_leaf(root);
}

template<class T>
binarytree<T>& binarytree<T>::operator =(const binarytree<T>&x)
{
	//cout<<"!!!——————正在拷贝。。。"<<endl;
	this->root=x._copytree(x.root);
	//system("pause");
	//cout<<"!!!——————拷贝完毕。。。"<<endl;
	return *this;
}
template<class T>
void binarytree<T>::_del(treenode<T>*p)
{
	if(p)
	{
		_del(p->back_left());
		_del(p->back_right());
		//cout<<"!!!即将删除p:"<<p<<"\tp->element:"<<p->element;
		delete p;
	}
}
template<class T>
void binarytree<T>::_swap_left_right(treenode<T>*p)
{
	if(p)
	{
		p->swap_left_right();
		_swap_left_right(p->back_left());
		_swap_left_right(p->back_right());
	}
}
template<class T>
int binarytree<T>::_height(treenode<T>*p)
{
	if(p)
	{
		int suml=(_height(p->back_left())+1);
		int sumr=(_height(p->back_right())+1);
		return suml>=sumr?suml:sumr;
	}
	else
		return 0;
}
template<class T>
int binarytree<T>::_sum_leaf(treenode<T>*p)
{
	if(!p)
		return 0;
	else if(!p->back_left()&&!p->back_right())
		return 1;
	else
		return _sumleaf(p->back_left())+_sumleaf(p->back_right());
}
template<class T>
void binarytree<T>::_order_pre(treenode<T>*p)
{
	if(p)
	{
		p->print();
		_order_pre(p->back_left());
		_order_pre(p->back_right());
	}
}
template<class T>
void binarytree<T>::_order_in(treenode<T>*p)
{
	if(p)
	{
		_order_in(p->back_left());
		p->print();
		_order_in(p->back_right());
	}
}
template<class T>
void binarytree<T>::_order_post(treenode<T>*p)
{
	if(p)
	{
		_order_post(p->back_left());
		_order_post(p->back_right());
		p->print();
	}
}
template<class T>
treenode<T>* binarytree<T>::_copy(treenode<T>*p)const
{
	if(p)
	{
		treenode<T>*q;
		q=new treenode<T>(p->back_element(),_copy(p->back_left()),_copy(p->back_right()));
		return q;
	}
	else
		return NULL;
}
#endif