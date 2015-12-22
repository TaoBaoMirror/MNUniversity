#include<iostream>
using namespace std;

#include"LinearList_Sequence.h"
int main()
{

	int *c=new int[10];
	for(int i=0;i<10;i++)
		c[i]=i+1;
	Sequence<int> z(c,10,10);
	for(int i=0;i<z.length();i++)
		cout<<z.backdata(i)<<endl;
	return 0;
}