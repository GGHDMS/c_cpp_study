#include <iostream>
using namespace std;

class Person {
private:
	char name[20];
	int age;
public:
	Person(void);
	Person(const char *, int a);
	void setName(const char *np);
	void setAge(int a);
	const char * getName() { // �Լ��� �����Ѹ� �ٷ� �����ص� �ȴ�. // �ڵ����� �ζ����Լ��� �νĵ�
		return name;
	}
	int getAge(void);
};

void Person::setName(/*Person * this, ���� ���� */ const char *np) {
//void Person::setName(Person *this, const char * np)
	if (np == NULL) {
		strcpy(this -> /* ���� ���� */name, "�ƹ���");
	}
	else {
		strcpy(this -> name, np);
	}
}

void Person::setAge(int a) {
	if (a < 0) {
		age = 0;
	}
	else {
		age = a;
	}
}

int Person::getAge() {
	return age;
}

Person::Person() {
	strcpy(this->name, "�����");
	this->age = 0;
}

Person::Person(const char *ch, int age) {	
	strcpy(name, ch);
	this -> age = age; // this ���� �Ұ�
}

void setName(const char *np) {
	cout << "extern �Լ� setName : " << np << endl;
}

int main() {
	/*Person ob1, ob2;
	ob1.setAge(100);
	cout << "���� : " << ob1.getAge() << endl;
	ob1.setAge(-1);
	cout << "���� : " << ob1.getAge() << endl;
	ob1.setName("ȫ�浿");
	cout << "�̸� : " << ob1.getName() << endl;
	ob1.setName(NULL);
	cout << "�̸� : " << ob1.getName() << endl;

	setName("�ŵ���");*/
	Person ob1;
	Person ob2("������", 35);

	cout << ob1.getName() << endl;
	cout << ob1.getAge() << endl;
	cout << ob2.getName() << endl;
	cout << ob2.getAge() << endl;
}




















