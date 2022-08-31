#include "HomeAutomation.h"
#include <iostream>
using namespace std;

HomeAutomation::HomeAutomation() {
	int i;
	for (i = 0; i< APPLIANCE_MAX_CNT; i++) {
		applianceArray[i] = 0;
	}
	applianceCnt = 0;
} // appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
HomeAutomation::HomeAutomation(const HomeAutomation &r) {
	int i;
	for (i = 0; i < r.applianceCnt; i++) {
		if (dynamic_cast <RiceCooker *> (r.applianceArray[i])) {
			applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		}
		else if (dynamic_cast <Washer *> (r.applianceArray[i])) {
			applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		}
		else {
			applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		}
	}
	for (i = r.applianceCnt; i < APPLIANCE_MAX_CNT; i++ ) {
		applianceArray[i] = 0;
	}
	applianceCnt = r.applianceCnt;
} // deep copy constructor
HomeAutomation::~HomeAutomation() {
	int i;
	for (i = 0; i < APPLIANCE_MAX_CNT; i++) {
		delete applianceArray[i];
	}
} // applianceArray에 동적 할당된 객체를 모두 해제함

				   // getter, setter member function
Appliance **HomeAutomation::getApplianceArray() {
	return applianceArray;
} // applianceArray 멤버 값 반환 함수
int HomeAutomation::getApplianceCnt() const {
	return applianceCnt;
} // applianceCnt 멤버 값 반환 함수

							 // member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r) {
	if (this == &r)return *this;
	int i;
	for (i = 0; i < applianceCnt; i++) {
		delete applianceArray[i];
	}
	for (i = 0; i < r.applianceCnt; i++) {
		if (dynamic_cast <RiceCooker *> (r.applianceArray[i])) {
			applianceArray[i] = new RiceCooker(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		}
		else if (dynamic_cast <Washer *> (r.applianceArray[i])) {
			applianceArray[i] = new Washer(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		}
		else {
			applianceArray[i] = new AirConditioner(r.applianceArray[i]->getMachineName(), r.applianceArray[i]->getPowerConsumption());
		}
	}
	for (i = r.applianceCnt; i < APPLIANCE_MAX_CNT; i++) {
		applianceArray[i] = 0;
	}
	applianceCnt = r.applianceCnt;
	return *this;
} // 대입(할당)연산자 오버로딩 함수
bool HomeAutomation::addAppliance(Appliance *ap) {
	if (applianceCnt >= APPLIANCE_MAX_CNT) {
		return false;
	}
	int i;
	for (i = 0; i < applianceCnt; i++) {
		if (ap->getMachineName() == applianceArray[i]->getMachineName()) {
			return false;
		}
	}
	applianceArray[applianceCnt] = ap;
	applianceCnt++;
	return true;
}	// 가전제품을 목록에 추가.  동일한 제품명 추가 불가능. 
int HomeAutomation::searchMachine(string machineName) {
	int i;
	for (i = 0; i < applianceCnt; i++) {
		if (machineName == applianceArray[i]->getMachineName()) {
			return i;
		}
	}
	return -1;
} // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
bool HomeAutomation::deleteAppliance(string machineName) {
	int i;
	for (i = 0; i < applianceCnt; i++) {
		if (machineName == applianceArray[i]->getMachineName()) {
			delete applianceArray[i];
			break;
		}
	}
	if (i == applianceCnt) {
		return false;
	}
	for (i; i < applianceCnt - 1; i++) {
		applianceArray[i] = applianceArray[i + 1];
	}
	applianceCnt--;
	return true;
} // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
void HomeAutomation::listDisplayAppliance() {
	int i;
	for (i = 0; i < applianceCnt; i++) {
		applianceArray[i]->stateView();
	}
} // 등록된 가전제품 전체 목록 및 상태를  확인하다
bool HomeAutomation::controlAppliance(string machineName) {
	int i;
	for (i = 0; i < applianceCnt; i++) {
		if (applianceArray[i]->getMachineName() == machineName) {
			if (applianceArray[i]->getPowerFlag() == false) {
				applianceArray[i]->turnOn();
			}
			setStateAppliance(applianceArray[i]);
			applianceArray[i]->stateView();
			return true;
		}
	}
	cout << "해당하는 제품이 존재하지 않습니다." << endl;
	return false;
}   // 해당 가전제품을 제어하다
void HomeAutomation::setStateAppliance(Appliance * ap) {
	int temp;
	if (RiceCooker * r = dynamic_cast <RiceCooker *> (ap)) {
		while (1) {
			cout << "1. 무동작 / 2. 보온 / 3. 밥짓기 / 4. 데우기 / 5. 끄기 : ";
			cin >> temp;
			myFlush();
			if (0 < temp && temp < 6) {
				break;
			}
		}
		if (temp == 5) {
			r->turnOff();
			r->setMachineState(r->NO_OPERATION);
		}
		else {
			r->setMachineState(temp);
		}
	}
	else if (Washer * r = dynamic_cast <Washer *> (ap)) {
		while (1) {
			cout << "1. 무동작 / 2. 일반빨래 / 3. 삶은빨래 / 4. 건조 / 5. 끄기 : ";
			cin >> temp;
			myFlush();
			if (0 < temp && temp < 6) {
				break;
			}
		}
		if (temp == 5) {
			r->turnOff();
			r->setMachineState(r->NO_OPERATION);
		}
		else {
			r->setMachineState(temp);
		}
	}
	else if (AirConditioner *r = dynamic_cast <AirConditioner *> (ap)) {
		while (1) {
			cout << "1. 송풍 / 2. 냉방 / 3. 난방 / 4. 끄기 : ";
			cin >> temp;
			if (0 < temp && temp < 5) {
				break;
			}
		}
		if (temp == 4) {
			r->turnOff();
			r->setMachineState(r->SENDAIR);
		}
		else {
			r->setMachineState(temp);
		}
	}
	else {
		;
	}
} // 켜져있는 가전제품의 상태를 변경하다