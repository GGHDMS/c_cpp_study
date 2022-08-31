#pragma once
#include <iostream>
//#include "116p.SmartPointer.h"
#include <memory> // auto_ptr쓰기 위한 헤더파일
using namespace std;

class Light {
private:
	bool _stat;
public:
	Light() : _stat(false) { cout << "call " << __FUNCTION__ << endl; }
	~Light() { cout << "call " << __FUNCTION__ << endl; }
	void setOn() { _stat = true; }
	void setOff() { _stat = false; }
	bool getStat() { return _stat; }
};

inline void room_ctl(auto_ptr<Light>& r, bool on = true) {
	//on ? r->setOn() : r->setOff();
	//on ? (&r)->setOn() : (&r)->setOff();
	on ? (*r).setOn() : (*r).setOff();
}