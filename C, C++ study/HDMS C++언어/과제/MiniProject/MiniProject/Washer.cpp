#include "Washer.h"

Washer::Washer():Appliance(){
	machineState = NO_OPERATION;
} // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
Washer::Washer(string machineName, int powerConsumption):Appliance(machineName, powerConsumption) {
	machineState = NO_OPERATION;
} // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
												  // getter, setter member function
int Washer::getMachineState() const {
	return machineState;
} // machineState ��� �� ��ȯ �Լ�
void Washer::setMachineState(int machineState) {
	this->machineState = machineState;
} // machineState ��� �ʱ�ȭ �Լ�
										// member function
void Washer::stateView() {
	cout << "��ǰ�� : " << getMachineName() << " (";
	if (getPowerFlag() == false) {
		cout << "OFF";
	}
	else {
		cout << "ON";
	}
	cout << ") ";
	if (getPowerFlag() == true) {
		if (machineState == NO_OPERATION) {
			cout << "�������� : ������";
		}
		else if (machineState == GENERAL) {
			cout << "�������� : �Ϲݻ���";
		}
		else if (machineState == BOIL) {
			cout << "�������� : ��������";
		}
		else {
			cout << "�������� : ����";
		}
	}
	cout << endl;
}  // ��ü�� ���� ���