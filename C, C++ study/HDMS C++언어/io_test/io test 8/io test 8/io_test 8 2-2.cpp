#include <iostream>
using namespace std;

class MoneyBox {
private:
	//char name[20];
	char *name;
	int sum;
public:
	MoneyBox();
	MoneyBox(const char *np, int m = 0);
	MoneyBox(const MoneyBox &br);
	~MoneyBox() { 
		cout << name << " �Ҹ��� ������..." << endl;
		delete[] this -> name;
	} // �Ҹ���
	void setName(const char *np);
	void save(int m);
	void use(int m);
	void prn();
};

MoneyBox::MoneyBox() {
	this->name = new char[strlen("�ƹ���") + 1];
	strcpy(this->name, "�ƹ���");
	this->sum = 0;
	cout << "����Ʈ ������ ȣ��..." << this->name << endl;
}

MoneyBox::MoneyBox(const char *np, int m) {
	this->name = new char[strlen(np) + 1];
	strcpy(this->name, np);
	this->sum = m;
	cout << "�����ε�� ������ ȣ��..." << this->name << endl;
}

MoneyBox::MoneyBox(const MoneyBox &br) {
	this->name = new char[strlen(br.name) + 1];
	strcpy(this->name, br.name);
	this->sum = br.sum;
	cout << "���� ������ ȣ��..." << this->name << endl;
}

void MoneyBox::setName(const char *np) {	
	if (this->name != NULL) { // �޸� ���� ����
		delete[] name;
	}
	if (np != NULL) {
		name = new char[strlen(np) + 1];
		strcpy(name, np);
	}
	else {
		;
	}
}

void MoneyBox::save(int m) {
	if (m >= 0) { this->sum += m; }
}

void MoneyBox::use(int m) {
	if (m > 0 && m <= this->sum) { this->sum -= m; }
}

void MoneyBox::prn() {
	cout << "�̸� : " << this->name << endl;
	cout << "�ܾ� : " << this->sum << endl;
}

MoneyBox &func(MoneyBox &m);

int main() {
	MoneyBox a;
	MoneyBox b("ȫ�浿");
	MoneyBox c("�̼���", 500);
	MoneyBox d = b;
	MoneyBox *mp1 = new MoneyBox("ȫ�浿");
	MoneyBox *mp2 = new MoneyBox(c);
	cout << "=========================================================" << endl;
	func(b);

	c.prn();
	delete mp1;
	delete mp2;

	c.setName("��������");
	c.prn();
	return 0;
}

MoneyBox &func(MoneyBox &m) {
	return m;
}










