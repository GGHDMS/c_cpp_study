#include "AirConditioner.h"

AirConditioner::AirConditioner():Appliance(){
	machineState = SENDAIR; 
	setTemperature = 25;

} // Appliance는 default 생성자로 생성, machineState는 송풍으로 초기화
AirConditioner::AirConditioner(string machineName, int powerConsumption):Appliance(machineName, powerConsumption) {
	machineState = SENDAIR;
	setTemperature = 25;
}// Appliance는 Overloaded 생성자로 생성, machineState는 송풍으로 초기화
														 // getter, setter member function
int AirConditioner::getMachineState() const {
	return machineState;
} // machineState 멤버값 반환 함수
int AirConditioner::getSetTemperature() const {
	return setTemperature;
}  // setTemperature 멤버값 반환 함수
void AirConditioner::setMachineState(int machineState) {
	this->machineState = machineState;
} // machineState 멤버 초기화 함수
void AirConditioner::setSetTemperature(int setTemperature) {
	this->setTemperature = setTemperature;
} // setTemperature 멤버 초기화 함수
											// member function
AirConditioner & AirConditioner::operator++() {
	setTemperature++;
	return *this;
} // 설정 온도를 1도씩 올린다(prefix increment)
AirConditioner & AirConditioner::operator--() {
	setTemperature++;
	return *this;
} // 설정 온도를 1도씩 내린다(prefix decrement)
void AirConditioner::stateView() {
	cout << "제품명 : " << getMachineName() << " (";
	if (getPowerFlag() == false) {
		cout << "OFF";
	}
	else {
		cout << "ON";
	}
	cout << ") ";
	if (getPowerFlag() == true) {
		if (machineState == SENDAIR) {
			cout << "설정상태 : 송풍";
		}
		else if (machineState == COOLER) {
			cout << "설정상태 : 냉방";
		}
		else {
			cout << "설정상태 : 난방";
		}
	}
	cout << endl;
}  // 객체의 상태 출력