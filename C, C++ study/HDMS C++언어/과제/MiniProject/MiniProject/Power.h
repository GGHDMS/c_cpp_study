#ifndef __POWER_H__
#define __POWER_H__
#include "Appliance.h"

class HomeAutomation;  // ���漱��(foward ����)

class Power
{
public :
	Power(){};
	int calPowerConsumption(HomeAutomation &rHa);  // ���� ��ǰ�� ���� �Ҹ��� ������
};
#endif