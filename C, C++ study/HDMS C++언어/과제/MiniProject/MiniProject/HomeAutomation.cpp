#include "HomeAutomation.h"
#include <iostream>
using namespace std;

HomeAutomation::HomeAutomation() {
	int i;
	for (i = 0; i< APPLIANCE_MAX_CNT; i++) {
		applianceArray[i] = 0;
	}
	applianceCnt = 0;
} // appliaceArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, applianceCnt�� 0���� �ʱ�ȭ
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
} // applianceArray�� ���� �Ҵ�� ��ü�� ��� ������

				   // getter, setter member function
Appliance **HomeAutomation::getApplianceArray() {
	return applianceArray;
} // applianceArray ��� �� ��ȯ �Լ�
int HomeAutomation::getApplianceCnt() const {
	return applianceCnt;
} // applianceCnt ��� �� ��ȯ �Լ�

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
} // ����(�Ҵ�)������ �����ε� �Լ�
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
}	// ������ǰ�� ��Ͽ� �߰�.  ������ ��ǰ�� �߰� �Ұ���. 
int HomeAutomation::searchMachine(string machineName) {
	int i;
	for (i = 0; i < applianceCnt; i++) {
		if (machineName == applianceArray[i]->getMachineName()) {
			return i;
		}
	}
	return -1;
} // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
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
} // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
void HomeAutomation::listDisplayAppliance() {
	int i;
	for (i = 0; i < applianceCnt; i++) {
		applianceArray[i]->stateView();
	}
} // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
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
	cout << "�ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�." << endl;
	return false;
}   // �ش� ������ǰ�� �����ϴ�
void HomeAutomation::setStateAppliance(Appliance * ap) {
	int temp;
	if (RiceCooker * r = dynamic_cast <RiceCooker *> (ap)) {
		while (1) {
			cout << "1. ������ / 2. ���� / 3. ������ / 4. ����� / 5. ���� : ";
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
			cout << "1. ������ / 2. �Ϲݻ��� / 3. �������� / 4. ���� / 5. ���� : ";
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
			cout << "1. ��ǳ / 2. �ù� / 3. ���� / 4. ���� : ";
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
} // �����ִ� ������ǰ�� ���¸� �����ϴ�