#ifndef hfmcoder_h
#define hfmcoder_h

//������������
#include<iostream>
#include"hfmtree.h"
#include"codernode.h"
#include"file.h"
using namespace std;
template<class T>
class hfmcoder
{
public:
	hfmcoder(int);//����
	~hfmcoder();
	void print();//�������ַ�S�����ӡ����Ļ
	void decipher(T*,char**,char*,char*);
	void encrypt(T *,char**,char*,char*,char*);//����һ���ļ������뽫���ܵ��ļ���������룬�Ѽ����ļ���
protected:

private:
	void coder(T*,char**);//����weightȨֵ�����ַ���s����
	/*int backsize();
	char* backcharacter(int);
	char* backcode(int);*/

	codernode<T> *codergroup;
	hfmtree<T> *tree;
	T *weight;
	int size;
};
template<class T>
hfmcoder<T>::hfmcoder(int maxn)
{
	size=maxn;
	weight=new T[maxn];
	codergroup=new codernode<T> [maxn];
}
template<class T>
hfmcoder<T>::~hfmcoder()
{
	delete[]codergroup;
	delete[]weight;
}
template<class T>
void hfmcoder<T>::coder(T*weight,char**s)//����weightȨֵ�����ַ���s����
{
	char *temp="";
	T w;
	tree=tree->createhfmtree(weight,size);
	//cout<<"!!!������������׼��Ѱ��Ҷ��·��������"<<endl;
	tree->leaftrack(temp,&codergroup);
	//cout<<"!!!������������Ҷ��·��׷Ѱ��ϡ�����"<<endl;
	//system("pause");
	codergroup=codergroup-size;
	for(int i=0;i<size;i++)
	{
		int j=0;
		//cout<<"codergroup[i].weight:"<<codergroup[i].weight<<endl;
		w=codergroup[i].weight;
		while(j<size&&w!=weight[j])
			j++;
		//for(int j=0;j<size&&w!=weight[j];j++)
		//cout<<s[j]<<endl;
		codergroup[i].updatechar(s[j]);
	}
	//cout<<"!!!������������������ϡ�����"<<endl;
	//system("pause");
}
template<class T>
void hfmcoder<T>::print()
{
	for(int i=0;i<size;i++)
		codergroup[i].print();
}
template<class T>
void hfmcoder<T>::encrypt(T *weight,char **strings,char*source,char*result,char*code)
{
	file fsource,fresult,fcode;
	fsource.openinfile(source);
	fresult.openoutfile(result);
	fcode.openoutfile(code);
	coder(weight,strings);
	//cout<<"!!!������������׼�����ļ�����������"<<endl;
	{//���result���
		char temp;
		int i=0;
		while(fsource.getcharc(temp))//���ļ���ȡһ���ֽڸ�temp
		{
			//cout<<temp<<endl;
			//system("pause");
			for(i=0;i<size&&*codergroup[i].strings!=temp;i++);
			if(i<size)
				fresult.writefile(codergroup[i].code);
			else
				cout<<"û�� \""<<temp<<"\" �ı��롣����"<<endl;
		}
	}
	{//�������code
		for(int i=0;i<size;i++)
		{
			fcode.writefile(codergroup[i].strings);
			fcode.writefile("\t");
			fcode.writefile(codergroup[i].code);
			fcode.writefile("\n");
		}
	}
	{//�ر��ļ�
		fsource.close();
		fcode.close();
		fresult.close();
	}
	cout<<"������������������ɡ�����������"<<endl;
}
template<class T>
void hfmcoder<T>::decipher(T*weight,char**strings,char*result,char*source)
{
	file fresult,fsource;
	fresult.openinfile(result);//�򿪴�����01�ļ�
	fsource.openoutfile(source);//���������ļ�
	coder(weight,strings);
	{//��������ļ�
		char temp[2]=" ";
		char *buffer=new char[1];
		memset(buffer,0,1);
		char*pbuffer=buffer;
		//system("pause");
		int location=0;
		int locationbuffer=0;
		int sizebuffer=1;
		while(fresult.getcharc(temp[0]))//���ļ���ȡһ���ֽڸ�temp
		{
			//system("pause");
			/*for(int i=0;i<strlen(buffer);i++)
				cout<<buffer[i];*/
			//cout<<endl;
			if(strlen(buffer)+1==sizebuffer)
			{//��̬�������ַ����ռ䣬��ֹ�ڴ����
				sizebuffer+=4;
				buffer=new char[sizebuffer];
				strcpy_s(buffer,strlen(pbuffer),pbuffer);
				delete[]pbuffer;
				pbuffer=buffer;
			}
			strcat_s(buffer,strlen(temp),temp);
			for(location=0;location<size&&strcmp(codergroup[location].code,buffer)!=0;location++);
			locationbuffer++;
			if(location<size)
			{
				fsource.writefile(codergroup[location].strings);
				memset(buffer,0,strlen(buffer));
				//cout<<"�Ѿ����ҵ�һ��������"<<endl;
				locationbuffer=0;
			}
		}
		cout<<"������������������ɡ�����������"<<endl;
	}
	fsource.close();
	fresult.close();
}


#endif