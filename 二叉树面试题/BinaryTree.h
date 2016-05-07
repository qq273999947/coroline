#pragma once
#include <queue>
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T &data = 0)
		:_data(data)
		,_left(NULL)
		,_right(NULL)
	{}
	T _data;
	BinaryTreeNode<T> *_left;
	BinaryTreeNode<T> *_right;
};
template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a,size_t size)
	{
		int index = 0;
		_root = _CreatTree(a,size,index);
	}
	BinaryTree(const BinaryTree<T> &t)
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=( BinaryTree<T> t)
	{
		swap(t._root,_root);
		return *this;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	size_t Size()
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	BinaryTreeNode<T>* Find(const T& x)
	{
		return _Find(_root, x);
	}
	int GetLeafNum()
	{
		return _GetLeafNum(_root);
	}
	int GetLevelLeafNum(const int k)
	{
		return _GetLevelLeafNum(_root,k);
	}
	~BinaryTree()
	{
		_Destroy(_root);
	}
	BinaryTreeNode<T>* FindLowestCommonAncestor(BinaryTreeNode<T> *u,BinaryTreeNode<T> *v)
	{
		//flag为0两个节点都没找到，为1找了一个结点，2则找祖先成功。
		int flag = 0;
		BinaryTreeNode<T> *tmp = _FindAncestor(_root,u,v,flag);
		if(flag == 2)
		{
			return tmp;
		}
		return NULL;
	}
	void Mirror()
	{
		_Mirror(_root);
	}
	bool IsCompleteBinaryTree()
	{
		return _IsCompleteBinaryTree(_root);
	}
	void TransToList()
	{
		BinaryTreeNode<T>* FirstNode = NULL;
		BinaryTreeNode<T>* LastNode = NULL;
		_TranToList(_root,FirstNode,LastNode);
	}
	void NodeMaxDistance()
	{
		int max = 0;
		_NodeMaxDistance(_root,max);
		cout<<"Distance:"<<max<<endl;
	}
	void ReBuildBinaryTree(int* pPreOrder, int* pInOrder,int nodeNum)
	{
		_root = _ReBuildBinaryTree(pPreOrder,pInOrder,nodeNum);
	}

private:
	BinaryTreeNode<T>* _ReBuildBinaryTree(int* pPreOrder, int* pInOrder, int nodeNum)
	{
		if(pPreOrder == NULL || pInOrder == NULL || nodeNum <= 0)
		{
			return NULL;
		}
		BinaryTreeNode<T> *newRoot = new BinaryTreeNode<T>;
		// 前序遍历的第一个为根
		newRoot ->_data = pPreOrder[0];
		newRoot ->_left = NULL;
		newRoot ->_right = NULL;

		// 查找根节点在中序遍历中的位置，中序遍历中，根节点左边为左子树，右边为右子树
		int rootPositionInOrder;
		for(int i = 0; i < nodeNum; i++)
		{
			if(pInOrder[i] == newRoot->_data)
			{
				rootPositionInOrder = i;
				break;
			}
		}

		// 重建左子树
		int nodeNumLeft = rootPositionInOrder;
		int * pPreOrderLeft = pPreOrder + 1;
		int * pInOrderLeft = pInOrder;
		newRoot->_left = _ReBuildBinaryTree(pPreOrderLeft, pInOrderLeft, nodeNumLeft);

		// 重建右子树
		int nodeNumRight = nodeNum - nodeNumLeft - 1;
		int * pPreOrderRight = pPreOrder + 1 + nodeNumLeft;
		int * pInOrderRight = pInOrder + nodeNumLeft + 1;
		newRoot->_right = _ReBuildBinaryTree(pPreOrderRight, pInOrderRight, nodeNumRight);
		return newRoot;
	}
	int _NodeMaxDistance(BinaryTreeNode<T> *root,int &max)
	{
		if(root == NULL)
		{
			return -1;
		}
		int lDistance = 1 + _NodeMaxDistance(root->_left,max);
		int rDistance = 1 + _NodeMaxDistance(root->_right,max);

		if (lDistance + rDistance > max) 
		{
			max = lDistance + rDistance;
		}
		return  lDistance > rDistance ? lDistance : rDistance;
	}
	void _TranToList(BinaryTreeNode<T>* root,BinaryTreeNode<T>*& first,BinaryTreeNode<T>*& last)
	{
		if(root == NULL)
		{
			first = NULL;
			last = NULL;
			return;
		}

		BinaryTreeNode<T>* firstLeft = NULL,*lastLeft = NULL,*firstRight = NULL,*lastRight = NULL;
		//论左
		if(root->_left == NULL)
		{
			first = root;
		}
		else
		{
			_TranToList(root->_left,firstLeft,lastLeft);
			first = firstLeft;

			root->_left = lastLeft;
			if(lastLeft)
			{
				lastLeft->_right = root;
			}
		}
		//论右
		if(root->_right == NULL)
		{
			last = root;
		}
		else
		{
			_TranToList(root->_right,firstRight,lastRight);
			last = lastRight;

			root->_right = firstRight;
			if(firstRight)
			{
				firstRight->_left = root;
			}
		}
		return;
	}
	bool _IsCompleteBinaryTree(BinaryTreeNode<T>* root)
	{
		if(root == NULL)
		{
			return false;
		}
		queue<BinaryTreeNode<T>*> q;
		q.push(root);
		bool MustHaveNoChild = false;
			
		while(!q.empty())
		{
			BinaryTreeNode<T>* cur = q.front();
			q.pop();
			if(MustHaveNoChild)
			{
				if(cur->_left != NULL || cur->_right != NULL)
				{
					return  false;
				}
			}
			else
			{
				if(cur->_right && cur->_left)
				{
					q.push(cur->_left);
					q.push(cur->_right);
				}
				else if(cur->_left && cur->_right == NULL)
				{
					MustHaveNoChild = true;
					q.push(cur->_left);
				}
				else if(cur->_right && cur->_left == NULL)
				{
					return false;
				}
				else
				{
					//两边都没有
					MustHaveNoChild = true;
				}
			}
		}
		return true;
	}
	BinaryTreeNode<T>* _Mirror(BinaryTreeNode<T> *& root)
	{
		if(root == NULL)
		{
			return NULL;
		}
		BinaryTreeNode<T> *pLeft = _Mirror(root->_left); 
		BinaryTreeNode<T> *pRight = _Mirror(root->_right); 

		root->_left = pRight;
		root->_right = pLeft;
		return root;
	}
	BinaryTreeNode<T>* _FindAncestor(BinaryTreeNode<T>* root,BinaryTreeNode<T>* u,BinaryTreeNode<T>* v,int &flag)
	{
		if(root == NULL || flag == 2)
		{
			return NULL;
		}
		BinaryTreeNode<T> *tmp = NULL;

		if(root == u||root == v)
		{
			++flag;
			if(flag == 2)
			{
				return root;
			}
			else
			{
				tmp = root;
			}
		}
		BinaryTreeNode<T>* left = _FindAncestor(root->_left,u,v,flag);
		BinaryTreeNode<T>* right = _FindAncestor(root->_right,u,v,flag);

		if(left && right)
		{
			return root;
		}
		else if(left || right)
		{
			tmp = left?left:right;
			if(flag == 2)
			{
				if(tmp == u||tmp == v)
				{
					return tmp;
				}
			}
		}
		return tmp;
	}
	int _GetLevelLeafNum(const BinaryTreeNode<T> * root,const int k)
	{
		static int count = 0;
		if(root == NULL||k < 0)
		{
			return 0;
		}
		if(k == 0)
		{
			count++;
		}
		_GetLevelLeafNum(root->_left,k-1);
		_GetLevelLeafNum(root->_right,k-1);
		return count;
	}
	int _GetLeafNum(const BinaryTreeNode<T>* root)
	{
		static int count = 0;
		if(root == NULL)
		{
			return 0;
		}
		else if(root->_left == NULL&&root->_right ==NULL)
		{
			count++;
		}
		_GetLeafNum(root->_left);
		_GetLeafNum(root->_right);
		return count;
	}
	BinaryTreeNode<T>*_CreatTree(const T* a,size_t size,int &index)
	{
		BinaryTreeNode<T> *root = NULL;
		if(index < size && a[index] != '#')
		{
			root = new BinaryTreeNode<T>(a[index]);
			root->_left = _CreatTree(a,size,++index);
			root->_right = _CreatTree(a,size,++index);
		}
		return root;
	}
	BinaryTreeNode<T> *_Find(BinaryTreeNode<T> *root,const T& x)
	{
		if(root == NULL)
		{
			return NULL;
		}
		else if(root->_data == x)
		{
			return root;
		}
		else
		{
			if(root->_left)
			{
				BinaryTreeNode<T> *tmp = _Find(root->_left,x);
				if(tmp)
					return tmp;
				else if(root->_right)
				{ 
					return _Find(root->_right,x);
				}
			}
		}
		return NULL;
	}
	size_t _Size(BinaryTreeNode<T> *root)
	{
		if(root == NULL)
		{
			return 0;
		}
		return 1+_Size(root->_left)+_Size(root->_right);
	}
	size_t _Depth(BinaryTreeNode<T> *root)
	{
		if(root == NULL)
		{
			return 0;
		}
		size_t left = _Depth(root->_left);
		size_t right = _Depth(root->_right);
		if(left < right)
		{
			return 1+right;
		}
		return 1+left;
	}
	BinaryTreeNode<T>* _Copy(BinaryTreeNode<T> *root)
	{
		BinaryTreeNode<T> *Newroot = NULL;
		if(root)
		{
			Newroot = new BinaryTreeNode<T>(root->_data);
			Newroot->_left = _Copy(root->_left);
			Newroot->_right = _Copy(root->_right);
		}
		return Newroot;
	}
	void _InOrder(BinaryTreeNode<T> *root)
	{
		if(root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout<<root->_data<<" ";
		_InOrder(root->_right);
	}
	void _Destroy(BinaryTreeNode<T> *root)

	{

		if(root == NULL)

		{

			return;

		} 
		if(root->_left == NULL &&root->_right == NULL)
		{
			delete root;
		} 
		else 
		{

			_Destroy(root->_left);

			_Destroy(root->_right);

			delete root; 
		}

	}

private:
	BinaryTreeNode<T> *_root;
};
