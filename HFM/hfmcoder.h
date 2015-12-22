#ifndef hfmcoder_h
#define hfmcoder_h

//哈弗曼编码类
#include<iostream>
#include"hfmtree.h"
#include"codernode.h"
#include"file.h"
using namespace std;
template<class T>
class hfmcoder
{
public:
	hfmcoder(int);//构造
	~hfmcoder();
	void print();//把所有字符S编码打印到屏幕
	void decipher(T*,char**,char*,char*);
	void encrypt(T *,char**,char*,char*,char*);//加密一个文件，输入将加密的文件，输出编码，已加密文件。
protected:

private:
	void coder(T*,char**);//根据weight权值，给字符串s编码
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
void hfmcoder<T>::coder(T*weight,char**s)//根据weight权值，给字符串s编码
{
	char *temp="";
	T w;
	tree=tree->createhfmtree(weight,size);
	//cout<<"!!!——————准备寻找叶子路径。。。"<<endl;
	tree->leaftrack(temp,&codergroup);
	//cout<<"!!!——————叶子路径追寻完毕。。。"<<endl;
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
	//cout<<"!!!——————编码完毕。。。"<<endl;
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
	//cout<<"!!!——————准备对文件操作。。。"<<endl;
	{//输出result结果
		char temp;
		int i=0;
		while(fsource.getcharc(temp))//从文件读取一个字节给temp
		{
			//cout<<temp<<endl;
			//system("pause");
			for(i=0;i<size&&*codergroup[i].strings!=temp;i++);
			if(i<size)
				fresult.writefile(codergroup[i].code);
			else
				cout<<"没有 \""<<temp<<"\" 的编码。。。"<<endl;
		}
	}
	{//输出编码code
		for(int i=0;i<size;i++)
		{
			fcode.writefile(codergroup[i].strings);
			fcode.writefile("\t");
			fcode.writefile(codergroup[i].code);
			fcode.writefile("\n");
		}
	}
	{//关闭文件
		fsource.close();
		fcode.close();
		fresult.close();
	}
	cout<<"——————加密完成——————"<<endl;
}
template<class T>
void hfmcoder<T>::decipher(T*weight,char**strings,char*result,char*source)
{
	file fresult,fsource;
	fresult.openinfile(result);//打开待译码01文件
	fsource.openoutfile(source);//打开已译码文件
	coder(weight,strings);
	{//输出解码文件
		char temp[2]=" ";
		char *buffer=new char[1];
		memset(buffer,0,1);
		char*pbuffer=buffer;
		//system("pause");
		int location=0;
		int locationbuffer=0;
		int sizebuffer=1;
		while(fresult.getcharc(temp[0]))//从文件读取一个字节给temp
		{
			//system("pause");
			/*for(int i=0;i<strlen(buffer);i++)
				cout<<buffer[i];*/
			//cout<<endl;
			if(strlen(buffer)+1==sizebuffer)
			{//动态的增长字符串空间，防止内存溢出
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
				//cout<<"已经查找到一个。。。"<<endl;
				locationbuffer=0;
			}
		}
		cout<<"——————解密完成——————"<<endl;
	}
	fsource.close();
	fresult.close();
}


#endif