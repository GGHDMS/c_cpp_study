#include <iostream>
using namespace std;

class Person {
	char name[20];
	int age;
public:
	Person(); //default cons.(�⺻������)
	Person(const char *np /* = "noname" �ϸ� default �����ڰ� 2�� �Ǽ� ���� */, int a /*= 0 */); // overloaded cons. (�Ϲݻ�����)
	~Person(); //destructor(�Ҹ���) - �������ڴ� ������ void (��ü Ŭ���� ���� �Ҹ��ڴ� ���� 1��)
	// ~Person(int) �Ұ� !!! �Ҹ��ڴ� �������� ������ ����.
	char * getName() { return name; } // �ڵ����� inline �Լ��� �ν� ��
	int getAge() { return age; } 
};

Person::Person(){
	strcpy(name, "noname");
	age = 0;
}

Person::Person(const char *np, int a) {
	if (np == NULL) {
		strcpy(name, "noname");
	}
	else {
		strcpy(name, np);
	}
	if (a < 0) {
		age = 0;
	}
	else{
		age = a;
	}
}

Person::~Person() {
	cout << "�Ҹ��� ���� ��..." << endl;
}

int main() {
	Person ob1;
	Person ob2("�̼���", 25);
	//Person ob3("��������");
	Person ob4(ob2); // coypy cons. �� ��ü ���� (compiler�� ������ copy cons. ��� - ���� ����)

	cout << ob1.getName() << " " << ob1.getAge() << "��" << endl;
	cout << ob2.getName() << " " << ob2.getAge() << "��" << endl;
	cout << ob4.getName() << " " << ob4.getAge() << "��" << endl;

	return 0;
}









