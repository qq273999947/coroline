#include <iostream>
#include<string>
using namespace std;

class Exception
{
public:
	Exception(const int errId,const char *errMess)
		:_errId(errId)
		,_errMess(errMess)
	{}
	void what()
	{
		cout<<_errId<<endl;
		cout<<_errMess<<endl;
	}
private:
	int _errId;
	string _errMess;
};

void Test1()
{
	try
	{
		int i =1;
		throw i;
	}
	catch(...)
	{
		cout<<"Î´Öª´íÎó"<<endl;
	}
}

int main()
{
	Test1();
	return 0;
}