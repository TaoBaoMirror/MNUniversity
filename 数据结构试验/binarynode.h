#ifndef binarynode_h
#define binarynode_h

#include<iostream>
using namespace std;


template<class T>
class binarynode//�������Ľڵ���
{
public:
	binarynode();//���캯��1
	binarynode(T&);//���캯��2
	binarynode(T&,binarynode<T>*,binarynode<T>*);//���캯��3
	void inccount();//�ڵ�Ԫ���ظ�������1
	void visit();//�ѽڵ�Ԫ���͵������

	void update_left(binarynode<T>*);//���±��ڵ����ڵ�
	void update_right(binarynode<T>*);//���±��ڵ���ҽڵ�
	binarynode<T>* back_left();//���ر��ڵ����ָ��
	binarynode<T>* back_right();//���ر��ڵ����ָ��

	bool operator >(binarynode<T>);//�������>���أ�����1��this->element��
	bool operator <(binarynode<T>);//�������<���أ�����1��this->element��
	bool operator ==(binarynode<T>);//�������==���أ�����1�����
protected:
private:
	enum info{small=-1,equal=0,big=1};
	int compare(char*,char*);//��С�Ƚ�������
	int count;//���ڵ���ظ��ڵ������0Ϊû���ظ���n�����ظ�n��
	
	binarynode<T>*left;//��ڵ�ָ��
	binarynode<T>*right;//�ҽڵ�
	T element;//�ڵ�Ԫ��
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
	//cout<<"��Ҫ�Ƚϵ��ַ�����"<<x<<"\t"<<y<<endl;
	int len=0;
	int lenx=strlen(x);
	int leny=strlen(y);
	if(lenx>leny)
		len=leny;
	else
		len=lenx;
	int i;
	for(i=0;i<len&&x[i]==y[i];i++);
	if(i!=len)//�̴������ڳ�����ǰiλ
	{
		if(x[i]>y[i])
			return big;
		else
			return small;
	}
	else// if(i==len)//�̴����ڳ�����ǰIλ
	{
		if(lenx>leny)
		{
			if(compare(&x[i],&y[0])==0)
				return big;
		}
		else if(lenx==leny)//�����������ͬ
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