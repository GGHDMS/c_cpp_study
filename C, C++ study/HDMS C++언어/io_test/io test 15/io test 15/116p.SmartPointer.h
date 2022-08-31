#pragma once
#include "116p.ISmartPointer.h"

template <class T>
class my_sp : public Isp<T> {
private:
	T *ptr;
public:
	my_sp(T *p) : ptr(p) { }
	~my_sp() { delete ptr; }
	T* operator->() const { return ptr; }
	T* operator&() const { return ptr; }
	T& operator*() const { return *ptr; }
};