#pragma once

enum Color{RED,BLACK};

template<class K,class V>
struct RBtreeNode
{
	RBtreeNode(const K& key,const V& v,Color col = RED)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_key(key)
		,_vlaue(v)
		,_col(col)
	{}
	RBtreeNode<K,V>* _left;
	RBtreeNode<K,V>* _right;
	RBtreeNode<K,V>* _parent;
	K _key;
	V _vlaue;
	Color _col;
};
template<class K,class V>
class RBtree
{
	typedef RBtreeNode<K,V> Node;
public:
	RBtree()
		:_root(NULL)
	{}
	bool Insert(const K& key,const V& v)
	{
		if(_root == NULL)
		{
			_root = new Node(key,v,BLACK);
			return true;
		}
		Node* parent = NULL;
		Node* cur = _root;
		while(cur)
		{
			if(key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if(key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key,v,RED);
		if(key < parent->_key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent =  parent;
		}
		//µ÷É«
		while(cur != _root && parent->_col == RED)
		{
			Node* GrandParent = parent->_parent;
			if(parent == GrandParent->_left)//Íù×ó×ÓÊ÷²å
			{
				Node* uncle = GrandParent->_right;
				if(uncle && uncle->_col == RED)
				{
					uncle->_col = parent->_col = BLACK;
					GrandParent->_col = RED;

					cur = GrandParent;
					parent = cur->_parent;
				}
				else
				{
					if(cur == parent->_right)
					{
						_RotateL(parent);
						swap(cur,parent);
					}
					_RotateR(GrandParent);
					parent->_col = BLACK;
					GrandParent->_col = RED;
				}
			}
			else//ÍùÓÒ×ÓÊ÷²å
			{
				Node*uncle = GrandParent->_left;
				if(uncle && uncle->_col == RED)
				{
					uncle->_col = parent->_col = BLACK;
					GrandParent->_col = RED;

					cur = GrandParent;
					parent = cur->_parent;
				}
				else
				{
					if(cur == parent->_left)
					{
						_RotateR(parent);
						swap(cur,parent);
					}
					_RotateL(GrandParent);

					parent->_col = BLACK;
					GrandParent->_col = RED;
				}

			}
		}
		_root->_col = BLACK;
		return true;
	}
	bool IsBalanceTree()
	{
		return _IsBalance(_root);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
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

		return (left > right)?left:right;
	}
	bool _IsBalance(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}
		int left = _Height(root->_left);
		int right = _Height(root->_right);

		int bf = abs(left - right);
		if (bf > 1)
		{
			return false;
		}

		return _IsBalance(root->_left) && _IsBalance(root->_right);
	}
	void _RotateL(Node* parent)
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;

		}
		subR->_left = parent;
		subR->_parent = parent->_parent;
		parent->_parent = subR;
		parent = subR;
		//Á¬°Ö°Ö:)
		if (parent->_parent == NULL)
		{
			_root = parent;
		}
		else
		{
			if (parent->_parent->_key < parent->_key)
			{
				parent->_parent->_right = parent;
			}
			else
			{
				parent->_parent->_left = parent;
			}
		}
	}
	void _RotateR(Node* parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;
		parent->_left = subLR;
		if (subLR != NULL)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		subL->_parent = parent->_parent;
		parent->_parent = subL;
		parent = subL;
		if (parent->_parent == NULL)
		{
			_root = parent;
		}
		else
		{
			if (parent->_parent->_key < parent->_key)
			{
				parent->_parent->_right = parent;
			}
			else
			{
				parent->_parent->_left = parent;
			}
		}
	}
	void _InOrder(Node*& root)
	{
		if(root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout<<root->_key<<" ";
		_InOrder(root->_right);
	}
protected:
	Node* _root;

};