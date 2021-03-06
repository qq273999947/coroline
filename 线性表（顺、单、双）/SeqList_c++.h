#pragma once
using namespace std;
typedef int DataType;
class SeqList
{
public:
	SeqList()
		:_array(NULL)
		,_capacity(0)
		,_size(0)
	{}
	SeqList(DataType *p,size_t size)
		:_array(new  DataType[size])
		,_capacity(size)
		,_size(size)
	{
		memcpy(_array,p,size*sizeof(DataType));
	}
	SeqList(const SeqList &s)
	{
		_array = new DataType[s._size];
		memcpy(_array,s._array,s._size*sizeof(DataType));
		_capacity = s._capacity;
		_size = s._size;
	}
	SeqList& operator=(const SeqList &s)
	{
		if(this != &s)
		{
			_array = new DataType[s._size];
			memcpy(_array,s._array,s._size*sizeof(DataType));
			_capacity = s._capacity;
			_size = s._size;
		}
		return *this;
	}
	~SeqList()
	{
		if(_array)
		{
			delete[] _array;
		}
	}
	void PushBack(char ch)
	{
		++_size;
		_array = _CheckCapacity();
		
		_array[_size] = ch;
	}
	void PopBack()
	{
		_array[_size - 1] = 0;
		--_size;
	}
	void Insert(size_t pos,char ch)
	{
		assert(pos <= _size);

		++_size;
		_array = _CheckCapacity();

		for(size_t i = _size;i >= pos;--i)
		{
			_array[i] = _array[i - 1];	
		}
		_array[pos -1] = ch;
	}
	int Find(char ch)
	{
		for(size_t i = 0;i<_size;i++)
		{
			if(_array[i] == ch)
			{
				return i;
			}
		}
		return -1;
	}
	void Erase(size_t pos)
	{
		assert(pos < _size);
      	for(size_t i = pos;i<_size;i++)
		{
			_array[i] = _array[i + 1];
		}
		_size--;
	}
	DataType& operator[](size_t index)
	{
		return _array[index];
	}
	void Reserve(size_t size)
	{
		_size = size;
		_array = _CheckCapacity();
	}
	void Clear()
	{
		SeqList tmp;
		swap(_array,tmp._array);
		swap(_size,tmp._size);
		swap(_capacity,tmp._capacity);
	}
private:
	DataType *_CheckCapacity()
	{
		if(_size >= _capacity)
		{
			size_t NewCapacity = (_capacity * 2 > (_size + 1) )? _capacity * 2:(_size+1);
			_array = (DataType *)realloc(_array,NewCapacity);
			_capacity = NewCapacity;
			return _array;
		}
		return _array;
	}
	DataType* _array;
	size_t _capacity;
	size_t _size;
};