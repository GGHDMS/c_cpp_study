#include"FightWithAx.h"
#include"knight.h"

int main()
{
	knight *kp = new knight();
	kp->fight();
	kp->setWay(new FightWithAx());
	kp->fight();
	return 0;
}