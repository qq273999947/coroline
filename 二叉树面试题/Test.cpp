#include<iostream>
using namespace std;
#include "BinaryTree.h"

void test()
{
	int a[10] = {1,2,3,'#','#',4,'#','#',5,6};
	BinaryTree<int> t1(a,10);

	t1.InOrder();
	cout<<t1.GetLeafNum()<<endl;
	cout<<t1.GetLevelLeafNum(1)<<endl;
	BinaryTreeNode<int> *u = t1.Find(3);
	BinaryTreeNode<int> *v = t1.Find(6);
	BinaryTreeNode<int> *tmp =t1.FindLowestCommonAncestor(u,v);
	cout<<tmp->_data<<endl;

// 	t1.Mirror();
// 	t1.InOrder();

	cout<<t1.IsCompleteBinaryTree()<<endl;
	int b[11] = {1,2,3,'#','#','#',5,6,'#','#',7};
	BinaryTree<int> t2(b,11);
	cout<<t2.IsCompleteBinaryTree()<<endl;

// 	t1.TransToList();
	t1.NodeMaxDistance();

	BinaryTree<int> t3;
	int c[6] = {1,2,3,4,5,6};
	int d[6] = {3,2,4,1,6,5};
	t3.ReBuildBinaryTree((int*)c,(int*)d,6);
	t3.InOrder();
}
int main()
{
	test();
	return 0;
}