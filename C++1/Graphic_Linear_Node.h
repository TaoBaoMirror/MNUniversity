#ifndef _Graphic_Linear_Node_h
#define _Graphic_Linear_Node_h

#include<iostream>
using namespace std;

template<class T>
class LGNode
{
public:
	int v;
	T w;
	LGNode<T> *next;

	LGNode(int,T);
	LGNode(int,LGNode<T>*);
	LGNode(int,T,LGNode<T>*);
protected:
private:
};

template<class T>
LGNode<T>::LGNode(int x,T y)
{
	v=x;
	w=y;
	next=NULL;
}

template<class T>
LGNode<T>::LGNode(int ver,T wei,LGNode<T>*p)
{
	v=ver;
	w=wei;
	next=p;
}

template<class T>
LGNode<T>::LGNode(int ver,LGNode<T> *p)
{
	v=ver;
	w=1;
	next=p;
}

#endif