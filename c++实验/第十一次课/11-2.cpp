#include <iostream>
#include <windows.h>
using namespace	std;


class Date{
	int Year,Month,Day;
public:
	Date(int y=0,int m=0,int d=0){Year=y; Month=m; Day=d;}
	void SetDate(int y,int m,int d){Year=y;Month=m;Day=d;}
	void ShowDate(){cout<<Year<<"-"<<Month<<"-"<<Day;}
};


class Time{
	int Hour,Minute,Second;
public:
	Time(int h=0,int m=0,int s=0){Hour=h; Minute=m; Second=s;}
	void SetTime(int h,int m,int s){Hour=h;Minute=m;Second=s;}
	void ShowTime(){cout<<Hour<<":"<<Minute<<":"<<Second;}
};


class DateTime:public Date, public Time{
public:
	DateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0):Date(year,month,day),Time(hour,minute,second){};
				
	void SetDateTime(int year=0,int month=0,int day=0,int hour=0,int minute=0,int second=0)
	{
		SetDate(year, month, day);
		SetTime(hour, minute, second);
	}
	
	void ShowDateTime()
	{
		ShowDate();
		cout << " ";
		ShowTime();
		cout << endl;
	}
	
};


int main(){
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	DateTime dt(sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond);
	cout << "当前日期和时间为";
	dt.ShowDateTime();
	
	char flag='y';
	cout<<"是否需要修改日期和时间？(y/n)";
	cin>>flag;
	while(tolower(flag)=='y'){
		cout<<"请输入新的日期和时间：";
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second; 
		
		cin >> year >> month >> day >> hour >> minute >> second;
		dt.SetDateTime(year, month, day, hour, minute, second);
		
		cout << "修改后的日期和时间为";
		dt.ShowDateTime();
		
		cout<<"------------------------------------------"<<endl;
		cout<<"是否继续修改日期和时间?(y/n)";
		cin>>flag;
	}
	
	
	return 0;
}

