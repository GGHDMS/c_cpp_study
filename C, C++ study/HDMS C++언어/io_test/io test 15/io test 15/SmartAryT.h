#pragma once
#include "MyAryT.h"

template <class T>
class SmartArray : public MyArray<T> {
private:
	T max;
public:
	SmartArray() : max(0) { }
	SmartArray(int s) : MyArray<T>(s), max(0) { }


	bool put(int index, T val);
	T getMax();

	bool operator>(const SmartArray<T> &ref);
};

template <class T>
bool SmartArray<T>::put(int index, T val) {
	if (!MyArray<T>::put(index, val)) {
		return false;
	}
	if (val > max)
		max = val;
	return true;
}
template <class T>
T SmartArray<T>::getMax() {
	return max;
}
template <class T>
bool SmartArray<T>::operator>(const SmartArray<T> &ref) {
	return this->max > ref.max ? true : false;
}