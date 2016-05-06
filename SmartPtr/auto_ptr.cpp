#include <iostream>
using namespace std;

template <class T>
class AutoPtr
{
public:
	AutoPtr(const T* ptr = NULL)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>&a)
	{
		
		_ptr = a._ptr;
		a._ptr = NULL;
	}
	AutoPtr<T> operator=(AutoPtr<T>& a)
	{
		if(this != &ptr)
		{
			_ptr = a._ptr;
			a._ptr = NULL;
		}
		return *this;
	}
	T& operator*()const
	{
		return *_ptr;
	}
	T* operator->()const
	{
		return _ptr;
	}
	~AutoPtr()
	{
		delete _ptr;
	}
private:
	T *_ptr;
	
};
int main()
{
	return 0;
}