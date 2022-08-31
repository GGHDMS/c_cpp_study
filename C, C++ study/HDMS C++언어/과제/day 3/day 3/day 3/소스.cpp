#include <stdio.h>
#include <string.h>

int main() {
	char ch[20];
	fgets(ch, 20, stdin);
	printf("%s", ch);
}