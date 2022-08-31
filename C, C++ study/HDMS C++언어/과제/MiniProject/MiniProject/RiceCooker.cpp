#include "RiceCooker.h"

RiceCooker::RiceCooker(): Appliance() {
	machineState = NO_OPERATION;
} // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
RiceCooker::RiceCooker(string machineName, int powerConsumption):Appliance(machineName, powerConsumption) {
	machineState = NO_OPERATION;
} // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
													  // getter, setter member function
int RiceCooker::getMachineState() const {
	return machineState;
} // machineState 멤버 값 반환 함수
void RiceCooker::setMachineState(int machineState) {
	this->machineState = machineState;
} // machineState 멤버 초기화 함수
										// member function
void RiceCooker::stateView() {
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
		else if (machineState == WARM) {
			cout << "설정상태 : 보온";
		}
		else if (machineState == COOK) {
			cout << "설정상태 : 밥짓기";
		}
		else {
			cout << "설정상태 : 데우기";
		}
	}
	cout << endl;
} // 객체의 상태 출력