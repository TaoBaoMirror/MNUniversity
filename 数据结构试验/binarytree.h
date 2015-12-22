#ifndef binarytree_h
#define binarytree_h

#include<iostream>
#include<list>
using namespace std;

#include"binarynode.h"

template<class T>
class binarytree//二叉树的类
{
public:
	binarytree();//构造函数
	~binarytree();//析构函数
	bool isempty();//检测空树
	void maketree(T,binarytree<T>&,binarytree<T>&);//构建一棵树

	void preorder();//先序遍历
	void inorder();//中序遍历
	void postorder();//后序遍历
	void gradation();//层次遍历

	void deletetree();/*删除整棵树*/
	void transtreelr();//左右转换
	int bsinsert(T);//binary search insert二分搜索树的插入操作
	int heighttree();//树高
	int sumleaf();//叶子总数
	binarytree<T>& operator = (const binarytree<T>&);//拷贝构造函数
protected:
	binarynode<T>*root;//根节点
private:
	enum info{success=1,duplicate};
	void _deletetree(binarynode<T>*);//删除主函数
	void _transtreelr(binarynode<T>*);//左右转换主函数
	void _preorder(binarynode<T>*);//先序遍历主函数
	void _inorder(binarynode<T>*);//中序遍历主函数
	void _postorder(binarynode<T>*);//后序遍历主函数
	int _heighttree(binarynode<T>*);//树高主函数
	int _sumleaf(binarynode<T>*);//叶子节点总数主函数
	binarynode<T>*_copytree(binarynode<T>*)const;//拷贝主函数
};
template<class T>
binarytree<T>::binarytree()
{
	//cout<<"binarytree正在构造______>"<<endl;
	root=0;
	//cout<<"binarytree构造完成______>"<<endl;
}
template<class T>
binarytree<T>::~binarytree()
{
	_deletetree(root);
	root=NULL;
	//cout<<"binarytree 析构完成______>"<<endl;
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
void binarytree<T>::maketree(T element,binarytree<T>&l,binarytree<T>&r)
{
	root=new binarynode<T>(element,l.root,r.root);
	l.root=r.root=NULL;
}


template<class T>
void binarytree<T>::preorder()
{
	_preorder(root);
}
template<class T>
void binarytree<T>::inorder()
{
	_inorder(root);
}
template<class T>
void binarytree<T>::postorder()
{
	_postorder(root);
}
template<class T>
void binarytree<T>::gradation()//按层次遍历所有节点
{
	
	if(root)
	{
		list<binarynode<T>*> temp;//用STL声明一个队列
		binarynode<T>*p;
		temp.push_back(root);
		while(!temp.empty())
		{
			p=temp.front();
			p->visit();
			temp.pop_front();
			if(p->back_left())
				temp.push_back(p->back_left());
			if(p->back_right())
				temp.push_back(p->back_right());
		}
	}
}

template<class T>
void binarytree<T>::deletetree()
{
	_deletetree(root);
	root=NULL;
	//cout<<"!!!二叉树删除完成。。。"<<endl;
}

template<class T>
void binarytree<T>::transtreelr()
{
	_transtreelr(root);
}
template<class T>
int binarytree<T>::heighttree()
{
	return _heighttree(root);
}
template<class T>
int binarytree<T>::sumleaf()
{
	return _sumleaf(root);
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
void binarytree<T>::_deletetree(binarynode<T>*p)
{
	if(p)
	{
		_deletetree(p->back_left());
		_deletetree(p->back_right());
		//cout<<"!!!即将删除p:"<<p<<"\tp->element:"<<p->element;
		delete p;
	}
}
template<class T>
void binarytree<T>::_transtreelr(binarynode<T>*p)
{
	binarynode<T>*temp=NULL;
	if(p)
	{
		temp=p->back_left();
		p->back_left()=p->back_right();
		p->back_right()=temp;
		_transtreelr(p->back_left());
		_transtreelr(p->back_right());
	}
}
template<class T>
int binarytree<T>::_heighttree(binarynode<T>*p)
{
	if(p)
	{
		int suml=(_heighttree(p->back_left())+1);
		int sumr=(_heighttree(p->back_right())+1);
		return suml>=sumr?suml:sumr;
	}
	else
		return 0;
}
template<class T>
int binarytree<T>::_sumleaf(binarynode<T>*p)
{
	if(!p)
		return 0;
	else if(!p->back_left()&&!p->back_right())
		return 1;
	else
		return _sumleaf(p->back_left())+_sumleaf(p->back_right());
}
template<class T>
void binarytree<T>::_preorder(binarynode<T>*p)
{
	if(p)
	{
		p->visit();
		_preorder(p->back_left());
		_preorder(p->back_right());
	}
}
template<class T>
void binarytree<T>::_inorder(binarynode<T>*p)
{
	if(p)
	{
		_inorder(p->back_left());
		p->visit();
		_inorder(p->back_right());
	}
}
template<class T>
void binarytree<T>::_postorder(binarynode<T>*p)
{
	if(p)
	{
		_postorder(p->back_left());
		_postorder(p->back_right());
		p->visit();
	}
}
template<class T>
binarynode<T>* binarytree<T>::_copytree(binarynode<T>*p)const
{
	if(p)
	{
		binarynode<T>*q;
		q=new binarynode<T>(p->element);
		q->back_left()=_copytree(p->back_left());
		q->back_right()=_copytree(p->back_right());
		return q;
	}
	else
		return 0;
}


template<class T>
int binarytree<T>::bsinsert(T temp)
{
	//cout<<"正在插入______> ("<<temp<<")"<<endl;
	binarynode<T>*store=NULL,*p=root;
	binarynode<T>*r=new binarynode<T>(temp);
	while(p)
	{
		store=p;
		if(*r>*p)
			p=p->back_left();
		else if(*r<*p)
			p=p->back_right();
		else
		{
			//cout<<"Error______>(Duplicate!)"<<temp<<endl;
			p->inccount();
			return duplicate;
		}
	}
	p=r;
	if(!root)
		root=p;
	else if(*p>*store)
	{
		//cout<<"插入在 ("<<store->element<<") 左"<<endl;
		store->update_left(p);
	}
	else
	{
		//cout<<"插入在 ("<<store->element<<") 右"<<endl;
		store->update_right(p);
	}
	//cout<<"插入完成______>"<<endl;
	return success;
}








#endif