#include<iostream>
#include<cassert>
using namespace std;

int FindRoot(int *set,int child)
{
	assert(set);
	while(set[child] >= 0)
	{
		child = set[child];
	}
	return child;
}
void Combine(int *set,int root1,int root2)
{
	assert(set);
	set[root1] += set[root2];
	set[root2] = root1;
}
int FindFrinedsCircle(int n,int m,int r[][2])
{
	assert(r);

	int *set = new int(n);
	memset(set,-1,sizeof(int)*n);

	for(int i = 0;i < m;++i)
	{
		int first = r[i][0];
		int second = r[i][1];

		int root1 = FindRoot(set,first);
		int root2 = FindRoot(set,second);

		if(root1 != root2)
		{
			Combine(set,root1,root2);
		}
	}
	int count = 0;
	for(int i = 0;i < n;++i)
	{
		if(set[i] < 0 )
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int r[][2] = {{1 , 2} , {2 , 3} , {4 , 5}};
	cout<<FindFrinedsCircle(5,3,r)<<endl;
	return 0;
}