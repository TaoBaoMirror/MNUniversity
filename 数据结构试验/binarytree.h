#ifndef binarytree_h
#define binarytree_h

#include<iostream>
#include<list>
using namespace std;

#include"binarynode.h"

template<class T>
class binarytree//����������
{
public:
	binarytree();//���캯��
	~binarytree();//��������
	bool isempty();//������
	void maketree(T,binarytree<T>&,binarytree<T>&);//����һ����

	void preorder();//�������
	void inorder();//�������
	void postorder();//�������
	void gradation();//��α���

	void deletetree();/*ɾ��������*/
	void transtreelr();//����ת��
	int bsinsert(T);//binary search insert�����������Ĳ������
	int heighttree();//����
	int sumleaf();//Ҷ������
	binarytree<T>& operator = (const binarytree<T>&);//�������캯��
protected:
	binarynode<T>*root;//���ڵ�
private:
	enum info{success=1,duplicate};
	void _deletetree(binarynode<T>*);//ɾ��������
	void _transtreelr(binarynode<T>*);//����ת��������
	void _preorder(binarynode<T>*);//�������������
	void _inorder(binarynode<T>*);//�������������
	void _postorder(binarynode<T>*);//�������������
	int _heighttree(binarynode<T>*);//����������
	int _sumleaf(binarynode<T>*);//Ҷ�ӽڵ�����������
	binarynode<T>*_copytree(binarynode<T>*)const;//����������
};
template<class T>
binarytree<T>::binarytree()
{
	//cout<<"binarytree���ڹ���______>"<<endl;
	root=0;
	//cout<<"binarytree�������______>"<<endl;
}
template<class T>
binarytree<T>::~binarytree()
{
	_deletetree(root);
	root=NULL;
	//cout<<"binarytree �������______>"<<endl;
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
void binarytree<T>::gradation()//����α������нڵ�
{
	
	if(root)
	{
		list<binarynode<T>*> temp;//��STL����һ������
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
	//cout<<"!!!������ɾ����ɡ�����"<<endl;
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
	//cout<<"!!!���������������ڿ���������"<<endl;
	this->root=x._copytree(x.root);
	//system("pause");
	//cout<<"!!!������������������ϡ�����"<<endl;
	return *this;
}
template<class T>
void binarytree<T>::_deletetree(binarynode<T>*p)
{
	if(p)
	{
		_deletetree(p->back_left());
		_deletetree(p->back_right());
		//cout<<"!!!����ɾ��p:"<<p<<"\tp->element:"<<p->element;
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
	//cout<<"���ڲ���______> ("<<temp<<")"<<endl;
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
		//cout<<"������ ("<<store->element<<") ��"<<endl;
		store->update_left(p);
	}
	else
	{
		//cout<<"������ ("<<store->element<<") ��"<<endl;
		store->update_right(p);
	}
	//cout<<"�������______>"<<endl;
	return success;
}








#endif