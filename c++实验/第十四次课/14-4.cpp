#include <iostream>
#include <iomanip>

class CDate {
private:
	int year;
	int month;
	int day;
	
public:
	CDate(int y, int m, int d) : year(y), month(m), day(d) {}
	
	// 显示日期的函数
	void displayDate() const {
		std::cout << year << "年" << month << "月" << day << "日";
	}
	
	// 日期的小于比较运算符重载
	bool operator<(const CDate& other) const {
		if (year < other.year)
			return true;
		else if (year == other.year && month < other.month)
			return true;
		else if (year == other.year && month == other.month && day < other.day)
			return true;
		return false;
	}
	
	// 日期的加法运算符重载
	CDate operator+(int days) const {
		CDate result = *this;
		// 简单处理，不考虑闰年等情况
		result.day += days;
		return result;
	}
};

class CTime {
private:
	int hour;
	int minute;
	int second;
	
public:
	CTime(int h, int m, int s) : hour(h), minute(m), second(s) {}
	
	// 显示时间的函数
	void displayTime() const {
		std::cout << std::setfill('0') << std::setw(2) << hour << ":"
		<< std::setw(2) << minute << ":" << std::setw(2) << second;
	}
	
	// 时间的小于比较运算符重载
	bool operator<(const CTime& other) const {
		if (hour < other.hour)
			return true;
		else if (hour == other.hour && minute < other.minute)
			return true;
		else if (hour == other.hour && minute == other.minute && second < other.second)
			return true;
		return false;
	}
	
	// 时间的加法运算符重载
	CTime operator+(int seconds) const {
		CTime result = *this;
		result.second += seconds;
		if (result.second >= 60) {
			result.minute += result.second / 60;
			result.second %= 60;
		}
		if (result.minute >= 60) {
			result.hour += result.minute / 60;
			result.minute %= 60;
		}
		return result;
	}
};

class CDateTime : public CDate, public CTime {
public:
	CDateTime(int y, int m, int d, int h, int min, int s)
	: CDate(y, m, d), CTime(h, min, s) {}
	
	// 显示日期时间的函数
	void displayDateTime() const {
		displayDate();
		std::cout << " ";
		displayTime();
	}
};

int main() {
	// 测试代码
	CDate date1(2023, 12, 7);
	CDate date2(2023, 12, 8);
	
	if (date1 < date2) {
		std::cout << "date1 小于 date2" << std::endl;
	}
	
	CDate resultDate = date1 + 5;
	std::cout << "date1 + 5 天后的日期：";
	resultDate.displayDate();
	std::cout << std::endl;
	
	CTime time1(12, 30, 45);
	CTime time2(14, 15, 30);
	
	if (time1 < time2) {
		std::cout << "time1 小于 time2" << std::endl;
	}
	
	CTime resultTime = time1 + 120;
	std::cout << "time1 + 120 秒后的时间：";
	resultTime.displayTime();
	std::cout << std::endl;
	
	CDateTime dateTime(2023, 12, 7, 12, 30, 45);
	std::cout << "日期时间：";
	dateTime.displayDateTime();
	std::cout << std::endl;
	
	return 0;
}

