#include "StudentStack.h"

int main() {
	StudentStack stack;
	stack.push(Student(20180403, "�㼮��", "����Ʈ�ý��ۼ���Ʈ�����а�"));
	stack.push(Student(20180402, "ȫ�浿", "����Ʈ�ý��ۼ���Ʈ�����а�"));
	stack.display();
	stack.pop();
	stack.display();
	return 0;
}