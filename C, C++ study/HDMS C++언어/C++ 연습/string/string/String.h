#include <iostream>
using namespace std;

class String {
	char *_buf;
	int _size;
public:
	String();
	String(const char *s);
	String(const String &s);
	~String();
	int size()const;
	char &at(int index);
	String &assign(const char *s);
	int compare(const String &s);
	int compare(const char *s);
	char &operator[](int index);
	String operator+ (const String &str);
	String operator+(const char *str);
	String&operator=(const String &str);
	String &operator=(const char *str);
	bool operator>(const String &s);
	bool operator<(const String &s);
	bool operator==(const String &s);
	bool operator!=(const String &s);
	bool operator>(const char *s);
	bool operator<(const char *s);
	bool operator==(const char *s);
	bool operator!=(const char *s);
	friend std::ostream&operator<<(std::ostream&os, String &s);
	friend std::istream&operator>>(std::istream &is, String &s);
	friend String operator+(const char *s, const String &str);

};