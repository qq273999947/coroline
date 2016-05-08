#pragma once

template<class K,int M = 3>
struct BtreeNode
{
	BtreeNode()
		:_size(0)
		,_parent(NULL)
	{
		for(int i = 0;i < M+1;++i)
		{
			_childs[i] = NULL;
		}
	}
	K _key[M];										  //关键字数组
	size_t _size;										 //关键字个数
	BtreeNode<K,M>* _childs[M+1];  //孩子
	BtreeNode<K,M>* _parent;			//父亲	
};
template<class K,class V>
struct Pair
{
	Pair(const K&k = K(),const V&v = V())
		:_first(k)
		,_second(v)
	{}
	K _first;//节点本身
	V _second;//节点所在的位置
};
template<class K,int M = 3>
class Btree
{
	typedef BtreeNode<K,M> Node;
public:
	Btree()
		:_root(NULL)
	{}
	void InOrder()
	{
		_InOrder(_root);
	}
	Pair<Node*,int> Find(const K&key)
	{
		Node* parent = NULL;
		Node* cur = _root;
		while(cur)
		{
			int i = 0;
			while(i < cur->_size && cur->_key[i] < key)
			{
				++i;
			}
			if(cur->_key[i] == key)
			{
				return Pair<Node*,int>(cur,i);
			}
			//如果在此节点里没有找到key，i这时也走到了相应的位置,我们该去它的孩子里找找看
			parent = cur;
			cur = cur->_childs[i];
		}
		return Pair<Node*,int>(parent,-1);
	}
	bool Insert(K& key)
	{
		if(_root == NULL)
		{
			_root = new Node;
			_root->_key[0] = key;
			++_root->_size;
			return true;
		}
		Pair<Node*,int> ret =Find(key);
		if(ret._second != -1)
		{
			return false;
		}
		
		Node *cur = ret._first;
		Node *child = NULL;

		//往cur插key
		while(1)
		{
			_InsertKey(cur,key,child);
			if(cur->_size < M)
			{
				return true;
			}
			//插完超过M，开始分裂
			int boundary = M/2;
			
			Node* tmp = new Node;
			size_t index = 0;
			size_t size = cur->_size;
			
			//拷贝key到新分裂出的结点tmp上
			for(int i = boundary+1;i < size;++i)
			{
				tmp->_key[index++] = cur->_key[i];
				
				tmp->_size++;
				cur->_size--;
			}
			//拷贝孩子
			index = 0;
			for(int i = boundary + 1;i <= size;++i)
			{
				tmp->_childs[index++] = cur->_childs[i];
				if(tmp->_childs[index])
				{
					tmp->_childs[index]->_parent = tmp;
				}
			}
			key = cur->_key[boundary];
			cur->_size--;

			//没有根了,即原本的root给分裂了
			if(cur->_parent == NULL)
			{
				_root = new Node;
				_root->_key[0] = key;
				_root->_childs[0] = cur;
				_root->_childs[1] = tmp;
				_root->_size = 1;

				tmp->_parent = _root;
				cur->_parent = _root;

				return true;
			}
			cur = cur->_parent;
			child = tmp;
		}
	}
protected:
	void _InOrder(Node* root)
	{
		if(root == NULL)
		{
			return;
		}
		for(size_t i = 0;i < root->_size;++i)
		{
			_InOrder(root->_childs[i]);
			cout<<root->_key[i]<<" ";
		}
		_InOrder(root->_childs[root->_size]);
	}
	void _InsertKey(Node*cur, const K& key,Node* child)//直接插入法
	{
		int i = cur->_size - 1;
		while(i >= 0)
		{
			if(cur->_key[i] > key)
			{
				cur->_key[i + 1] = cur->_key[i];
				cur->_childs[i + 2] = cur->_childs[i+1];

				--i;
			}
			else
			{
				break;
			}
		}
		cur->_key[i+1] = key;
		cur->_childs[i + 2] = child;
		if(child)
		{
			child->_parent = cur;
		}
		cur->_size++;
	}
protected:
	Node* _root;
};
