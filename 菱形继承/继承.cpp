#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f1()
	{
		cout<<"Bsse::f1"<<endl;
	}

	virtual void f2()
	{
		cout<<"Bsse::f2"<<endl;
	}

public:
	int _b;
};

class Base1: virtual public Base
{
public:
	virtual void f1()
	{
		cout<<"Bsse1::f1"<<endl;
	}

	virtual void f3()
	{
		_b1 = 10;
		cout<<"Bsse1::f3"<<endl;
	}

	int _b1;
};

class Base2: virtual public Base
{
public:
	virtual void f1()
	{
		cout<<"Bsse2::f1"<<endl;
	}

	virtual void f4()
	{
		cout<<"Bsse2::f4"<<endl;
	}

	int _b2;
};

class Derive: public Base1, public Base2
{
public:
	virtual void f1()
	{
		_d = 10;
		cout<<"Derive::f1"<<endl;
	}

	virtual void f3()
	{
		this->_d = 10;
		cout<<"Derive::f3"<<endl;
	}

	virtual void f4()
	{
		cout<<"Derive::f4"<<endl;
	}

	virtual void f5()
	{
		cout<<"Derive::f5"<<endl;
	}
	int _d;
};


typedef void(__thiscall*FUNC)(Derive*);

void PrintVTable (int* VTable, Derive* that)
{
	cout<<" 虚表地址>"<< VTable<<endl ;
	FUNC* VF = (FUNC*)VTable;
	for (int i = 0; VTable[i ] != 0; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i , VTable[i ]);
		FUNC f = (FUNC)VTable[i];
		f(that);
	}

	cout<<endl ;
}


void Test()
{
	Derive d;

	d.Base1::_b = 1;
	d.Base2::_b = 2;

	d._b1 = 3;
	d._b2 = 4;
	d._d = 5;

	int* vTable = (int*)(*(int*)&d);
	PrintVTable(vTable, &d);
}

int main()
{
	Test();

	return 0;
}