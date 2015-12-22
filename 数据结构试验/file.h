#ifndef file_h
#define file_h

#define DEBUG/*���Կ��أ�ɾ���˾佫�������׷����Ϣ*/

#include<fstream>
#include<iostream>
using namespace std;

class file
{
public:
	file();
	bool openinfile(char *);/*�����������ļ�������1���ļ���������ֵ���ɹ�����true������false*/
	bool openoutfile(char *);/*��������ļ�������1���ļ���������ֵ���ɹ�����true������false*/

	void close();/*�ر���������������ļ�*/
	void writefile(char *);/*���ļ�д���ַ���������1��д����ַ���*/
	char* extract_number();/*���ļ���ȡһ�������ַ����������ַ���ָ��*/
	bool getchar(char&);/*���������ļ���ȡһ���ַ�������1���洢���Ŀռ䣬����ֵ����ȡ�ɹ�����true������false*/
	bool toend();/*����������ļ��Ƿ��ļ�β������ֵ�����ļ�β����true������false*/
protected:

private:
	ifstream in;
	ofstream out;
	char* _extract_number();/*�����������ļ���ȡһ�������ַ����������ַ���ָ��*/
};

file::file()
{
#ifdef DEBUG
	cout<<"DEBUG______>"<<"file���ڹ���"<<endl;
#endif
}

bool file::openinfile(char *s)
{
	in.open(s,ios::in);
	if(!in)
	{
		cout<<"Tip______>"<<s<<" �ļ���ʧ��,���ڳ��Դ���"<<endl;
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
	int strings_size=2;//��������С
	int strings_size_increment=1;//��������̬����
	char*strings=new char[strings_size];
	memset(strings,0,sizeof(char)*strings_size);//��ʼ������
	int index=0;
	for(;file::getchar(strings[index]);index++)
	{
		if((index+2)==strings_size)//��̬������������������ڴ��������
		{
			char *temp=new char[strings_size+strings_size_increment];
			memset(temp,0,sizeof(char)*strings_size);
			strings[index+1]='\0';
			//cout<<"��Ҫ�����ַ�����������������"<<endl;
			strcpy_s(temp,strings_size,strings);//VS2010����
			//cout<<"����OK��������������"<<endl;
			//strings[index+1]='\0';//2010����
			//strcpy(temp,strings);
			delete[]strings;
			strings=temp;
			strings_size=strings_size+strings_size_increment;
		}
		if(strings[index]=='\n'||strings[index]==' ')//��ȡ���
			break;
		if(strings[index]>'9'||strings[index]<'0')//δ��ȡ��'0'~'9'
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