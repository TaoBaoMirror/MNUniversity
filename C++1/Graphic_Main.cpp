#include<iostream>
using namespace std;

#include"Graphic_Matrix.h"
#include"Graphic_Linear_Extend.h"
int main()
{
	//Graphic<int> *x;
	ELMGraphic<int>x(12);
	//system("pause");
	x.insert(0,10);
	x.insert(0,11);
	x.insert(0,1);

	x.insert(1,11);
	x.insert(1,5);
	x.insert(1,2);
	x.insert(1,0);

	x.insert(11,10);
	x.insert(11,1);
	x.insert(11,0);
	

	x.insert(10,9);
	x.insert(10,6);
	x.insert(10,11);
	x.insert(10,0);

	x.insert(2,1);
	x.insert(2,5);
	x.insert(2,3);

	x.insert(5,1);
	x.insert(5,2);
	x.insert(5,4);
	x.insert(5,6);

	x.insert(6,10);
	x.insert(6,9);
	x.insert(6,7);
	x.insert(6,5);
	
	x.insert(9,10);
	x.insert(9,8);
	x.insert(9,6);
	
	x.insert(3,2);
	x.insert(3,4);
	
	x.insert(4,5);
	x.insert(4,7);
	x.insert(4,3);
	
	x.insert(7,6);
	x.insert(7,8);
	x.insert(7,4);
	
	x.insert(8,9);
	x.insert(8,7);

	//cout<<x.edges()<<endl;
	x.DFS();
	x.BFS();
	x.MINPATH(2,8);
	/*
	x.insert(0,1,50);
	x.insert(0,4,70);
	x.insert(0,2,10);

	x.insert(2,0,20);
	x.insert(2,3,15);

	x.insert(3,1,20);
	x.insert(3,4,35);

	x.insert(1,2,15);
	x.insert(1,4,10);

	x.insert(4,3,30);

	x.insert(5,3,3);
	//x.insert(0,3,25);

	//x.print();
	x.DFS();
	x.BFS();
	x.MINPATH(0,5);
	x.MINPATH(0,4);*/
	return 0;
}