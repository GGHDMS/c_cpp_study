#include <iostream>
using namespace std;

void quick_sort(char *a[], int low, int high) {
	if (low >= high) { // ���Ұ� 1���� ��� 
		return; 
	} 
	int pivot = low; 
	int i = pivot + 1; // ���� ��� ���� 
	int j = high; // ������ ��� ���� 
	char* temp; 
	while(i <= j){ // �����Ͱ� ������������ �ݺ� 
		while(i <= high && (strcmp(a[i], a[pivot]) != 1)){ i++; } 
		while(j > low&& (strcmp(a[j], a[pivot]) != -1)){ j--; } 
		if(i > j){ // ������ 
			temp = a[j]; 
			a[j] = a[pivot]; 
			a[pivot] = temp; 
}
		else{ // i��°�� j��°�� ���� 
			temp = a[i]; 
			a[i] = a[j]; 
			a[j] = temp; 
		} 
	} // ���� ��� 
	quick_sort(a, low, j - 1); 
	quick_sort(a, j + 1, high); 
}
