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
}// machineName ����� ��ȯ �Լ�
bool Appliance::getPowerFlag() const {
	return powerFlag;
} // powerFlag ��� �� ��ȯ �Լ� 
int Appliance::getPowerConsumption() const {
	return powerConsumption;
} // powerConsumtion ��� �� ��ȯ �Լ�
time_t Appliance::getStartHour() {
	return startHour;
} // startHour ��� �� ��ȯ �Լ�
time_t Appliance::getUseHour() {
	return useHour;
} // useHour ��� �� ��ȯ �Լ�
void Appliance::setMachineName(string machineName) {
	this->machineName = machineName;
}  // machineName ��� �ʱ�ȭ �Լ�
void Appliance::setPowerFlag(bool powerFlag) {
	this->powerFlag = powerFlag;
} // powerFlag ��� �ʱ�ȭ �Լ� 
void Appliance::setPowerConsumption(int powerConsumption) {
	this->powerConsumption = powerConsumption;
} // powerConsumtion ��� �ʱ�ȭ �Լ�
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
} // ��ǰ�� �Ѵ�
bool Appliance::turnOff() {
	if (powerFlag == true) {
		powerFlag = false;
		this->useHour += clock() / 1000 - this -> startHour;
		return false;
	}
	else {
		return true;;
	}
} // ��ǰ�� ����