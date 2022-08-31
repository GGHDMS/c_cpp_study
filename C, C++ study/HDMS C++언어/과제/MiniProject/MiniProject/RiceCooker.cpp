#include "RiceCooker.h"

RiceCooker::RiceCooker(): Appliance() {
	machineState = NO_OPERATION;
} // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
RiceCooker::RiceCooker(string machineName, int powerConsumption):Appliance(machineName, powerConsumption) {
	machineState = NO_OPERATION;
} // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
													  // getter, setter member function
int RiceCooker::getMachineState() const {
	return machineState;
} // machineState ��� �� ��ȯ �Լ�
void RiceCooker::setMachineState(int machineState) {
	this->machineState = machineState;
} // machineState ��� �ʱ�ȭ �Լ�
										// member function
void RiceCooker::stateView() {
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
		else if (machineState == WARM) {
			cout << "�������� : ����";
		}
		else if (machineState == COOK) {
			cout << "�������� : ������";
		}
		else {
			cout << "�������� : �����";
		}
	}
	cout << endl;
} // ��ü�� ���� ���