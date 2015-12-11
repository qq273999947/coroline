#include <iostream>
#include<windows.h>
#include<assert.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		int len =  strlen(str);
		_capacity = len +1;
		_size = len;
		_str = new char[_capacity];
		strcpy(_str, str);
	}
	String(const String& s)
		:_str(new char[1]())
	{
		String tmp = s._str;
		StringSwap(tmp);
	}

	String& operator=(String s)
	{
		StringSwap(s);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
	void Display()
	{
		cout<<_str<<endl;
	}
	bool operator>(const String& s)
	{
		return (MyStrcmp(_str,s._str) > 0);
	}
	bool operator<(const String& s)
	{
		return (MyStrcmp(_str,s._str) < 0);
	}
	bool operator>=(const String& s)
	{
		return (MyStrcmp(_str,s._str) >= 0);
	}
	bool operator<=(const String& s)
	{
		return (MyStrcmp(_str,s._str) <= 0);
	}
	bool operator==(const String& s)
	{
		return (MyStrcmp(_str,s._str) == 0);
	}
	void PushBack(char ch)
	{
		int len = 1;
		_size += len;
		_str = _CheckCapacity();
		
		_str[_size - 1] = ch;
	}
	void Insert(size_t pos,char ch)
	{
		assert(pos < _size);
		int len = 1;
		_size += len;
		_str = _CheckCapacity();

		for(size_t i = _size;i >= pos;--i)
		{
			_str[i] = _str[i - 1];	
		}
		_str[pos -1] = ch;
	}
	void Insert(size_t pos,const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		_size += len;
		_str = _CheckCapacity();

		for(size_t i =_size;i >= pos;i--)
		{
			_str[i] = _str[i - len];
		}
		for(size_t i = 0;i < len;i++)
		{
			_str[pos + i] = str[i];
		}
	}
	char& operator[](size_t index)
	{
		return _str[index];
	}
	int Find(char ch)
	{
		for(size_t i = 0;i<_size;i++)
		{
			if(_str[i] == ch)
			{
				return i;
			}
		}
		return -1;
	}
	int Find(const char *str)//"hello world" "wor" ->6
	{
		const char *pscr = _str;
		const char *psub = str;

		int scrlen = _size;
		int sublen = strlen(str);

		int scrIndex = 0;
		while(scrIndex <= scrlen - sublen)
		{
			int i = scrIndex;
			int j = 0;
			while(scrlen > i && j < sublen && pscr[i] == psub[j])
			{
				i++;
				j++;
			}
			if(j == sublen)
			{
				return scrIndex;
			}
			++scrIndex;
		}
		return -1;
	}
	void Erase(size_t pos)
	{
		assert(pos < _size);
      	for(size_t i = pos;i<_size;i++)
		{
			_str[i] = _str[i + 1];
		}
		_size--;
	}
	void Erase(size_t pos,size_t n)
	{
		assert(pos < _size - n);
      	for(size_t i = pos;i<_size;i++)
		{
			_str[i] = _str[i + n];
		}
		_size -= n;
	}
private:
	char *_CheckCapacity()
	{
		if(_size >= _capacity)
		{
			size_t NewCapacity = (_capacity * 2 > (_size + 1) )? _capacity * 2:(_size+1);//这里之所以要加1是因为当插入一个字母时，_size与_capacity相等,要是不开辟多余的一个空间 ，那么那个/0就不能往后移动，会越界。
			_str = (char *)realloc(_str,NewCapacity);
			_capacity = NewCapacity;
			return _str;
		}
		return _str;
	}
	void StringSwap(String &s)
	{
		swap(_str,s._str);
		swap(_size,s._size);
		swap(_capacity,s._capacity);		
	}
	int MyStrcmp(const char *str1,const char *str2)
	{
		while((*str1++ == *str2++))
		{
			if(*str1 =='\0')
			{
				return 0;
			}
		}
		if(*str1 > *str1)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	char* _str;
	size_t _capacity;
	size_t _size;
};

void Test1()
{
	String s1("hello world");
	s1.Display();
	String s2(s1);
	s2.Display();
	String s3("change world");
	s1 = s3;
	s1.Display();
}
void Test2()
{
	String s1("ello world");
	s1.Insert(1,'H');
	s1.Display();
}
void Test3()
{
	String s1("hellorld");
	char *str = " wo";
	s1.Insert(5,str);
	s1.Display();
}
void Test4()
{
	String s1("Hello");
	cout<<s1[0]<<endl;
}
void Test5()
{
	String s1("hello world");
	cout<<s1.Find("ll")<<endl;
}
void Test6()
{
	String s1("hello world");
	s1.Erase(2,3);
	s1.Display();
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	system("pause");
	return 0;
}