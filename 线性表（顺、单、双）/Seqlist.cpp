#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SeqList
{
public:
	SeqList()
		:_size(0)
		,_capacity(0)
		,_data(NULL)

	{}
	SeqList( const SeqList<T>&s )
	{
		_data = new T[s._size];
		for(size_t i = 0;i <s._size ; ++i)
		{
			_data[i] = s._data[i];
		}
		_capacity = s._capacity;
		_size = s._size;
	}
	~SeqList()
	{
		delete [] _data;
		_size = 0;
		_capacity = 0;
	}
	SeqList<T>& operator=(const SeqList<T>&s )
	{
		if(this != &s)
		{
			if(_data)
			{
				delete[] _data;
			}
			_data = new T[s._size];
			for(size_t i = 0;i <s._size ; ++i)
			{
				_data[i] = s._data[i];
			}
			_capacity = s._capacity;
			_size = s._size;
		}
		return *this;
	}
	void PushBack(const T &x)
	{
		_CheckCapacity();
		_data[_size++] = x;
	}
	void Print()
	{
		for(int i=0;i < _size ;i++)
		{
			cout<<_data[i]<<" ";
		}
		cout<<endl;
	}
	void PopBack()
	{
		_data[_size - 1] = "0";
		--_size;
	}
	void PushFront(const T &x)
	{
		_CheckCapacity();
		for(int i = _size;i > 0;--i)
		{
			_data[i] = _data[i -1];
		}
		_data[0] = x;
		++_size;
	}
	void PopFront()
	{
		for(int i = 0;i < _size;++i)
		{
			_data[i] = _data[i + 1];
		}
		--_size;
	}
	int Find(const T &x)
	{
		for(int i = 0;i<_size;++i)
		{
			if(_data[i] == x)
			{
				return i;
			}
		}
		return -1;
	}

private:
	void _CheckCapacity()
	{
		if(_size >= _capacity)
		{
			_capacity = (_capacity * 2)>(_size+1)? _capacity*2: (_size+1);
			//_data = (T*)realloc(_data,sizeof(T)*_capacity);
			T* tmp = new T[_capacity];
			if(_size)
			{
				for(size_t i = 0;i <_size ; ++i)
				{
					tmp[i] = _data[i];
				}
				delete[] _data;
			}
			_data = tmp;
		}
	}
	size_t _size;
	size_t _capacity;
	T* _data;
};
int main()
{
	SeqList<string> s1;
	s1.PushBack("x1");
	s1.PushBack("x2");
	s1.PushBack("x3");
	s1.PushBack("x4");
	s1.PushBack("x5");
	s1.Print();
	cout<<s1.Find("x2")<<endl;
	//s1.Print();

// 	SeqList<string> s2;
// 	s2.PushBack("ssssssssssssssssssss");
// 	s2.PushBack("2");
// 	s2.PushBack("3");
// 	s2.PushBack("4ssssssssssssssss");
// 	s2.PushBack("x5");
// 	s2.Print();
// 	s2 = s1;
// 	s2.Print();
// 	SeqList<int> s1;
// 	s1.PushBack(1);
// 	s1.PushBack(2);
// 	s1.PushBack(3);
// 	s1.PushBack(4);
// 	s1.PushBack(5);
// 	s1.Print();

	return 0;
}