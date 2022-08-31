#include <iostream>
using namespace std;

class Person {
	char name[20];
	int age;
public:
	Person(); //default cons.(기본생성자)
	Person(const char *np /* = "noname" 하면 default 생성자가 2개 되서 오류 */, int a /*= 0 */); // overloaded cons. (일반생성자)
	~Person(); //destructor(소멸자) - 전달인자는 무조건 void (전체 클래스 내에 소멸자는 오직 1개)
	// ~Person(int) 불가 !!! 소멸자는 전달인자 가질수 없다.
	char * getName() { return name; } // 자동으로 inline 함수로 인식 함
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
	cout << "소멸자 수행 중..." << endl;
}

int main() {
	Person ob1;
	Person ob2("이순신", 25);
	//Person ob3("을지문덕");
	Person ob4(ob2); // coypy cons. 로 객체 생성 (compiler가 제공한 copy cons. 사용 - 얕은 복사)

	cout << ob1.getName() << " " << ob1.getAge() << "세" << endl;
	cout << ob2.getName() << " " << ob2.getAge() << "세" << endl;
	cout << ob4.getName() << " " << ob4.getAge() << "세" << endl;

	return 0;
}









