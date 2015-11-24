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