#include "StudentStack.h"

int main() {
	StudentStack stack;
	stack.push(Student(20180403, "허석문", "스마트시스템소프트웨어학과"));
	stack.push(Student(20180402, "홍길동", "스마트시스템소프트웨어학과"));
	stack.display();
	stack.pop();
	stack.display();
	return 0;
}