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
		k = k / 3 + 1; // 다음 간격을 k/3 + 1로 구함
		printf("간격 k = %d\n", k); // 간격을 보여준다.
		for (m = 0; m<k; m++) { //m은 각 묶음의 첫 인덱스가 된다.
			for (i = m + k; i<len; i += k) {
				// 삽입정렬은 첫번째 원소를 정렬된 것으로 간주함
				// 따라서 첫 인텍스는 m+k가 된다.
				tempINT = num[i];
				for (j = i - k; num[j] > tempINT && j >= 0; j -= k) {
					num[j + k] = num[j];
				}
				num[j + k] = tempINT;
				// 나머지 부분은 삽입 정렬과 같다.
			}
		}
		tracer(num, len);
	} while (k != 1); // k가 1이 되면, 더 이상 정렬할 필요 없음
}

void tracer(int num[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\t", num[i]);
	}
	printf("\n\n");
}