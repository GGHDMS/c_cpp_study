//수강생 허석문 HW12
#include <iostream>
using namespace std;

class Save {
private:
	char name[20];
	int capital;
	int profit;
	int tax;
	int tot;
	static double ratio;
public:
	static double tax_ratio;
	Save(const char *np = "아무개", int n = 0);
	void calculate();
	static void set_ratio(double r);
	void getter()const;
};

double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;

Save::Save(const char *np, int n) {
	strcpy(this->name, np);
	this->capital = n;
}
void Save::calculate() {
	this->profit = this->capital*ratio;
	this->tax = this->profit*this->tax_ratio;
	this->tot = capital + profit - tax;
}
void Save::set_ratio(double r) {
	ratio = r;
}
void Save::getter()const {
	cout << "이름 : " << name << endl;
	cout << "원금 : " << capital << endl;
	cout << "이자소득 : " << profit << endl;
	cout << "세금 : " << tax << endl;
	cout << "총금액 : " << tot << endl;
	cout << "이율 : " << ratio << endl;
	cout << "세율 : " << tax_ratio << endl;
}

int main() {
	Save a("철이", 1000000), b("메텔", 2000000);
	a.calculate();
	a.getter();
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	cout << endl;
	b.calculate();
	b.getter();
	return 0;
}