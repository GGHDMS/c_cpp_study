#include "Washer.h"

Washer::Washer():Appliance(){
	machineState = NO_OPERATION;
} // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
Washer::Washer(string machineName, int powerConsumption):Appliance(machineName, powerConsumption) {
	machineState = NO_OPERATION;
} // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
												  // getter, setter member function
int Washer::getMachineState() const {
	return machineState;
} // machineState 멤버 값 반환 함수
void Washer::setMachineState(int machineState) {
	this->machineState = machineState;
} // machineState 멤버 초기화 함수
										// member function
void Washer::stateView() {
	cout << "제품명 : " << getMachineName() << " (";
	if (getPowerFlag() == false) {
		cout << "OFF";
	}
	else {
		cout << "ON";
	}
	cout << ") ";
	if (getPowerFlag() == true) {
		if (machineState == NO_OPERATION) {
			cout << "설정상태 : 무동작";
		}
		else if (machineState == GENERAL) {
			cout << "설정상태 : 일반빨래";
		}
		else if (machineState == BOIL) {
			cout << "설정상태 : 삶은빨래";
		}
		else {
			cout << "설정상태 : 건조";
		}
	}
	cout << endl;
}  // 객체의 상태 출력