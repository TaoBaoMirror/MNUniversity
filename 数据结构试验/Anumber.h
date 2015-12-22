#ifndef assorted_number_h
#define assorted_number_h

#include<iostream>
using namespace std;

#include"binarytree.h"
#include"file.h"


class Anumber
{
public:
	Anumber(char*);//���캯��
	void print();//�ѽ���͵������
	void caculate();
protected:

private:
	binarytree<char*> btree;//��������������
	file datafile;//�ļ�������
	char* delete_zero(char*);//��һ��������ʼ������ȥ��
};
Anumber::Anumber(char*filename)//��Ҫ��ϵ��ļ�����
{
	datafile.openinfile(filename);
}

void Anumber::caculate()
{
	int flag_delete_zero=0;//1Ϊȥ�㣬0Ϊ��ȥ��
	char*temp;
	while(!datafile.toend())
	{
		temp=datafile.extract_number();
		if(strlen(temp)!=0)
		{
			if(temp[0]=='0'&&flag_delete_zero==0)
			{
				cout<<"��������: "<<temp<<" ��Ҫȥ�������"<<endl;
				cout<<"1.��"<<endl<<"2.����"<<endl<<"������Ҫ�Ĳ�����";
				cin>>flag_delete_zero;
				while(flag_delete_zero!=1&&flag_delete_zero!=2)
				{
					cout<<"1.��"<<endl<<"2.����"<<endl<<"������Ҫ�Ĳ�����";
					cin>>flag_delete_zero;
				}
			}
			if(flag_delete_zero==1)
			{
				temp=delete_zero(temp);
				if(temp[0]=='\0')
					cout<<"������ȫ�����ݣ�����"<<endl;
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