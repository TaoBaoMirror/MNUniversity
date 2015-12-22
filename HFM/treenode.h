#ifndef treenode_h
#define treenode_h

#include<iostream>
using namespace std;
//二叉树的节点类
template<class T>
class treenode
{
public:
	treenode(T&,treenode<T>*,treenode<T>*);
	void print();
	treenode<T>& operator = (const treenode<T>&);
	treenode<T>* back_left();
	treenode<T>* back_right();
	T back_element();
	void swap_left_right();
protected:
private:
	treenode<T>*left;
	treenode<T>*right;
	T element;
};

template<class T>
treenode<T>::treenode(T&x,treenode<T>*l,treenode<T>*r)
{
	element=x;
	left=l;
	right=r;
}
template<class T>
void treenode<T>::print()
{
	cout<<element;
}
template<class T>
treenode<T>& treenode<T>::operator =(const treenode<T>& temp)
{
	this->element=temp.element;
	this->left=temp.left;
	this->right=temp.right;
	return *this;
}
template<class T>
treenode<T>* treenode<T>::back_left()
{
	return left;
}
template<class T>
treenode<T>* treenode<T>::back_right()
{
	return right;
}
template<class T>
T treenode<T>::back_element()
{
	return element;
}
template<class T>
void treenode<T>::swap_left_right()
{
	treenode<T>*temp=NULL;
	temp=left;
	left=right;
	right=temp;
}
#endif