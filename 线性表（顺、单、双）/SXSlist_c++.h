#pragma once
using namespace std;
typedef int DataType;
class SlistNode
{
public:
	SlistNode(const DataType x)
		:_data(x)
		,_next(NULL)
		,_pre(NULL)
	{}
	friend class Slist;
	friend ostream &operator<<(ostream &out,const SlistNode &s);
private:
	void Swap(SlistNode &s)
	{
		swap(_data,s._data);
		swap(_pre,s._pre);
		swap(_next,s._next);
	}
	DataType _data;
	SlistNode *_next;
	SlistNode *_pre;
};
ostream &operator<<(ostream &out,const SlistNode &s)
{
	out << s._data;
	return out;
}
class Slist
{
public:
	Slist()
		:_head(NULL)
		,_tail(NULL)
	{}
	Slist(const Slist &s)
	{
			if(s._head ==NULL)
			{
				_head = _tail = NULL;
			}
			else if(s._head == s._tail)
			{
				_head = new SlistNode(s._head->_data);
				_tail = _head;
			}
			else
			{
				_head = new SlistNode(s._head->_data);
				_tail = _head;
				SlistNode *curs = s._head->_next;
				while(curs)
				{
					SlistNode *cur = new SlistNode(curs->_data);
					_tail->_next = cur;
					cur ->_pre = _tail;
					_tail = _tail->_next;
					curs = curs->_next;
				}
			}
	}
	Slist& operator=(const Slist &s)
	{
		if(this != &s)
		{
			Clear();
			if(s._head ==NULL)
			{
				_head = _tail = NULL;
			}
			else if(s._head == s._tail)
			{
				_head = new SlistNode(s._head->_data);
				_tail = _head;
			}
			else
			{
				_head = new SlistNode(s._head->_data);
				_tail = _head;
				SlistNode *curs = s._head->_next;
				while(curs)
				{
					SlistNode *cur = new SlistNode(curs->_data);
					_tail->_next = cur;
					cur ->_pre = _tail;
					_tail = _tail->_next;
					curs = curs->_next;
				}
			}
			
		}
		return *this;
	}
	void PopBack()
	{
		assert(_head != NULL);
		if(_head == _tail)
		{
			delete _head;
			_head = _tail =	NULL;
		}
		else
		{
			_tail = _tail->_pre;
			delete _tail->_next;
			_tail->_next = NULL;
		}
	}
	void PushFront(const DataType x)
	{
		SlistNode *tmp = new SlistNode(x);
		if(_head == NULL)
		{
			_head = _tail = tmp;
		}
		else
		{
			_head->_pre = tmp;
			tmp->_next = _head;
			_head = tmp;
		}
	}
	void PopFront()
	{
		assert(_head != NULL);
		if(_head == _tail)
		{
			delete _head;
			_head = _tail = NULL;
		}
		else
		{
			_head = _head->_next;
			delete _head->_pre;
			_head->_pre = NULL;
		}
	}
	SlistNode *Find(const DataType x)
	{
		SlistNode *cur = _head;
		while(cur)
		{
			while(cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}
	void Remove(DataType x)//找到x并删除
	{
		SlistNode *del =Find(x);
		if(del == _head)
		{
			PopFront();
		}
		else if(del == _tail)
		{
			PopBack();
		}
		else
		{
			del->_pre->_next = del->_next;
			del->_next->_pre = del->_pre;
			delete del;
		}
	}
	void Reverse()
	{
		SlistNode *cur = _head;
		while(cur)
		{
			swap(cur->_next,cur->_pre);
			cur = cur->_pre;
		}
		swap(_head,_tail);
	}
	void Slist::Erase(SlistNode *pos)//删除指针指向的节点
	{
		Remove(pos->_data);
	}
	void Insert(SlistNode* pos, DataType x)//在位置pos插入x
	{
		assert(pos != NULL);
		if(pos == _head)
		{
			PushFront(x);
		}
		else
		{
			SlistNode *tmp = new SlistNode(x);
			tmp->_next = pos;
			tmp->_pre = pos->_pre;
			tmp->_pre->_next = tmp;
			tmp->_next->_pre = tmp;
			
		}
	}
	~Slist()
	{
		Clear();
		_head = NULL;
		_tail = NULL;
	}
	void Clear()
	{
		SlistNode *cur = _head;
		while(cur)
		{
			SlistNode *del = cur;
			cur = cur->_next ;
			delete del;
		}
	}
	void PushBack(DataType x)
	{
		SlistNode *tmp = new SlistNode(x);
		if(_head == NULL)
		{
			_head = _tail = tmp;
		}
		else
		{
			_tail->_next =tmp;
			tmp->_pre = _tail;
			_tail = _tail->_next ;
		}
	}
	void Print()
	{
		SlistNode *cur = _head;
		while(cur)
		{
			cout<<cur->_data<<"->";
			cur = cur->_next;
		}
		cout<<"NULL"<<endl;
	}
private:
	SlistNode *_head;
	SlistNode *_tail;
};
