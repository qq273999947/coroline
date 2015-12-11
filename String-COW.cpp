#include<iostream>
#include<windows.h>
using namespace std;
class String
{
public:
	String(const char *str)
		:_str(new char[strlen(str) + 5])
	{
		GetRefCount(_str) = 1;
		_str += 4;
		strcpy(_str,str);
	}
	String(const String &s)
		:_str(s._str)
	{
		++GetRefCount(_str);
	}
	String operator=(const String&s)
	{
		if(_str != s._str)
		{
			Release(_str);
			_str = s._str;
			++GetRefCount(_str);
		}
		return *this;
	}
	~String()
	{
		Release(_str);
	}
private:
	void Release(char *p)
	{
		if(--GetRefCount(_str) == 0)
		{
			delete [] (p - 4);
		}
	}
	int& GetRefCount(char *p)
	{
		return *(int *)(p - 4);
	}
	char *_str;
};
void Test1()
{
	String s1("11111");
	String s2(s1);

	String s3("22222");
	s1 =s1;
}
int main()
{
	Test1();
	system("pause");
	return 0;
}