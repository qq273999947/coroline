#include <iostream>
using namespace std;

template<class T>
class ScopedPtr
{
public:
	ScopedPtr(const T* ptr = NULL)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		delete _ptr;
	}
private:
	ScopedPtr<T> (ScopedPtr<T>& ptr);
	ScopedPtr<T>operator=(ScopedPtr<T>& ptr);
	T* _ptr;
};
