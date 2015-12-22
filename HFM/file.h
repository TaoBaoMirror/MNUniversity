#ifndef file_h
#define file_h
#include<fstream>
#include<iostream>
using namespace std;
class file
{
public:
	void openinfile(char *);
	void openoutfile(char *);
	bool getcharc(char&);
	void close();
	void writefile(char *);
protected:

private:
	ifstream in;
	ofstream out;
};
void file::openinfile(char *s)
{/*
	char *s="d:\\textfile.txt";
	char *r="d:\\result.txt";
	char *t="d:\\codefile.txt";*/
	in.open(s,ios::in);
	if(!in)
	{
		cout<<s<<"文件打开失败，请创建"<<endl;
	}
}
void file::openoutfile(char *s)
{/*
	char *s="d:\\textfile.txt";
	char *r="d:\\result.txt";
	char *t="d:\\codefile.txt";*/
	out.open(s,ios::out);
	if(!out)
	{
		cout<<s<<"文件打开失败，请创建！"<<endl;
	}
	//out.clear();
}
void file::writefile(char*s)
{
	out.write(s,strlen(s));
}
bool file::getcharc(char &s)
{
	if(in.get(s))
		return 1;
	else
		return 0;
}
void file::close()
{
	in.close();
	out.close();
}
#endif