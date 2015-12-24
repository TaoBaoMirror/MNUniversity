#ifndef _Graphic_Virtual_h
#define _Graphic_Virtual_h

template<class T>/*ͼ�������*/
class Graphic
{
public:
	virtual int insert(int,int)=0;
	virtual int insert(int,int,T)=0;
	virtual int remove(int,int)=0;
	virtual int exist(int,int)=0;		
	virtual int vertices();					/*���ض�����*/
	virtual int edges();					/*���ر���*/
protected:
	int n;										/*������*/
	int e;											/*����*/
private:
};

template<class T>/*���ض�����*/
int Graphic<T>::vertices()
{
	return n;
}
template<class T>/*���ر���*/
int Graphic<T>::edges()
{
	return e;
}



#endif