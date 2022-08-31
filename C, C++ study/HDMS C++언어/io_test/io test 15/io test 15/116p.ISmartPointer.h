#pragma once
template <class T>
struct Isp {
	virtual ~Isp() { }
	virtual T* operator->() const = 0;
	virtual T* operator&() const = 0;
	virtual T& operator*() const = 0;
};  