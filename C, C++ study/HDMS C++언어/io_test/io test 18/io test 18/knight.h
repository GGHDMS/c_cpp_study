#include"Charactor.h"

class knight :public Charactor
{
public:
	static const string name;
	knight();
	virtual ~knight();
	void fight();
};