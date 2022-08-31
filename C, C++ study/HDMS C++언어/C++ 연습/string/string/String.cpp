#include "String.h"

String::String() {
	_buf = NULL;
	_size = 0;
}
String::String(const char *s) {
	_size = strlen(s);
	_buf = new char[_size + 1];
	strcpy(_buf, s);
}
String::String(const String &s) {
	_size = strlen(s._buf);
	_buf = new char[_size + 1];
	strcpy(_buf, s._buf);
}
String::~String() {
	delete[] _buf;
}
int String::size()const {
	return _size;
}
char &String::at(int index) {
	return _buf[index];
}
String& String::assign(const char *s) {
	delete[]_buf;
	_buf = new char[strlen(s) + 1];
	strcpy(_buf, s);
	return *this;
}
int String::compare(const String &s) {
	return strcmp(_buf, s._buf);
}
int String::compare(const char *s) {
	return strcmp(_buf, s);
}
char &String::operator[](int index) {
	return _buf[index];
}
String String::operator+(const String &str) {
	String s;
	s._size = _size + str._size;
	s._buf = new char[s._size + 1];
	strcpy(s._buf, _buf);
	strcat(s._buf, str._buf);
	return s;
}
String String::operator+(const char *str) {
	String s;
	s._size = _size + strlen(str);
	s._buf = new char[s._size + 1];
	strcpy(s._buf, _buf);
	strcat(s._buf, str);
	return s;
}
String &String::operator=(const String &str) {
	if (*this == str) {
		return *this;
	}
	delete[]_buf;
	_size = str._size;
	_buf = new char[_size + 1];
	strcpy(_buf, str._buf);
	return *this;
}
String &String::operator=(const char *str) {
	delete[]_buf;
	_size = strlen(str);
	_buf = new char[_size + 1];
	strcpy(_buf, str);
	return *this;
}
bool String::operator>(const String&s) {
	return strcmp(_buf, s._buf) == -1;
}
bool String::operator<(const String &s) {
	return strcmp(_buf, s._buf) == 1;
}
bool String::operator==(const String &s) {
	return strcmp(_buf, s._buf) == 0;
}
bool String::operator!=(const String&s) {
	return strcmp(_buf, s._buf) != 0;
}
bool String::operator>(const char*s) {
	return strcmp(_buf, s) == -1;
}
bool String::operator<(const char *s) {
	return strcmp(_buf, s) == 1;
}
bool String::operator==(const char *s) {
	return strcmp(_buf, s) == 0;
}
bool String::operator!=(const char *s) {
	return strcmp(_buf, s) != 0;
}
std::ostream&operator<<(std::ostream&os, String &s) {
	os<< s._buf;
	return os;
}
std::istream&operator>>(std::istream &is, String &s) {
	char str[100];
	is >> str;
	delete[]s._buf;
	s._size = strlen(str);
	s._buf = new char[s._size + 1];
	strcpy(s._buf, str);
	return is;
}
String operator+(const char *s, const String &str) {
	String ss;
	ss._size = strlen(s) + str._size;
	ss._buf = new char[ss._size + 1];
	strcpy(ss._buf, s);
	strcat(ss._buf, str._buf);
	return ss;
}
