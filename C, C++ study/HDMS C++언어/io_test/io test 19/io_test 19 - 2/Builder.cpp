#include "Builder.h"

Builder::Builder()
{
	computer = new Computer("기본컴퓨터", "기본처리장치", 4, 50000);
}


Builder::~Builder()
{
}

Builder *Builder::getInstance() {
	if (instance == NULL) {
		instance = new Builder();
	}
	return instance;
}

Computer *Builder::setComputer() {
	return computer;
}
Builder * Builder::getPrdName(string prdName) {
	computer->setPrdName(prdName);
	return this;
}
