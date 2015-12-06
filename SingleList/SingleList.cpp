#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include"SingleList.h"
void test1()//测试尾插
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PushBack(p,5);

	PrintList(p);
}
void test2()//测试头删
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PrintList(p);

	PopFront(p);
	PopFront(p);
	PopFront(p);
	PopFront(p);
	PopFront(p);
	PrintList(p);
}
void test3()//测试查找结点 删除结点
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PrintList(p);

	ListNode *ret = Find(p,3);
	Erase(p,ret);
	PrintList(p);
	ListNode *ret2 = Find(p,1);
	Erase(p,ret2);
	PrintList(p);
	ListNode *ret3 = Find(p,4);
	Erase(p,ret3);
	PrintList(p);
}
void test4()//测试随机插入
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PrintList(p);

	ListNode *ret = Find(p,3);
	Insert(p,ret,0);
	PrintList(p);

	ListNode *ret2 = Find(p,1);
	Insert(p,ret2,0);
	PrintList(p);
}
void test5()//测试逆置
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PrintList(p);
    PrintReverse(p);
}
void test6()//约瑟夫环
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PushBack(p,5);
	PrintList(p);
    
	ListNode *p1 = JosephCycle(p,3);
	PrintList(p1);
}
void test7()//Bubblesort
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,3);
	PushBack(p,2);
	PushBack(p,5);
	PushBack(p,4);
	PrintList(p);
    
    BubbleSort(p);
	PrintList(p);
}
void test8()//MergeList
{
	ListNode *p1 = NULL;
	InitList(p1);
	PushBack(p1,1);
	PushBack(p1,3);
	PushBack(p1,5);
	PrintList(p1);
	
    ListNode *p2 = NULL;
	InitList(p2);
	PushBack(p2,2);
	PushBack(p2,4);
	PrintList(p2);
  
	ListNode *p3 = MergeList(p1,p2);
	PrintList(p3);
}
void test9()//找倒数第K个结点，只遍历一次
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PushBack(p,5);
	PrintList(p);
    
	ListNode *ret = FindTailnNode(p,3);
	printf("node is %d\n",ret->data);
}
void test10()//判断链表是否有环，有环求长度，求入口。
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PushBack(p,5);
	PushBack(p,6);
	PrintList(p);
 
	ListNode *tail = Find(p,6);
	ListNode *enter = Find(p,2);

	tail->next = enter;
    
	ListNode *meet = IsLoop(p);
	int len = Cyclelength(p,meet);
	printf("len is %d\n",len);

	ListNode *test_enter = CycleEnter(p,len);
	printf("%d\n",test_enter->data);
}
void test11()//找两个不带环相交链表的入口
{
	ListNode *p = NULL;
	InitList(p);
	PushBack(p,1);
	PushBack(p,2);
	PushBack(p,3);
	PushBack(p,4);
	PushBack(p,5);
	PushBack(p,6);
	PrintList(p);
	
	ListNode *p2 = NULL;
	InitList(p2);
	PushBack(p2,1);
	PushBack(p2,2);
	PushBack(p2,3);
	PushBack(p2,4);
	PushBack(p2,5);
	PushBack(p2,6);
	PrintList(p2);
 
	ListNode *enter_p = Find(p,3);
	ListNode *enter_p2 = Find(p2,2);

	enter_p2->next = enter_p;

	ListNode *ent = EnterCross(p,p2);
	printf("%d\n",ent->data);
}
int main()
{
//	test1();
//  test2();
//	test3();
//	test4();
//	test5();
//	test6();
//	test7();
//	test8();
//	test9();
//	test10();
	test11();
	return 0;
}