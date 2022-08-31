#include "Appliance.h"

Appliance::Appliance(): machineName(""){
	powerConsumption = 0;
	powerFlag = false;
	startHour = 0;
	useHour = 0;
}// default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag , time_t startHour, time_t useHour):machineName(machineName) {
	this->powerConsumption = powerConsumption;
	this->powerFlag = powerFlag;
	this->startHour = startHour;
	this->useHour = useHour;
} // getter, setter member function
string Appliance::getMachineName() const {
	return machineName;
}// machineName 멤버값 반환 함수
bool Appliance::getPowerFlag() const {
	return powerFlag;
} // powerFlag 멤버 값 반환 함수 
int Appliance::getPowerConsumption() const {
	return powerConsumption;
} // powerConsumtion 멤버 값 반환 함수
time_t Appliance::getStartHour() {
	return startHour;
} // startHour 멤버 값 반환 함수
time_t Appliance::getUseHour() {
	return useHour;
} // useHour 멤버 값 반환 함수
void Appliance::setMachineName(string machineName) {
	this->machineName = machineName;
}  // machineName 멤버 초기화 함수
void Appliance::setPowerFlag(bool powerFlag) {
	this->powerFlag = powerFlag;
} // powerFlag 멤버 초기화 함수 
void Appliance::setPowerConsumption(int powerConsumption) {
	this->powerConsumption = powerConsumption;
} // powerConsumtion 멤버 초기화 함수
// member fucntion
bool Appliance::turnOn() {
	if (powerFlag == false) {
		powerFlag = true;
		this->startHour = clock() / 1000;
		return true;
	}
	else {
		return false;
	}
} // 제품을 켜다
bool Appliance::turnOff() {
	if (powerFlag == true) {
		powerFlag = false;
		this->useHour += clock() / 1000 - this -> startHour;
		return false;
	}
	else {
		return true;;
	}
} // 제품을 끄다