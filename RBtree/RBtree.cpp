#include <iostream>
using namespace std;
#include "RBtree.h"

void test()
{
	RBtree<int, int> rb;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		rb.Insert(a[i], i);
	}
	rb.InOrder();
	cout<<rb.IsBalanceTree();
}
int main()
{
	test();
	return 0;
}