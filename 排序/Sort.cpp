#include <iostream>
using namespace std;
#include "Sort.h"


void Test()
{
	int a[10] = {2,4,3,8,5,1,6,7,9,0};
	//InsertSort(a,10);
	//ShellSort(a,10);
	//SelectionSort(a,10);
	//HeapSort(a,10);
	//QuickSort(a,0,9);
	//QuickSort2(a,0,9);
	//QuickSort3(a,0,9);
	//QuickSort4(a,0,9);
	QuickSort5(a,0,9);
	Print(a,10);
}
int main()
{
	Test();
	return 0;
}