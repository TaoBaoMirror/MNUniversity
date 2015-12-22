#include<iostream>
using namespace std;

#include<ctime>;
#include"sort.h";


int main()
{
	int max=10;
	for(int i=0;i<5;i++,max*=10)
	{
	cout<<"——————"<<max<<"个随机数据排序时间——————"<<endl;
	srand(time(0));
	int *a=new int[max];
	cout<<"正在填充随机数______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	cout<<"随机填充完毕______>"<<endl;
	sort<int> x;
	int p,q;
	p=clock();
	x.sort_quick(a,max);
	q=clock();
	cout<<"快排："<<q-p<<" MS"<<endl;

	//cout<<"正在填充随机数______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"随机填充完毕______>"<<endl;
	p=clock();
	x.sort_merge(a,max);
	q=clock();
	cout<<"合并："<<q-p<<" MS"<<endl;

	
	//cout<<"正在填充随机数______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"随机填充完毕______>"<<endl;
	p=clock();
	x.sort_insert(a,max);
	q=clock();
	cout<<"插入："<<q-p<<" MS"<<endl;
	


	//cout<<"正在填充随机数______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"随机填充完毕______>"<<endl;
	p=clock();
	x.sort_select(a,max);
	q=clock();
	cout<<"选择："<<q-p<<" MS"<<endl;

	
	//cout<<"正在填充随机数______>"<<endl;
	for(int i=0;i<max;i++)
		a[i]=rand();
	//cout<<"随机填充完毕______>"<<endl;
	p=clock();
	x.sort_bubble(a,max);
	q=clock();
	cout<<"冒泡："<<q-p<<" MS"<<endl;

	cout<<"——————"<<max<<"个随机数据排序完成——————"<<endl;
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