//二叉树的基本操作及哈弗曼编码的实现
#include"binarytree.h"
#include"treenode.h"
#include"hfmtree.h"
#include"hfmcoder.h"
#include"file.h"
#include<iostream>
using namespace std;
int main()
{
	int weight[68]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
		17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,
		33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
		49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,
		65,66,67};
	char *s[68]={"0","1","2","3","4","5","6","7","8","9","A","B"
		,"C","D","E","F","G","H","I","J","K","L","M","N","O","P"
		,"Q","R","S","T","U","V","W","X","Y","Z","(",")",".",","," "
		,"\n","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"
		,"p","q","r","s","t","u","v","w","x","y","z"};
	hfmcoder<int>x(68),y(68);
	x.encrypt(weight,s,"d:\\textfile.txt","d:\\result.txt","d:\\codefile.txt");
	y.decipher(weight,s,"e:\\encrypted.txt","e:\\decipered.txt");
	return 0;
}