#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
private:
	T *ary;
	int size;
public:
	MyArray() { ary = NULL, size = 0; }
	MyArray(int s);
	MyArray(const MyArray &br); // parameter자리에 <T>는 선택
	virtual ~MyArray() { delete[] ary; }

	MyArray& operator=(const MyArray<T> &br); // parameter자리에 <T>는 선택
	virtual bool put(int index, T val);
	bool get(int index, T &getdata);
	int getSize();
	T* getAry();
};

template <class T>
MyArray<T>::MyArray(int s) : size(s) {
	ary = new T[size];
	for (int i = 0; i < size; i++) {
		ary[i] = 0;
	}
}
template <class T>
MyArray<T>::MyArray(const MyArray &br) : size(br.size) {
	ary = new T[size];
	for (int i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
}
template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T> &br) {
	if (this == &br)
		return *this;
	delete[] this->ary;
	this->size = br.size;
	ary = new T[size];
	for (int i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
	return *this;
}
template <class T>
bool MyArray<T>::put(int index, T val) {
	if (index >= size || index < 0) {
		cout << "out of binary" << endl;
		return false;
	}
	ary[index] = val;
	return true;
}
template <class T>
bool MyArray<T>::get(int index, T &getdata) {
	if (index >= size || index < 0) {
		cout << "out of binary" << endl;
		return false;
	}
	getdata = ary[index];
	return true;
}
template <class T>
int MyArray<T>::getSize() {
	return size;
}
template <class T>
T* MyArray<T>::getAry() {
	return ary;
}