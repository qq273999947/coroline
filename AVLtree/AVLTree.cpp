#include <iostream>
using namespace std;
#include "AVLTree.h"

void test()
{
	AVLTree<int,int> t;
	int a[]={16, 3, 7, 11, 9, 26, 18, 14, 15};
	for(int i = 0;i < sizeof(a)/sizeof(int);++i)
	{
		t.Insert(a[i],i);
	}
	t.InOrder();
}
void test2()
{
	AVLTree<int,int> t;
	int a[]={4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
	for(int i = 0;i < sizeof(a)/sizeof(int);++i)
	{
		t.Insert(a[i],i);
	}
	t.InOrder();
	cout<<"IsBalance?"<<t.IsBalance()<<endl;
}
int main()
{
  test();
  return 0;
}