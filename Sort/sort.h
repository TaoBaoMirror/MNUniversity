#ifndef Sort_h
#define Sort_h

#define DEBUG/*调试开关，删除此句将不会产生追踪信息*/

template <class T>/*排序类*/
class sort
{
public:
	void sort_select(T*,int);/*选择排序，参数1：需要排序的空间指针，参数2：排序的元素总量*/
	void sort_insert(T*,int);/*插入排序，参数1：需要排序的空间指针，参数2：排序的元素总量*/
	void sort_bubble(T*,int);/*冒泡排序，参数1：需要排序的空间指针，参数2：排序的元素总量*/
	void sort_quick(T*,int);/*快速排序，参数1：需要排序的空间指针，参数2：排序的元素总量*/
	void sort_merge(T*,int);/*归并排序，参数1：需要排序的空间指针，参数2：排序的元素总量*/
protected:

private:
	void sort_quick(T*,int,int);/*快排主函数，参数1：需要排序的空间指针，参数2：左边界，参数3：右边界*/
	void swap(T*,T*);/*交换两个元素，参数1：交换的元素1，参数2：交换的元素2*/
	void merge(T*,int,int,int,int);/*合并函数，参数1：区间1的左边界，参数2：区间1的右边界，参数3：区间2的左边界，参数4：区间2的右边界*/
};

template<class T>/*选择排序*/
void sort<T>::sort_select(T*matrix,int n)
{
#ifdef DEBUG
	cout<<"DEBUGE______>"<<"正在选择排序"<<endl;
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
	cout<<"DEBUGE______>"<<"选择排序结束"<<endl;
#endif
}

template<class T>/*插入排序*/
void sort<T>::sort_insert(T*matrix,int n)
{
#ifdef DEBUG
	cout<<"DEBUGE______>"<<"正在插入排序"<<endl;
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
	cout<<"DEBUG_______>"<<"插入排序结束"<<endl;
#endif
}

template<class T>/*冒泡排序*/
void sort<T>::sort_bubble(T*matrix,int n)
{
#ifdef DEBUG
	cout<<"DEBUG______>"<<"正在冒泡排序"<<endl;
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
	cout<<"DEBUG_______>"<<"冒泡排序结束"<<endl;
#endif
}

template<class T>/*快排外接口*/
void sort<T>::sort_quick(T*matrix,int n)
{
	sort_quick(matrix,0,n-1);
}

template<class T>/*快排*/
void sort<T>::sort_quick(T*matrix,int left,int right)
{
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"正在快速排序"<<endl;
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
	cout<<"DEBUG_______>"<<"快速排序结束"<<endl;
#endif
*/
}

template<class T>/*交换两个元素*/
void sort<T>::swap(T*x,T*y)
{
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"正在交换元素("<<*x<<","<<*y<<")"<<endl;
#endif
*/
	T temp;
	temp=*x;
	*x=*y;
	*y=temp;
/*
#ifdef DEBUG
	cout<<"DEBUG_______>"<<"交换元素结束"<<endl;
#endif
*/
}


template<class T>/*合并函数*/
void sort<T>::merge(T*A,int i1,int j1,int i2,int j2)
{
/*
#ifdef DEBUG
	cout<<"DEBUG______>"<<"正在合并"<<endl;
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
	cout<<"DEBUG______>"<<"合并结束"<<endl;
#endif
*/
}

template<class T>/*并归排序*/
void sort<T>::sort_merge(T*A,int n)
{
#ifdef DEBUG
	cout<<"DEBUG______>"<<"正在并归排序"<<endl;
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
	cout<<"DEBUG______>"<<"并归排序结束"<<endl;
#endif
}



#endif