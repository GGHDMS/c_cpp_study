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
	const char * getName() { // 함수가 간단한면 바로 정의해도 된다. // 자동으로 인라인함수로 인식됨
		return name;
	}
	int getAge(void);
};

void Person::setName(/*Person * this, 쓰지 말자 */ const char *np) {
//void Person::setName(Person *this, const char * np)
	if (np == NULL) {
		strcpy(this -> /* 생략 가능 */name, "아무개");
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
	strcpy(this->name, "노네임");
	this->age = 0;
}

Person::Person(const char *ch, int age) {	
	strcpy(name, ch);
	this -> age = age; // this 생략 불가
}

void setName(const char *np) {
	cout << "extern 함수 setName : " << np << endl;
}

int main() {
	/*Person ob1, ob2;
	ob1.setAge(100);
	cout << "나이 : " << ob1.getAge() << endl;
	ob1.setAge(-1);
	cout << "나이 : " << ob1.getAge() << endl;
	ob1.setName("홍길동");
	cout << "이름 : " << ob1.getName() << endl;
	ob1.setName(NULL);
	cout << "이름 : " << ob1.getName() << endl;

	setName("꼽등이");*/
	Person ob1;
	Person ob2("강감찬", 35);

	cout << ob1.getName() << endl;
	cout << ob1.getAge() << endl;
	cout << ob2.getName() << endl;
	cout << ob2.getAge() << endl;
}




















