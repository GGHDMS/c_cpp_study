#pragma once // 중복 INCLUDE 예방 명령
#include<iostream>
using namespace std;
class MyString {
private:
	char *str; // 문자열을 연결할 포인터멤버
	int len; // 문자열의 길이를 저장
public:
	MyString(); // 디폴트 생성자
	MyString(const char *cp); // 오버로디드 생성자
	MyString(const MyString &br); // 복사 생성자
	~MyString(); // 소멸자
	MyString &operator=(const MyString &br); // 대입연산자 멤버함수
	MyString operator+(const MyString &br); // 덧셈 연산자
	bool operator>(const MyString &br); // 관계연산자 멤버함수(길이 비교)
										//void operator<<(ostream &os);
										//void operator>>(istream &is);
	friend ostream &operator<<(ostream &os, MyString &br); // 출력 일반함수
	friend istream &operator>>(istream &is, MyString &br); // 입력 일반함수
														   // getter, setter 멤버함수 추가
	void setStr(const char *cp);
	char *getStr(void) const;
	int getLen(void) const;
};