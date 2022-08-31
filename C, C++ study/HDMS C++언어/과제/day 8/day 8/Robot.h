#pragma once
class Robot {
private:
	char *name;
	int energy;
	void errPrn();
public:
	Robot();
	~Robot();
	Robot(const char *name, int energy = 0);
	Robot(Robot &r);
	void go();
	void back();
	void turn();
	void jump();
	void charge(int e);
	char * getName();
	void setName(const char *);
	int getEnergy();
	void setEnergy(int);
};
