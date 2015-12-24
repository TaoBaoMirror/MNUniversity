#ifndef _Graphic_Virtual_h
#define _Graphic_Virtual_h

template<class T>/*图的虚基类*/
class Graphic
{
public:
	virtual int insert(int,int)=0;
	virtual int insert(int,int,T)=0;
	virtual int remove(int,int)=0;
	virtual int exist(int,int)=0;		
	virtual int vertices();					/*返回顶点数*/
	virtual int edges();					/*返回边数*/
protected:
	int n;										/*顶点数*/
	int e;											/*边数*/
private:
};

template<class T>/*返回顶点数*/
int Graphic<T>::vertices()
{
	return n;
}
template<class T>/*返回边数*/
int Graphic<T>::edges()
{
	return e;
}



#endif