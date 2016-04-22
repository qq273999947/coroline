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
int main()
{
  test();
  return 0;
}