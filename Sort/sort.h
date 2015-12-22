#ifndef Sort_h
#define Sort_h

#define DEBUG/*���Կ��أ�ɾ���˾佫�������׷����Ϣ*/

template <class T>/*������*/
class sort
{
public:
	void sort_select(T*,int);/*ѡ�����򣬲���1����Ҫ����Ŀռ�ָ�룬����2�������Ԫ������*/
	void sort_insert(T*,int);/*�������򣬲���1����Ҫ����Ŀռ�ָ�룬����2�������Ԫ������*/
	void sort_bubble(T*,int);/*ð�����򣬲���1����Ҫ����Ŀռ�ָ�룬����2�������Ԫ������*/
	void sort_quick(T*,int);/*�������򣬲���1����Ҫ����Ŀռ�ָ�룬����2�������Ԫ������*/
	void sort_merge(T*,int);/*�鲢���򣬲���1����Ҫ����Ŀռ�ָ�룬����2�������Ԫ������*/
protected:

private:
	void sort_quick(T*,int,int);/*����������������1����Ҫ����Ŀռ�ָ�룬����2����߽磬����3���ұ߽�*/
	void swap(T*,T*);/*��������Ԫ�أ�����1��������Ԫ��1������2��������Ԫ��2*/
	void merge(T*,int,int,int,int);/*�ϲ�����������1������1����߽磬����2������1���ұ߽磬����3������2����߽磬����4������2���ұ߽�*/
};

template<class T>/*ѡ������*/
void sort<T>::sort_select(T*matrix,int n)
{
#ifdef DEBUG
	cout<<"DEBUGE______>"<<"����ѡ������"<<endl;
#endif
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
			if(matrix[j]<matrix[min])
				min=j;
		swap(&matrix[i],&matrix[min]);
	}
#ifdef DEBUG
	cout<<"DEBUGE______>"<<"ѡ���������"<<endl;
#endif
}

template<class T>/*��������*/
void sort<T>::sort_insert(T*matrix,int n)
{
#ifdef DEBUG
	cout<<"DEBUGE______>"<<"���ڲ�������"<<endl;
#endif
	T temp;
	int j;
	for(int i=1;i<n;i++)
	{
		temp=matrix[i];
		for(j=i;j>0&&temp<matrix[j-1];j--)
			matrix[j]=matrix[j-1];
		matrix[j]=temp;
	}
	
#ifdef DEBUGE
	cout<<"DEBUG_______>"<<"�����������"<<endl;
#endif
}

template<class T>/*ð������*/
void sort<T>::sort_bubble(T*matrix,int n)
{
#ifdef DEBUG
	cout<<"DEBUG______>"<<"����ð������"<<endl;
#endif
	int i,j,last;
	i=n-1;
	while(i>0)
	{
		last=0;
		for(j=0;j<i;j++)
			if(matrix[j+1]<matrix[j])
			{
				swap(&matrix[j],&matrix[j+1]);
				last=j;
			}
		i=last;
	}
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"ð���������"<<endl;
#endif
}

template<class T>/*������ӿ�*/
void sort<T>::sort_quick(T*matrix,int n)
{
	sort_quick(matrix,0,n-1);
}

template<class T>/*����*/
void sort<T>::sort_quick(T*matrix,int left,int right)
{
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"���ڿ�������"<<endl;
#endif
*/
	int i,j;
	if(left<right)
	{
		i=left;
		j=right+1;
		do
		{
			do
			{
				i++;
			}while(matrix[i]<matrix[left]);
			do
			{
				j--;
			}while(matrix[j]>matrix[left]);
			if(i<j)
				swap(&matrix[i],&matrix[j]);
		}while(i<j);
		swap(&matrix[left],&matrix[j]);
		sort_quick(matrix,left,j-1);
		sort_quick(matrix,j+1,right);
	}
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"�����������"<<endl;
#endif
*/
}

template<class T>/*��������Ԫ��*/
void sort<T>::swap(T*x,T*y)
{
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"���ڽ���Ԫ��("<<*x<<","<<*y<<")"<<endl;
#endif
*/
	T temp;
	temp=*x;
	*x=*y;
	*y=temp;
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"����Ԫ�ؽ���"<<endl;
#endif
*/
}


template<class T>/*�ϲ�����*/
void sort<T>::merge(T*A,int i1,int j1,int i2,int j2)
{
/*
#ifdef DEBUG
	cout<<"DEBUG______>"<<"���ںϲ�"<<endl;
#endif
*/
	T*temp=new T[j2-i1+1];
	int i=i1,j=i2,k=0;
	while(i<=j1&&j<=j2)
		if(A[i]<=A[j])
			temp[k++]=A[i++];
		else
			temp[k++]=A[j++];
	while(i<=j1)
		temp[k++]=A[i++];
	while(j<=j2)
		temp[k++]=A[j++];
	for(i=0;i<k;i++)
	{
		A[i1++]=temp[i];
		//cout<<temp[i];
	}
	delete[] temp;
/*
#ifdef DEBUG
	cout<<"DEBUG______>"<<"�ϲ�����"<<endl;
#endif
*/
}

template<class T>/*��������*/
void sort<T>::sort_merge(T*A,int n)
{
#ifdef DEBUG
	cout<<"DEBUG______>"<<"���ڲ�������"<<endl;
#endif
	int i1,j1,i2,j2;
	int size=1;
	while(size<n)
	{
		i1=0;
		while(i1+size<n)
		{
			i2=i1+size;
			j1=i2-1;
			if(i2+size-1>n-1)
				j2=n-1;
			else
				j2=i2+size-1;
			merge(A,i1,j1,i2,j2);
			i1=j2+1;
		}
		size*=2;
	}
#ifdef DEBUG
	cout<<"DEBUG______>"<<"�����������"<<endl;
#endif
}



#endif