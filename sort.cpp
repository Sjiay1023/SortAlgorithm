#include<cstdio>
#include<cstring>
#include<algorithm>
#include "node.h"
#include "sort.h"
using namespace std;
struct list
{
	int key;	
}
//���в�������
//ֱ�Ӳ�������
//temp �൱����һ�������� ���Ƚ���һ����¼��Ϊ����Ȼ������������� 
void straight_insertion_sort(list *a)
{
	int len = a[0].key;
	for(int i=2;i<=len;i++)
	{
		if(a[i].key <a[i-1].key)
		{
			int temp = a[i].key;
			a[i].key = a[i-1].key;
			int j;
			for(j=i-2;j>0&&temp<(a[j].key);--j)
			{
				a[j+1].key = a[j].key;
			}
			a[j+1].key =temp;
		}
	} 		
} 

//�۰��������
void binary_insertion_sort(list *a)
{
	int len = a[0].key;
	for(int i=2;i<=len;i++)
	{
		int temp = a[i].key;
		int low=1,high=i-1;		
		while(low<=high)
		{
			int mid=((low+high)>>1);
			if(a[mid].key>temp) high=mid-1;
			else low =mid+1;
		}
		for(j=i-1;j>=high+1;--j)
		{
			a[j+1].key = a[j].key;
		}
		a[j+1].key = temp;
	}
} 

//ϣ������
void shell_insertion_sort(list *a,int len_a)
{
	for(int i=len_a/2;i>0;i/=2)
	{
		shell_sort(a,i);
	}
} 
//����b��С��a���л��ֺ����ֱͨ�Ӳ�������
void shell_sort(list *a,int b)
{
	int len=a[0].key;
	for(int i=b+1;i<len;++i)
	{
		if(a[i].key<a[i-b].key)
		{
			int temp = a[i].key;
			int j ;
			for(j=i-b;(j>=1)&&(temp<a[j].key);j-=b)
			{
				a[j+b].key=a[j].key;
			}
			a[j+b].key=temp;
		}
	}
} 

//�������� 
//ð������ 
void bubble_sort(list *a)
{
	int len = a[0].key;
	for(int i=1;i<len;++i)
	{
		bool flag = true;
		for(int j=1;j<len-i+1;++j)
		{
			if(a[j].key>a[j+1].key)
			{
				swap(a[j].key,a[j+1].key);
				flag = false;
			}
		}
		if(flag)break;
	}
} 
//��������
void quick_sort(list *a,int low,int high)
{
	if(low<high)
	{
		int axis = a[low].key;//�ֱ�ĵ�һ����¼��Ϊ�����¼ 
		int i=low,j = high;
		//�������м�ɨ�� 
		while(i<j)
		{
			while(i<j&&a[j].key>=axis)
			{
				--j;
				a[i].key=a[j].key;
			}
			while(i<j&&a[i].key>=axis)
			{
				++i;
				a[j].key=a[i].key;
			}
		}
		a[j].key =axis;
			quick_sort(a,low,i-1);
		quick_sort(a,i+1,high);
	}
} 

//ѡ������
//��ѡ������ 
void select_sort(list *a)
{
	int len =a[0].key;
	for(int i=1;i<len;++i)
	{
		int min_value=a[i].key;
		int min_index=i;
		for(int j=i+1;j<=len;++j)
		{
			if(a[j].key<min_value)
			{
				min_value=a[j].key;
				min_index=j;
			}
		}
		swap(a[i].key,a[min_index].key);
	}
}

//������
void heap_sort(list *a)
{
	int len = a[0].key;
	//����һ���ѵĹ���
	for(int i=len/2;i>0;--i)
	{
		heap_adjust(a,i,len);
	} 
	for(int i=len;i>1;--i)
	{
		swap(a[1].key,a[i].key);
		heap_adjust(a,1,i-1);
	}
	
} 
void heap_adjust(list *a,int s,int m)
{
	//list a�г���a[s]֮��Ĺؼ��־�����ѵĶ���
	//����������a[s]�Ĺؼ��֣���a[s....m]��Ϊһ���󶥶�
	int temp =a[s].key;
	for(int j=2*s;j<=m;j*=2)
	{
		if(j<m&&(a[j].key<a[j+1].key))++j;
		if(temp>=a[j].key)break;
		a[s].key=a[j].key;
		s=j;
	}
	a[s].key=temp; 
}


//�鲢����
void merge_sort(list *a,int low,int high)
{
	int mid=((low+high)>>1);;
	merge_sort(a,low,mid);
	merge_sort(a,mid+1,high);
	merge_sort(a,low,mid,high);	
} 
//�鲢����ĺϲ�����
void merge_array(list *a,int low,int mid,int high)
{
	list *temp = new list[high-low+1+1];
	int i=low,j=mid+1;
	int index=0;
	while(i<=mid&&j<=high)
	{
		if(a[i].key<a[j].key)
		{
			temp[index++].key=a[i++].key;
		}
		else
		{
			temp[index++].key=a[j++].key;
		}
	}
	while(i<=mid)
	{
		temp[index++].key=a[i++].key;
	}
	while(j<=high)
	{
		temp[index++].key=a[j++].key;
	}
	for(i=0;i<index;++i)
	{
		a[low+i]=temp[i];
	}
	delete []temp;
} 