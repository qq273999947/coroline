#pragma once
using namespace std;
typedef int DataType;
class SlistNode
{
	friend class Slist;
public:
	SlistNode(const DataType x)
		:_data(x)
		,_next(NULL)
	{}
	void Swap(SlistNode &s)
	{
		swap(_next,s._next);
		swap(_data,s._data);
	}
private:
	DataType _data;
	SlistNode *_next;
};

class Slist
{
public:
	Slist()
		:_head(NULL)
		,_tail(NULL)
	{}
	//Slist(const Slist &s)//正规
	//{
	//	if(s._head == NULL)
	//	{
	//		_head = _tail = NULL;
	//	}
	//	else if(s._head == s._tail)
	//	{	
	//		_head = new SlistNode(s._head->_data);
	//		_head = _tail;
	//	}
	//	else
	//	{
	//		_head = new SlistNode(s._head->_data);
	//		_tail = _head;
	//		SlistNode *tail = s._head->_next;
	//		while(tail)
	//		{
	//			_tail->_next = new SlistNode(tail->_data); 
	//			_tail = _tail->_next;
	//			tail = tail->_next;
	//		}
	//	}
	//}
	Slist(const Slist& s)//lazy way
		: _head(NULL)
		, _tail(NULL)
	{
		SlistNode *cur = s._head;
		while (cur)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	Slist& operator=(const Slist &s)
	{
		if(this != &s)
		{
			if(_head != NULL)
			{
				Clear();
			}			
		    _head = _tail = NULL;
			SlistNode *cur = s._head;
			while (cur)
			{
				PushBack(cur->_data);
				cur = cur->_next;
			}	
		}	
		return *this;
	}
	~Slist()
	{
		Clear();
		_head = NULL;
		_tail = NULL;
	}
	void Clear()
	{
		SlistNode *begin = _head;
		while(begin)
		{
			SlistNode *tmp = begin;
			begin = begin->_next;
			delete tmp;
		}
	}
	void PushBack(const DataType x)
	{
		if(_head == NULL)
		{
			_head = new SlistNode(x);
			_tail = _head;
		}
		else
		{
			_tail->_next = new SlistNode(x);
			_tail = _tail->_next;
		}
	}
	void PopBack()
	{
		assert(_head != NULL);
		if(_head == _tail)
		{
			delete _head;
			_head = NULL;
			_tail =NULL;
		}
		else
		{		
			SlistNode *del = _head;
			while(del->_next->_next != NULL)
			{
				del = del->_next;
			}
			swap(del,_tail);
			delete del;
			_tail->_next = NULL;
		}
	}
	void Print()
	{
		SlistNode *begin = _head;
		while(begin)
		{
			cout<<begin->_data<<"->";
			begin = begin->_next;
		}
		cout<<"NULL"<<endl;
	}
	void PushFront(const DataType x)
	{
		SlistNode *tmp = new SlistNode(x);
		tmp->_next = _head;
		_head = tmp;
	}
	void PopFront()
	{
		SlistNode *del = _head;
		_head= _head->_next;
		delete del;
	}
	SlistNode *Find(const DataType x)
	{
		assert(_head != NULL);
		SlistNode *begin = _head;
		while(begin)
		{
			if(begin->_data == x)
			{
				return begin;
			}
			begin = begin->_next;
		}
		return NULL;
	}
	void Remove(DataType x)//找到x并删除
	{
		SlistNode *del = Find(x);
		Erase(del);
	}
	void Reverse()
	{
		SlistNode *newhead = NULL,*cur = _head;;

		while(cur)
		{
			SlistNode *tmp = cur;
			cur = cur->_next;

			tmp->_next = newhead;
			newhead = tmp;
		}
		_head = newhead;
	}
	void Slist::Erase(SlistNode *pos)	//删除指针指向的节点
	{
		assert(pos != NULL);
		if(pos->_next == NULL)
		{
			PopBack();
		}
		else if(pos == _head)
		{
			PopFront();
		}
		else
		{
			swap(pos->_data ,pos->_next ->_data );
			pos->_next = pos->_next->_next ;
			delete pos->_next ;
		}
	}
	void Slist::Insert(SlistNode* pos, DataType x)//在位置pos插入x
	{
		SlistNode *tmp = new SlistNode(x);
		tmp->_next = pos->_next;
		pos->_next = tmp;
	}
private:
	SlistNode *_head;
	SlistNode *_tail;
};

