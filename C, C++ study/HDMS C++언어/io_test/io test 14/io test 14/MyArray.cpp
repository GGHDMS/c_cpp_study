#include "MyArray.h"

MyArray::MyArray(int s){
	ary = new int[s];
	size = s;
}
MyArray::MyArray(const MyArray &br){
	int i;
	size = br.size;
	ary = new int[size];
	for (i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
}
MyArray& MyArray::operator=(const MyArray &br){
	if (this == &br)return *this;
	int i;
	delete[]ary;
	size = br.size;
	ary = new int[size];
	for (i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
	return *this;
}
bool MyArray::put(int index, int val){
	if (0 <= index && index < size) {
		ary[index] = val;
		return true;
	}
	else {
		return false;
	}
}
bool MyArray::get(int index, int &getdata){
	if (0 <= index && index < size) {
		getdata = ary[index];
		return true;
	}
	else {
		return false;
	}
}
int MyArray::getSize(){
	return size;
}
int *MyArray::getAry(void){
	return ary;
}

