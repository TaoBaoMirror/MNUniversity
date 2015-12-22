#ifndef assorted_number_h
#define assorted_number_h

#include<iostream>
using namespace std;

#include"binarytree.h"
#include"file.h"


class Anumber
{
public:
	Anumber(char*);//构造函数
	void print();//把结果送到输出流
	void caculate();
protected:

private:
	binarytree<char*> btree;//二分搜索树变量
	file datafile;//文件流变量
	char* delete_zero(char*);//把一个以零起始的数据去零
};
Anumber::Anumber(char*filename)//需要组合的文件名；
{
	datafile.openinfile(filename);
}

void Anumber::caculate()
{
	int flag_delete_zero=0;//1为去零，0为不去零
	char*temp;
	while(!datafile.toend())
	{
		temp=datafile.extract_number();
		if(strlen(temp)!=0)
		{
			if(temp[0]=='0'&&flag_delete_zero==0)
			{
				cout<<"发现数据: "<<temp<<" 需要去零操作吗？"<<endl;
				cout<<"1.是"<<endl<<"2.不是"<<endl<<"输入需要的操作：";
				cin>>flag_delete_zero;
				while(flag_delete_zero!=1&&flag_delete_zero!=2)
				{
					cout<<"1.是"<<endl<<"2.不是"<<endl<<"输入需要的操作：";
					cin>>flag_delete_zero;
				}
			}
			if(flag_delete_zero==1)
			{
				temp=delete_zero(temp);
				if(temp[0]=='\0')
					cout<<"输入了全零数据！！！"<<endl;
				else
					btree.bsinsert(temp);
			}
			else
				btree.bsinsert(temp);
		}
	}
}

char* Anumber::delete_zero(char*temp)
{
	int length_string=strlen(temp);
	int zero_length=0;
	for(int i=0;i<length_string&&temp[i]=='0';i++)
		zero_length++;
	return &temp[zero_length];
}
void Anumber::print()
{
	btree.inorder();
}






#endif