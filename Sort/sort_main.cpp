#include<iostream>
using namespace std;

#include<ctime>;
#include"sort.h";


int main()
{
	int max=10;
	for(int i=0;i<5;i++,max*=10)
	{
	cout<<"������������"<<max<<"�������������ʱ�䡪����������"<<endl;
	srand(time(0));
	int *a=new int[max];
	cout<<"������������______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	cout<<"���������______>"<<endl;
	sort<int> x;
	int p,q;
	p=clock();
	x.sort_quick(a,max);
	q=clock();
	cout<<"���ţ�"<<q-p<<" MS"<<endl;

	//cout<<"������������______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"���������______>"<<endl;
	p=clock();
	x.sort_merge(a,max);
	q=clock();
	cout<<"�ϲ���"<<q-p<<" MS"<<endl;

	
	//cout<<"������������______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"���������______>"<<endl;
	p=clock();
	x.sort_insert(a,max);
	q=clock();
	cout<<"���룺"<<q-p<<" MS"<<endl;
	


	//cout<<"������������______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"���������______>"<<endl;
	p=clock();
	x.sort_select(a,max);
	q=clock();
	cout<<"ѡ��"<<q-p<<" MS"<<endl;

	
	//cout<<"������������______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"���������______>"<<endl;
	p=clock();
	x.sort_bubble(a,max);
	q=clock();
	cout<<"ð�ݣ�"<<q-p<<" MS"<<endl;

	cout<<"������������"<<max<<"���������������ɡ�����������"<<endl;
	//for(int i=0;i<max;i++)
	//	cout<<a[i]<<" ";


	/*
	int b[10]={1,2,3,4,5,6,7,8,9,10};
	//char b[10]={'g','c','k','n','j','f','a','h','i','e'};
	sort<int> y;
	y.sort_merge(b,10);

	for(int i=0;i<10;i++)
		cout<<b[i]<<" ";*/
	}
	return 0;
}