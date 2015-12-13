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
	char&operator[](size_t pos)
	{
		if(--GetRefCount(_str) != 0)
		{
			char *tmp = new char[strlen(_str) + 5];	
			--GetRefCount(_str);
			tmp += 4;
			strcpy(tmp,_str);
			_str = tmp;
			tmp = NULL;
			GetRefCount(_str) = 1;
		}
		return _str[pos];
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
	String s1("111111111111111111111");
	String s2(s1);

	String s3("222222222222222222222");
	s1 =s1;
}
void Test2()
{
	String s1("11211111111111111111");
	cout<<s1[2]<<endl;

}
int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}