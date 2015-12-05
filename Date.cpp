#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1900,int month = 1,int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{ 
	}
	Date(Date &day)
	{
		_year = day._year;
		_month = day._month;
		_day = day._day;
	}
	~Date()
	{
		
	}
	void Display(Date &day)
	{
		cout<<day._year<<" "<<day._month<<" "<<day._day<<endl;
	}
	int GetMonDay(int year,int month)
	{
		static int monthArr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

		int day = monthArr[month - 1];
		if((month == 2) && (year%400 == 1 || (year%4 == 1 && year%100 != 1)))
		{
			day++;
		}

		return day;
	}
	bool operator==(Date day2)
	{
		return 	(this->_year == day2._year)&&
		        (this->_month = day2._month)&&
		         (this->_day = day2._day);
	}
    int operator-(Date d)//两个日期相减算天数
	{
		Date tmp;
		//保证this指向较后日期
		if ((this->_year > d._year) || (this->_year == d._year && this->_month > d._month)||
			(this->_year == d._year && this->_month == d._month && this->_day > d._day))  
		{  
			tmp = d;  
			d = *this;  
			*this = tmp;  
		}
		int MonDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		//计算较后日期所差的日子
        int Diff1 = _day - 1;
		for(int i =_month; i > 1; i--)
		{
			Diff1 +=  MonDay[i - 1];
			if((i == 2) && (_year%400 == 0 || (_year%4 == 0 && _year%100 != 0)))
			{
				Diff1++;
			}
		}
	    //计算较前日子所差的日子
        int Diff2 = d._day - 1;
		for(int j = d._month; j > 1; j--)
		{
			Diff2 +=  MonDay[j - 1];
			if((j == 2) && (d._year%400 == 0 || (d._year%4 == 0 && d._year%100 != 0)))
			{
				Diff2++;
			}
		}
		if(d._year > _year)
		{
			for(int i = d._year; i > _year; i--)
			{
				Diff2 += 365;
				if(i%400 == 0 || (i%4 == 0 && i%100 != 0))
				{
					Diff2++;
				}
			}
		}
		int Diff = Diff2 - Diff1;
		return Diff;					
	}
//第二种方法：把一个日子一步一步加到另一个日子，加的次数即所差天数
//	int operator-(const Date& d)
//	{
//		int flag = 1;
//		Date max = *this;
//		Date min = d;
//
//		if (*this < d)
//		{
//			min = *this;
//			max = d;
//			flag = -1;
//		}
//
//		int days = 0;
//		//while (min._year < max._year)
//		//{
//			//days += 365;
//			//if () // 润年
//			//{
//			//}
//		//}
//
//		while (min != max)
//		{
//			++min;
//			days++;
//		}
//
//		return flag*days;
//	}
	Date& operator+(int day)
	{
		if(day < 0)
		{
			return *this - (-day);
		}
		_day += day;
		while(_day > GetMonDay(_year,_month))
		{
			if(_month < 12)
			{
				_month++;
				_day -= GetMonDay(_year,_month);
			}
			else
			{
				_year++;
				_month = 1;
				_day -= GetMonDay(_year,_month);
			}
		}
		return *this;
	}
	Date& operator-(int day)
	{
		if(day < 0)
		{
			return *this + (-day);
		}
		_day -= day;
		while(_day < 1)
		{
			if(_month == 1)
			{
				_year--;
				_month += 12;
				_day +=  GetMonDay(_year,_month);
			}
			else
			{
				_month--;
				_day +=  GetMonDay(_year,_month);
			}
		}
		return *this;
	}
	Date& operator+=(int days)
     {
         *this = *this + days;
         return *this;
     }

     Date& operator-=(int days)
     {
         *this = *this - days;
         return *this;
     }

	Date& operator++()
	{
		if(_day == GetMonDay(_year,_month))
		{
			if(_month == 12)
			{
				_year++;
				_month = 1;
				_day = 1;
			}
			_month++;
			_day = GetMonDay(_year,_month);
		}
		_day++;
		return *this;
	}
	Date operator++(int)
	{
		Date *tmp = this;
		if(_day == GetMonDay(_year,_month))
		{
			if(_month == 12)
			{
				_year++;
				_month = 1;
				_day = 1;
			}
			_month++;
			_day = GetMonDay(_year,_month);
		}
		_day++;
		return *tmp;
	}

	Date& operator--()
	{
		if(_day = 1)
		{
			if(_month = 1 )
			{
				_year--;
				_month = 12;
				_day = GetMonDay(_year,_month);
				return *this;
			}
			_month--;
			_day = GetMonDay(_year,_month);
			return *this;
		}
		_day--;
		return *this;
	}
	Date operator--(int)
	{
		Date *tmp = this;
		if(_day = 1)
		{
			if(_month = 1 )
			{
				_year--;
				_month = 12;
				_day = GetMonDay(_year,_month);
				return *this;
			}
			_month--;
			_day = GetMonDay(_year,_month);
			return *this;
		}
		_day--;
		return *tmp;
	}
	istream& operator>>(istream& is, Date& d)
	{
		cout<<"请输入一个日期的年月日:";
		is>>d._year>>d._month>>d._day;

		return is;
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		cout<<d._year<<"-"<<d._month<<"-"<<d._day<<endl;
		return os;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	int year,month,day,count;
	int select = 1;
	Date d1;
	Date d2;
	while(select)
	{
		cout<<"**************************************"<<endl;
		cout<<"*[0]退出"<<endl;
		cout<<"*[1]推算几天后的日期，请输入："<<endl;
		cout<<"*[2] 两个日期之间的天数，请输入：  "<<endl;
		cout<<"**************************************"<<endl;
		cout<<"请选择:>"<<endl;
		cin>>select;
		switch(select)
		{
		case 0:
			break;
		case 1:
			cout<<"请输入日期和天数，例：2013 1 12 100    "<<endl;
			cin>>d1._year>>d1._month>>d1._day>>count;
			d2 = d1 + count;
			d2.Display(d2);
			break;

		case 2:
			cout<<"请输入两个日期，例：2013 1 12  2012 1 1  "<<endl;
			break;

		}
	}

	return 0;
}