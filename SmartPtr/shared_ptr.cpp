#include <iostream>
using namespace std;

template<class T>
class SharePtr
{
public:
	SharePtr(const T* ptr = NULL)
		:_pCount(new int(1))
		:_ptr(ptr)
	{}
	SharePtr(SharePtr<T>& s)
	{
		++(*s._pCount);
		_pCount = s._pCount;
		_ptr = s._ptr;
	}
	SharePtr<T> operator=(SharePtr<T>& s)
	{
		if(this != &s)
		{
			if(--(*_pCount) == 0)
			{
				delete _pCount;
				delete _ptr;
			}
			++(*s._pCount);
			_pCount = s._pCount;
			_ptr = s._ptr;
		}
		return *this;
	}
	~SharePtr()
	{
		if(--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
		}
	}
private:
	int *_pCount;
	T *_ptr;
};