#define MAX_SIZE 100
typedef int DataType;
typedef struct SeqList
{
	DataType arr[MAX_SIZE];
	size_t size;
}SeqList;
void InitSeqList(SeqList *pSeq)
{
	memset(pSeq->arr,0,sizeof(DataType)*MAX_SIZE);
	pSeq->size = 0;
}
void ShowSeqList(SeqList *pSeq)
{	
	size_t i = 0;
	assert(pSeq);
	for(;i<pSeq->size;i++)
	{
		printf("%d ",pSeq->arr[i]);
	}
	printf("\n");
}
void PushBack(SeqList *pSeq,DataType x)
{
	assert(pSeq);
	if(pSeq->size >= MAX_SIZE)
	{
		printf("SeqList is full");
		return;
	}
	pSeq->arr[pSeq->size++] = x;
}
void Erase(SeqList *pSeq,size_t pos)
{
   size_t i = pos;
   assert(pSeq);
   if(pSeq->size == 0)
   {
	   printf("nothing to erase!\n");
	   return;
   }
   if((pos > pSeq->size) || (pos < 1))
   {
	   printf("pos is wrong!\n");
	   return;
   }
   for(i = pos; i < pSeq->size;i++)
	   {
          pSeq->arr[i] = pSeq->arr[i + 1];
	   }
	   pSeq->size--;  
}
void Remove(SeqList *pSeq,DataType x)
{	
	size_t i = 0,j = 0;
	assert(pSeq);
	if(pSeq->size == 0)
   {
	   printf("nothing to remove!\n");
	   return;
   }
	for(i = 0;i < pSeq->size;i++)
	{
		if(pSeq->arr[i] == x)
		{
			for(j =i ;j < pSeq->size;j++)
            {
				pSeq->arr[j] = pSeq->arr[j+1];
			}
			pSeq->size--;
		    return;
		}
	}
	printf("data is not exist!\n");
	return;
	
}
//void RemoveALL(SeqList *pSeq,DataType x)//普通
//{	
//	size_t i = 0,j = 0,k = 0;
//	assert(pSeq);
//	if(pSeq->size == 0)
//   {
//	   printf("nothing to remove!\n");
//	   return;
//   }
//	for(k = 0;k < pSeq->size;k++)
//	{
//		for(i = k;i < pSeq->size;i++)
//		{
//			if(pSeq->arr[i] == x)
//			{
//				for(j =i ;j < pSeq->size;j++)
//				{
//					pSeq->arr[j] = pSeq->arr[j+1];
//				}
//				pSeq->size--;
//			}
//		}
//	}
//}
void RemoveALL(SeqList *pSeq,DataType x)//优化
{	
	size_t first = 0,second = 0,i = 0;
	assert(pSeq);
	if(pSeq->size == 0)
   {
	   printf("nothing to remove!\n");
	   return;
   }
	while(pSeq->arr[second] != 0)
	{
		if(pSeq->arr[second] != x)
		{
			if(pSeq->arr[first] != pSeq->arr[second])
			{
				pSeq->arr[first] = pSeq->arr[second];
			}
			second++;
		    first++;
		}
		else
		{
			second++;
		}
	}
	pSeq->size = first;
}
void Sort(SeqList *pSeq)//选择排序
{
	size_t i = 0,j = 0,temp = 0;
	assert(pSeq);
	if(pSeq->size == 0)
   {
	   printf("nothing to Sort!\n");
	   return;
   }

		for(i = 0;i < pSeq->size - 1;i++)
		{
			for(j = i + 1;j < pSeq->size;j++)
			{
				if(pSeq->arr[i]>pSeq->arr[j])
				{
					temp = pSeq->arr[j];
					pSeq->arr[j] = pSeq->arr[i];
					pSeq->arr[i] = temp;
				}
			}
		}
}
void BubbleSort(SeqList *pSeq)//冒泡排序(优化：判断是否接近有序，已经排好就不排了)
{
	size_t i = 0,j = 0,temp = 0,count = 1;
    assert(pSeq);
	if(pSeq->size == 0)
   {
		printf("nothing to Sort!\n");
		return;
   }
	for(i = 0;i < pSeq->size - 1;i++)
	{
		for(j = i;j < pSeq->size - 1;j++)
		{
			if(pSeq->arr[j + 1] < pSeq->arr[j])
			{
				temp = pSeq->arr[j];
				pSeq->arr[j] = pSeq->arr[j + 1];
				pSeq->arr[j + 1] = temp;
			}
		}
        
	}
}
size_t Binaryfind(SeqList *pSeq,DataType x)//二分查找
{
	size_t left = 0,right = pSeq->size - 1,mid = (left + right)/2;
	assert(pSeq);
	while((pSeq->arr[mid] != x)&&(left < right))
	{
		if(x > pSeq->arr[mid])
		{
			left = mid + 1;
		}
		else if(x < pSeq->arr[mid])
		{
			right = mid - 1;
		}
		mid = (left + right)/2;
	}
	if(pSeq->arr[mid] == x)
	{
		return mid;
	}
	else
	{
      return -1;
	}
}
size_t Binaryfind_d(SeqList *pSeq,DataType x,size_t left,size_t right)//二分查找，递归
{
	size_t mid = (left + right)/2;
	assert(pSeq);
	while(left <= right)
	{
		if(pSeq->arr[mid] == x)
		{
			return mid;
		}		
		else if(x > pSeq->arr[mid])
		{
			left = mid + 1;
			return Binaryfind_d(pSeq,x,left,right);
		}
		else
		{
			right = mid - 1;
			return Binaryfind_d(pSeq,x,left,right);				
		}
	}
      return -1;
}
void Reverse(SeqList *pSeq)
{
   size_t i = 0,count = (pSeq->size - 1)/2;
   assert(pSeq);
   if(pSeq->size == 0)
   {
	   printf("nothing to reverse!\n");
	   return;
   }
   for(i = 0;i <= count;i++)
   {
	   int temp = 0;
	   temp = pSeq->arr[i];
	   pSeq->arr[i] = pSeq->arr[pSeq->size - i - 1];
	   pSeq->arr[pSeq->size - i - 1] = temp;
   }

}