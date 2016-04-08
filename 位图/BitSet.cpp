#include <iostream>
using namespace std;
#include "BitSet.h"

void test()
{
	BitMap bm1(100);
	bm1.Set(1);
	bm1.Set(33);
	bm1.Set(69);
	bm1.Set(100);

	bm1.Reset(33);
}
int main()
{
	test();
	return 0;
}