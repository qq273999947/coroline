#include <stdio.h>
#include<string.h>
#include<assert.h>
#include"SeqList.h"
int main()
{
	SeqList s;
	SeqList *p = &s;
    InitSeqList(p);
	PushBack(p,2);
	PushBack(p,2);
	PushBack(p,2);
	PushBack(p,2);
	PushBack(p,1);
	PushBack(p,2);
	ShowSeqList(p);
//	Erase(p,1);
//	Remove(p,2);
//	RemoveALL(p,2);
//	Sort(p);
//	Reverse(p);
	BubbleSort(p);
//	Binaryfind(p,8);
//	Binaryfind(p,1);
//    Binaryfind(p,3);
//	Binaryfind(p,10);
//	printf("pos is %d\n",Binaryfind(p,8));
//	printf("pos is %d\n",Binaryfind(p,1));
//	printf("pos is %d\n",Binaryfind(p,3));
//	printf("pos is %d\n",Binaryfind(p,10));
//	Binaryfind_d(p,8,0,5);
//	Binaryfind_d(p,1,0,5);
//	Binaryfind_d(p,3,0,5);
//	Binaryfind_d(p,10,0,5);
//	printf("pos is %d\n",Binaryfind(p,8));
//	printf("pos is %d\n",Binaryfind(p,1));
//	printf("pos is %d\n",Binaryfind(p,3));
//	printf("pos is %d\n",Binaryfind(p,10));
    ShowSeqList(p);
	return 0;
}
