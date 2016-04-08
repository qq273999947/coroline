#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
#include "Migong.h"

void test()
{
	int a[10*10] = {};
	GetMaze(a,10,10);
	PrintMaze(a,10,10);

	Pos entry(2,0);
	GetMazePath(a,10,10,entry);
	PrintMaze(a, 10, 10);

}
int main()
{
	test();
	return  0;
}
