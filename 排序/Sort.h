#pragma once
#include <cassert>
#include<stack>
// void InsertSort(int *a,size_t size)//����for��ʽ
// {
// 	assert(a);
// 	for(int i = 1;i < size;++i)
// 	{
// 		int tmp = a[i];
// 		int j;
// 		for(j = i-1;j >= 0 &&tmp < a[j];--j)
// 		{
// 			a[j+1] =a[j];
// 		}
// 		a[j + 1] = tmp;
// 	}
// }
void InsertSort(int *a,size_t size)
{
	assert(a);
	for(int i = 1;i < size;++i)
	{
		int tmp = a[i];
		int index = i - 1;
		while(tmp < a[index] && index >= 0)
		{
			a[index + 1] = a[index];
			index--;
		}
		a[index + 1] = tmp;
	}
}
void ShellSort(int *a,size_t size)
{
	int gap = size;
	while(gap > 1)
	{
		gap = gap/3 + 1;//��1��ֹgapС��1
		for(int i = gap;i < size;++i)
		{
			int tmp = a[i];
			int end = i - gap;
			while(end >= 0 && tmp < a[end])
			{
				a[end+gap] = a[end];
				end -= gap;//����ȥ��
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectionSort(int *a,size_t size)
{
	assert(a);
	for(int i = 0;i < size - 1;++i)
	{
		int min = i;
		for(int j = i + 1;j < size;++j)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
		}
		if(a[min] != a[i])
		{
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}

void AjustDown(int *a,size_t size,size_t root)
{
	assert(a);
	int child = root * 2 + 1;
	int parents = root;
	while(child < size)
	{
		if(child + 1 < size && a[child+1] > a[child])
		{
			child++;
		}
		if(a[child] > a[parents])
		{
			swap(a[child],a[parents]);
			parents = child;
			child = child *2 +1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int *a,size_t size)
{
	assert(a);
	//���˶��ţ�����
	for(int i = (size - 2)/2;i >= 0;--i)//size - 1Ϊ���һ��Ԫ�أ���-1��2Ϊ��һ��Ҷ�ӽڵ�ĸ��ڵ�
	{
		AjustDown(a,size,i);
	}
	//��ʼ����
	for(int i = size -1;i > 0; --i)
	{
		swap(a[i],a[0]);
		AjustDown(a,i,0);
	}
}
void Print(int *a,size_t size)
{
	assert(a);
	for(int i = 0;i < size;++i)
	{
		printf("%d ",a[i]);
	}
	cout<<endl;
}
//��ͳ����
int Partition(int *a,int left,int right)
{
	assert(a);
	int begin = left,end = right - 1,key = a[right];
	while(begin < end)
	{
		while(a[begin] < key && begin <= end)
		{
			begin++;
		}
		while(a[end] > key && end >= begin)
		{
			--end;
		}
		if(begin < end)
		{
			swap(a[begin],a[end]);
		}
	}
	if(a[begin] > a[right])
	{
		swap(a[begin],a[right]);
		return begin;
	}
	else
	{
		return right;
	}
}
void QuickSort(int *a,int left,int right)
{
	assert(a);
	if(right > left)
	{
		int boundary = Partition(a,left,right);
		QuickSort(a,left,boundary - 1);
		QuickSort(a,boundary + 1,right);	
	}
}
//��һ�߿�ʼ�ҵ�
int Partition2(int *a,int left,int right)
{
	assert(a);
	int cur = left,prev = left - 1,key = a[right];
	while(cur < right)
	{
		if(a[cur] < key && (++prev) != cur)
		{
			swap(a[prev],a[cur]);
		}
		++cur;
	}
	swap(a[++prev],a[right]);
	return prev;
}
void QuickSort2(int *a,int left,int right)
{
	assert(a);
	if(right > left)
	{
		int boundary = Partition2(a,left,right);
		QuickSort(a,left,boundary - 1);
		QuickSort(a,boundary + 1,right);	
	}
}
//�ڿ�����
int Partition3(int *a,int left,int right)
{
	assert(a);
	int begin = left,end = right,key = a[right];
	while(begin < end)
	{
		while(a[begin] <= key  && begin <= end)
		{
			++begin;
		}
		if(begin < end)
		{
			a[end] = a[begin];
		}
		while(a[end] >= key && begin <= end)
		{
			--end;
		}
		if(begin < end)
		{
			a[begin] = a[end];
		}
	}
	a[begin] = key;
	return begin;
}
void QuickSort3(int *a,int left,int right)
{
	assert(a);
	if(right > left)
	{
		int boundary = Partition3(a,left,right);
		QuickSort(a,left,boundary - 1);
		QuickSort(a,boundary + 1,right);	
	}
}
//�Ż�������ȡ�з�
int GetMidIndex(int *a,int left,int right)
{
	assert(a);
	int mid = left -(left - right)/2;
	if(a[left] < a[right])
	{
		if(a[mid] < a[left])
			return left;
		else if(a[mid] < a[right])
			return mid;
		else
			return right;
	}
	else
	{
		if(a[mid] < a[right])
			return right;
		if(a[mid] < a[left])
			return mid;
		else
			return left;
	}
}
int Partition4(int *a,int left,int right)
{
	assert(a);
	int begin = left,end = right - 1;
	int index = GetMidIndex(a,left,right);
	int key = a[index];
	while(begin < end)
	{
		while(a[begin] < key && begin <= end)
		{
			begin++;
		}
		while(a[end] > key && end >= begin)
		{
			--end;
		}
		if(begin < end)
		{
			swap(a[begin],a[end]);
		}
	}
	if(a[begin] > a[right])
	{
		swap(a[begin],a[right]);
		return begin;
	}
	else
	{
		return right;
	}
}
void QuickSort4(int *a,int left,int right)
{
	assert(a);
	if(right > left)
	{
		int boundary = Partition(a,left,right);
		QuickSort(a,left,boundary - 1);
		QuickSort(a,boundary + 1,right);	
	}
}
//�ǵݹ鷽��
int Partition5(int *a,int left,int right)
{
	assert(a);
	int cur = left,prev = left - 1,key = a[right];
	while(cur < right)
	{
		if(a[cur] < key && (++prev) != cur)
		{
			swap(a[prev],a[cur]);
		}
		++cur;
	}
	swap(a[++prev],a[right]);
	return prev;
}
void QuickSort5(int *a,int left,int right)
{
	assert(a);
	stack<int> s;
	if(right > left)
	{

		int boundary = Partition5(a,left,right);
		if(left < boundary - 1)
		{
			s.push(left);
			s.push(boundary - 1);
		}
		if(boundary+1 < right)
		{
			s.push(boundary+1);
			s.push(right);
		}
		while(!s.empty())
		{
			int end = s.top();
			s.pop();
			int begin = s.top();
			s.pop();
			boundary = Partition2(a,begin,end);

			if(begin < boundary - 1)
			{
				//��߽����£��ұ߽����ϡ�
				s.push(begin);
				s.push(boundary - 1);
			}
			if(boundary + 1 < end)
			{
				s.push(boundary+1);
				s.push(end);
			}
		}	
	}
}
//�鲢
void MergrSection(int *a,int *tmp,int begin1,int end1,int begin2,int end2)
{
	assert(a&&tmp);
	int index = begin1;
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
		while(begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
		while(begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
}
void _MergeSort(int *a,int *tmp,int left,int right)
{
	assert(a && tmp);
	if(left < right)
	{
		int mid = left +(right - left)/2;
		_MergeSort(a,tmp,left,mid);
		_MergeSort(a,tmp,mid+1,right);
		MergrSection(a,tmp,left,mid,mid+1,right);
		memcpy(a+left,tmp+left,(right-left+1)*sizeof(int));
	}
}

void MergrSort(int *a,size_t size)
{
	assert(a);
	int *tmp = new int[size];
	_MergeSort(a,tmp,0,size -1);
	delete[] tmp;
	
}
//��������
void CountSort(int *a,size_t size)
{
	assert(a);
	// ȷ����Χ
	int max = a[0],min = a[0];
	for(size_t i = 0;i < size;++i)
	{
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}

	int range = max - min +1;
	int *CountArray = new int[range];
	memset(CountArray,0,sizeof(int)*range);
	for(size_t i = 0;i < size;++i)
	{
		CountArray[a[i] - min]++;
	}
	size_t index = 0;
	for(size_t i = 0;i < range;++i)
	{
		if(CountArray[i] != 0)
		{
			while(CountArray[i])
			{
				a[index++] = i + min;
				CountArray[i]--;
			}
		}
		else
		{
			break;
		}
	}
}
//��������
int GetMaxDigit(int *a,size_t size)
{
	int digit = 1;
	int max = 10;
	for(size_t i = 0;i < size;++i)
	{
		if(a[i] >= 10)
		{
			digit++;
			max *= 10;
		}
	}
	return digit;
}
void DigitSort(int *a,size_t size)
{
	assert(a);
	int MaxDigit = GetMaxDigit(a,size);

	int Count[10];
	int Start[10];
	int *Bucket = new int[size];

	int bit = 1;
	int digit = 0;
	while(digit < MaxDigit)
	{
		memset(Count,0,sizeof(int)*10);
		memset(Start,0,sizeof(int)*10);
		for(size_t i = 0;i < size;++i)
		{
			int num = (a[i]/bit)%10;
			Count[num]++;
		}
		for(size_t i = 1;i < 10;++i)
		{
			Start[i] = Count[i - 1] + Start[i - 1];
		}
		for(size_t i = 0;i < size; ++i)
		{
			int num = (a[i]/bit)%10;
			Bucket[Start[num]++] = a[i];
		}
		memcpy(a,Bucket,sizeof(int)*size);
		digit++ ;
		bit *= 10;
	}
}