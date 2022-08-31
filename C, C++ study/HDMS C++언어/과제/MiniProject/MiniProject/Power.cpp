#include "HomeAutomation.h"
#include "Power.h"

int Power::calPowerConsumption(HomeAutomation &rHa) {
	int tot = 0 , i;
	for (i = 0; i < rHa.applianceCnt; i++) {
		if (rHa.applianceArray[i]->getPowerFlag() == false) {
			tot += rHa.applianceArray[i]->getUseHour() * rHa.applianceArray[i]->getPowerConsumption() / 3600;
		}
	}
	return tot;
}