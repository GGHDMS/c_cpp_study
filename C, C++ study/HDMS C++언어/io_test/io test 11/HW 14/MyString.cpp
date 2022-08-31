#include "MyString.h"

MyString::MyString() {
	str = new char[strlen("") + 1];
	strcpy(str, "");
	len = 0;
	//cout << __FUNCTION__ << "()" << endl;
}
MyString::MyString(const char *cp) {
	len = strlen(cp);
	str = new char[len + 1];
	strcpy(str, cp);
}
MyString::MyString(const MyString &br) {
	len = br.len;
	str = new char[len + 1];
	strcpy(str, br.str);
}
MyString::~MyString() {
	delete[]str;
}
MyString &MyString::operator=(const MyString &br) {
	if (this == &br) { return *this; }
	delete[]str;
	len = br.len;
	str = new char[len + 1];
	strcpy(str, br.str);
	return *this;
}
MyString MyString::operator+(const MyString &br) {

	/*char temp[500];
	strcpy(temp, str);
	strcat(temp, br.str);
	return MyString(temp);*/

	char *cp;
	cp = new char[len + br.len + 1];
	strcpy(cp, str);
	strcat(cp, br.str);
	MyString temp(cp);
	delete[]cp; // 메모리 누수 조심
	return temp;
}
bool MyString::operator>(const MyString &br) {
	//return len > br.len; // 길이 비교
	return strcpy(str, br.str); // 스펠링 비교
}	
void MyString::setStr(const char *cp) {
	if (cp == this->str) { return; }//본인의 문자열로 str을 갱신하려고 하면 
	delete[]str;
	len = strlen(cp);
	str = new char[len + 1];
	strcpy(str, cp);
}
char * MyString::getStr(void)const {
	return str;
}
int MyString::getLen(void)const {
	return len;
}
