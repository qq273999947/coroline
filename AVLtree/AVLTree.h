#pragma once

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const K& key,const V& value)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_key(key)
		,_value(value)
		,_bf(0)
	{}
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K,V>* _right;
	AVLTreeNode<K,V>* _parent;
	K _key;
	V _value;
	int _bf;//平衡因子
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K& key,const V& value)
	{
		if(_root == NULL)
		{
			_root = new Node(key,value);
			return true;
		}
		//插入
		Node *cur = _root;
		Node *parent = NULL;
		while(cur)
		{
			if(key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key,value);
		if(key > parent->_key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		//调整平衡因子
		bool IsRotate = false;
		while(parent)
		{	
			if(parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if(parent->_bf == 0)
			{
				break;
			}
			else if(parent->_bf == 1||parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else
			{
				IsRotate = true;
				if(parent->_bf == 2)
				{
					if(cur->_bf == 1)
					{
						RotateL(parent);
					}
					else//cur->_bf == -1
					{
						RotateRL(parent);
					}
				}
				else//parent->_bf == -2
				{
					if(cur->_bf == -1)
					{
						RotateR(parent);
					}
					else//cur->_bf == 1
					{
						RotateLR(parent);
					}
				}
				break;
			}
		}	
		if(IsRotate)
		{
			Node* GrandParent = parent->_parent;
			if(GrandParent == NULL)
			{
				_root = parent;
			}
			else
			{
				if(parent->_key < GrandParent->_key)
				{
					GrandParent->_left = parent;
				}
				else
				{
					GrandParent->_right = parent;
				}
			}
		}
		return true;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}

protected:
	int _Height(Node* root)
	{
		if(root == NULL)
		{
			return 0;
		}
		int left = _Height(root->_left) + 1;
		int right = _Height(root->_right) + 1;
		return (left>right)?left:right;
	}
	bool _IsBalance(Node* root)
	{
		if(root == NULL)
		{
			return true;
		}
		int left = _Height(root->_left);
		int right = _Height(root->_right);

		int bf = left - right;
		if(abs(bf) > 1)
		{
			return false;
		}
		if(abs(bf) != abs(root->_bf))
		{
			cout<<root->_key<<"平衡因子出错！"<<endl;
			return false;
		}
		return _IsBalance(root->_left)&&_IsBalance(root->_right);
	}
	void _InOrder(Node* root)
	{
		if(root == NULL)
			return;
		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
	}
	void RotateL(Node*& parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		
		parent->_right = subRL;
		if(subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		subR->_parent = parent->_parent;

		parent->_parent = subR;
		parent->_bf = subR->_bf = 0;

		parent = subR; 
		
	}
	void RotateR(Node*& parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if(subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		subL->_parent = parent->_parent;
	
		parent->_parent = subL;
		parent->_bf = subL->_bf = 0;

		parent = subL;
	}
	void RotateLR(Node*& parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}
	void RotateRL(Node*& parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}
protected:
    Node* _root;
};
