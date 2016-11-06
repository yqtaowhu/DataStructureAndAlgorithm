//Date		: 2016.11.6
//Autore	: yqtao
/*
	string 类的实现
*/
#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
class String {
private:
	char* _data;
public:
	String(const char* str = nullptr);
	String(const String& rhs) :_data(new char[rhs.size() + 1]) {
		strcpy(_data, rhs._data);
	}
	String& operator=(const String& rhs);
	~String() {
		if (_data != nullptr) {
			delete[]_data;
			_data = nullptr;
		}
		//delete[]_data;
	}
	void Swap(String rhs) {
		std::swap(_data, rhs._data);
	}
	size_t size() const {
		return strlen(_data);
	}
private:
	//重载操作符
	char&  operator[](int index);
	friend ostream& operator<<(ostream &os, const String &rhs);
	friend istream& operator >> (istream &is, String &rhs);
	friend String operator+(const String& lhs, const String& rhs);
	friend String operator+=(String& lhs,const String& rhs);   //注意这里不能声明成const
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);
	friend bool operator>(const String &lhs, const String &rhs);
	friend bool operator>=(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);
	friend bool operator<=(const String &lhs, const String &rhs);
};
String::String(const char* str) {       //构造函数，默认的输入为空
	if (str == nullptr) {
		_data = new char[1];
		*_data = '\0';
	}
	else {
		_data = new char[strlen(str) + 1];
		strcpy(_data, str);
	}
}
//
String& String::operator=(const String& rhs) {
	if (this == &rhs) {
		return *this;
	}
	delete[]_data;
	_data = new char[rhs.size() + 1];
	strcpy(_data, rhs._data);
}
/*
	其他的写法：
	//2. copy and swap技术
	String& operator=(const String& rhs) {
		String temp(rhs);       //利用复制构造函数
		Swap(rhs);
		return *this;
	}
	//3. 传值方式
	String& operator=(String rhs) {
		Swap(rhs);
		return *this;
	}
	//4. c++11右值引用
	String& operator= (String&& rhs) {
		Swap(rhs);
		return *this;
	}
*/
char& String::operator[](int index) {
	return _data[index];
}
ostream& operator<<(ostream &os, const String &rhs) {
	os << rhs._data;
	return os;
}
/*
//注意这里可能会出错，如果有大神这道什么原因，请指教
istream& operator >> (istream &is, String &rhs) {     
	String tmp;
	is >> tmp._data;
	rhs = tmp;
	return is;
}
*/
//重载+
String operator+(const String& lhs, const String& rhs) {
	String res;
	int len = lhs.size() + rhs.size();
	res._data = new char[len + 1];
	strcpy(res._data, lhs._data);
	strcat(res._data, rhs._data);
	return res;
}
//重载+=
String operator+=(String& lhs, const String& rhs) {
	lhs = lhs + rhs;    //利用加法即可完成 
	return lhs;
}
//重载==
bool operator==(const String& lhs, const String& rhs) {
	if (strcmp(lhs._data, rhs._data) == 0) return true;
	return false;
}
bool operator!=(const String& lhs, const String& rhs) {
	if (strcmp(lhs._data, rhs._data) == 0) return false;
	return true;
}
//重载>函数  
bool operator>(const String &lhs, const String &rhs){
	if (strcmp(lhs._data, rhs._data) > 0)
		return true;
	return false;
}
bool operator<(const String &lhs, const String &rhs) {
	if (strcmp(lhs._data, rhs._data) < 0)
		return true;
	return false;
}
//重载<=函数  
bool operator<=(const String &lhs, const String &rhs){
	if (strcmp(lhs._data, rhs._data) <= 0)
		return true;
	return false;
}

//重载>=函数  
bool operator>=(const String &lhs, const String &rhs){
	if (strcmp(lhs._data, rhs._data) >= 0)
		return true;
	return false;
}
#endif // !STRING_H

