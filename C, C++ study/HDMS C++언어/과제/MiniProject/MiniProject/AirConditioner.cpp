#include "AirConditioner.h"

AirConditioner::AirConditioner():Appliance(){
	machineState = SENDAIR; 
	setTemperature = 25;

} // Appliance�� default �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
AirConditioner::AirConditioner(string machineName, int powerConsumption):Appliance(machineName, powerConsumption) {
	machineState = SENDAIR;
	setTemperature = 25;
}// Appliance�� Overloaded �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
														 // getter, setter member function
int AirConditioner::getMachineState() const {
	return machineState;
} // machineState ����� ��ȯ �Լ�
int AirConditioner::getSetTemperature() const {
	return setTemperature;
}  // setTemperature ����� ��ȯ �Լ�
void AirConditioner::setMachineState(int machineState) {
	this->machineState = machineState;
} // machineState ��� �ʱ�ȭ �Լ�
void AirConditioner::setSetTemperature(int setTemperature) {
	this->setTemperature = setTemperature;
} // setTemperature ��� �ʱ�ȭ �Լ�
											// member function
AirConditioner & AirConditioner::operator++() {
	setTemperature++;
	return *this;
} // ���� �µ��� 1���� �ø���(prefix increment)
AirConditioner & AirConditioner::operator--() {
	setTemperature++;
	return *this;
} // ���� �µ��� 1���� ������(prefix decrement)
void AirConditioner::stateView() {
	cout << "��ǰ�� : " << getMachineName() << " (";
	if (getPowerFlag() == false) {
		cout << "OFF";
	}
	else {
		cout << "ON";
	}
	cout << ") ";
	if (getPowerFlag() == true) {
		if (machineState == SENDAIR) {
			cout << "�������� : ��ǳ";
		}
		else if (machineState == COOLER) {
			cout << "�������� : �ù�";
		}
		else {
			cout << "�������� : ����";
		}
	}
	cout << endl;
}  // ��ü�� ���� ���