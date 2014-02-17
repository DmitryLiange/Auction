// Created by group 3.1.2 
#include "Date.h"
#include <string>  

Date::Date() : month(0), day(0), year(0), hour(0), minute(0), second(0) {}

Date::Date(int month, int day, int year, int hour, int minute, int second) : 
month(month), day(day), year(year), hour(hour), minute(minute), second(second) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

int Date::getHour() const {
	return hour;
}

int Date::getMinute() const {
	return minute;
}

int Date::getSecond() const {
	return second;
}

void Date::setYear(int& newYear) {
	this->year = newYear;
}

void Date::setMonth(int& newMonth) {
	this->month = newMonth;
}

void Date::setDay(int& newDay) {
	this->day = newDay;
}

void Date::setHour(int& newHour) {
	this->hour = newHour;
}

void Date::setMinute(int& newMinute) {
	this->minute = newMinute;
}

void Date::setSecond(int& newSecond) {
	this->second = newSecond;
}

ostream &operator<< (ostream &stream, const Date &date) {
	if (date.getMonth() < 10) {
		stream << "0" << date.getMonth() << "/";
	} else { 
		stream << date.getMonth() << "/";
	}

	if (date.getDay() < 10) {
		stream << "0" << date.getDay() << "/";
	} else {
		stream << date.getDay() << "/";
	}
	stream << date.getYear() << " ";

	if (date.getHour() < 10) {
		stream << "0" << date.getHour() << ":";
	} else { 
		stream << date.getHour() << ":";
	}

	if (date.getMinute() < 10) {
		stream << "0" << date.getMinute() << ":";
	} else { 
		stream << date.getMinute() << ":";
	}

	if (date.getSecond() < 10) {
		stream << "0" << date.getSecond();
	} else {
		stream << date.getSecond();
	}
	return stream;
}

istream &operator>>(istream& stream, Date& date) {
	string date_string;
	getline(stream, date_string);

	int strPosition = date_string.find_first_of("/", 0);
	int month = atoi(date_string.substr(0, strPosition).c_str());
	date.setMonth(month);

	int day = atoi(date_string.substr(strPosition + 1, date_string.find_last_of("/", 0)).c_str());
	date.setDay(day);

	strPosition = date_string.find_first_of("/", strPosition + 1) + 1;
	int strPosition2 = date_string.find_first_of(" ", strPosition) + 1;
	int year = atoi(date_string.substr(strPosition, strPosition2).c_str());
	date.setYear(year);

	int strPosition3 = date_string.find_first_of(":", strPosition2 + 1);
	int hour = atoi(date_string.substr(strPosition2, strPosition3).c_str());
	date.setHour(hour);

	int strPosition4 = date_string.find_first_of(":", strPosition3 + 1);
	int minute = atoi(date_string.substr(strPosition3 + 1, strPosition4).c_str());
	date.setMinute(minute);

	int second = atoi(date_string.substr(strPosition4 + 1, date_string.length()).c_str());
	date.setSecond(second);

	return stream;
}

bool Date::operator==(const Date &date) {
	if (year == date.year && month == date.month && day == date.day
		&& hour == date.hour && minute == date.minute && second == date.second) {
		return true;
	} else { 
		return false;
	}
}

bool Date::operator< (const Date &rhs) {
	if (year > rhs.year) {
		return false;
	} else if (year < rhs.year) {
		return true;
	} else if (month > rhs.month) {
		return false;
	} else if (month < rhs.month) {
		return true;
	} else if (day > rhs.day) {
		return false;
	} else if (day < rhs.day) {
		return true;
	} else if (hour > rhs.hour) {
		return false;
	} else if (hour < rhs.hour) {
		return true;
	} else if (minute > rhs.minute) {
		return false;
	} else if (minute < rhs.minute) {
		return true;
	} else if (second >= rhs.second) {
		return false;
	} 
	return true;
}

