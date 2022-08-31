#include <stdio.h>

void shell_sort(int num[], int len);
void tracer(int num[], int len);

int main(void) {
	int testArr[] = { 485,241,454,325,452,685,498,890,281 };
	int len = sizeof(testArr) / sizeof(int);
	shell_sort(testArr, len);
}

void shell_sort(int num[], int len) {
	int i, j, m, tempINT;
	int k = len;
	do {
		k = k / 3 + 1; // ���� ������ k/3 + 1�� ����
		printf("���� k = %d\n", k); // ������ �����ش�.
		for (m = 0; m<k; m++) { //m�� �� ������ ù �ε����� �ȴ�.
			for (i = m + k; i<len; i += k) {
				// ���������� ù��° ���Ҹ� ���ĵ� ������ ������
				// ���� ù ���ؽ��� m+k�� �ȴ�.
				tempINT = num[i];
				for (j = i - k; num[j] > tempINT && j >= 0; j -= k) {
					num[j + k] = num[j];
				}
				num[j + k] = tempINT;
				// ������ �κ��� ���� ���İ� ����.
			}
		}
		tracer(num, len);
	} while (k != 1); // k�� 1�� �Ǹ�, �� �̻� ������ �ʿ� ����
}

void tracer(int num[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", num[i]);
	}
	printf("\n\n");
}