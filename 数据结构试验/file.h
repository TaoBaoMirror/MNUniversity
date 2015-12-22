#ifndef file_h
#define file_h

#define DEBUG/*调试开关，删除此句将不会产生追踪信息*/

#include<fstream>
#include<iostream>
using namespace std;

class file
{
public:
	file();
	bool openinfile(char *);/*打开输入流流文件，参数1：文件名，返回值：成功返回true，否则false*/
	bool openoutfile(char *);/*打开输出流文件，参数1：文件名，返回值：成功返回true，否则false*/

	void close();/*关闭输出流和输入流文件*/
	void writefile(char *);/*向文件写入字符串，参数1：写入的字符串*/
	char* extract_number();/*从文件抽取一个数字字符串，返回字符串指针*/
	bool getchar(char&);/*从输入流文件获取一个字符，参数1：存储到的空间，返回值：获取成功返回true，否则false*/
	bool toend();/*检测输入流文件是否到文件尾，返回值：到文件尾返回true，否则false*/
protected:

private:
	ifstream in;
	ofstream out;
	char* _extract_number();/*主函数：从文件抽取一个数字字符串，返回字符串指针*/
};

file::file()
{
#ifdef DEBUG
	cout<<"DEBUG______>"<<"file正在构造"<<endl;
#endif
}

bool file::openinfile(char *s)
{
	in.open(s,ios::in);
	if(!in)
	{
		cout<<"Tip______>"<<s<<" 文件打开失败,正在尝试创建"<<endl;
		if(openoutfile(s))
		{
			close();
		}
		else
			openinfile(s);
	}
}

bool file::openoutfile(char *s)
{
	out.open(s,ios::out);
	if(!out)
		return false;
	else
		return true;
}

void file::writefile(char*s)
{
	out.write(s,strlen(s));
}

bool file::getchar(char &s)
{
	if(in.eof()==false)
	{
		in.get(s);
		return true;
	}
	else
		return false;
}

void file::close()
{
	in.close();
	out.close();
}

char* file::extract_number()
{
	return _extract_number();
}

char* file::_extract_number()
{
	int strings_size=2;//缓存区大小
	int strings_size_increment=1;//缓存区动态增量
	char*strings=new char[strings_size];
	memset(strings,0,sizeof(char)*strings_size);//初始化置零
	int index=0;
	for(;file::getchar(strings[index]);index++)
	{
		if((index+2)==strings_size)//动态增长缓存区不会产生内存溢出问题
		{
			char *temp=new char[strings_size+strings_size_increment];
			memset(temp,0,sizeof(char)*strings_size);
			strings[index+1]='\0';
			//cout<<"将要拷贝字符串——————》"<<endl;
			strcpy_s(temp,strings_size,strings);//VS2010以上
			//cout<<"拷贝OK——————》"<<endl;
			//strings[index+1]='\0';//2010以下
			//strcpy(temp,strings);
			delete[]strings;
			strings=temp;
			strings_size=strings_size+strings_size_increment;
		}
		if(strings[index]=='\n'||strings[index]==' ')//抽取完成
			break;
		if(strings[index]>'9'||strings[index]<'0')//未抽取到'0'~'9'
			index--;
	}
	strings[index]='\0';
	//cout<<strings[index]-'0'<<endl;
	//char *p=new char[strlen(strings)];
	//strcpy_s(p,strlen(strings),strings);//2012
	//strcpy(p,strings);
	//cout<<strings<<endl;
	//return p;
	return strings;
}

bool file::toend()
{
	if(in.eof())
		return true;
	else
		return false;
}


#endif