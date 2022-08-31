#pragma once // �ߺ� INCLUDE ���� ���
#include<iostream>
using namespace std;
class MyString {
private:
	char *str; // ���ڿ��� ������ �����͸��
	int len; // ���ڿ��� ���̸� ����
public:
	MyString(); // ����Ʈ ������
	MyString(const char *cp); // �����ε�� ������
	MyString(const MyString &br); // ���� ������
	~MyString(); // �Ҹ���
	MyString &operator=(const MyString &br); // ���Կ����� ����Լ�
	MyString operator+(const MyString &br); // ���� ������
	bool operator>(const MyString &br); // ���迬���� ����Լ�(���� ��)
										//void operator<<(ostream &os);
										//void operator>>(istream &is);
	friend ostream &operator<<(ostream &os, MyString &br); // ��� �Ϲ��Լ�
	friend istream &operator>>(istream &is, MyString &br); // �Է� �Ϲ��Լ�
														   // getter, setter ����Լ� �߰�
	void setStr(const char *cp);
	char *getStr(void) const;
	int getLen(void) const;
};