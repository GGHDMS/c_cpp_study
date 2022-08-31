#include <iostream>
using namespace std;

void quick_sort(char *a[], int low, int high) {
	if (low >= high) { // 원소가 1개인 경우 
		return; 
	} 
	int pivot = low; 
	int i = pivot + 1; // 왼쪽 출발 지점 
	int j = high; // 오른쪽 출발 지점 
	char* temp; 
	while(i <= j){ // 포인터가 엇갈릴때까지 반복 
		while(i <= high && (strcmp(a[i], a[pivot]) != 1)){ i++; } 
		while(j > low&& (strcmp(a[j], a[pivot]) != -1)){ j--; } 
		if(i > j){ // 엇갈림 
			temp = a[j]; 
			a[j] = a[pivot]; 
			a[pivot] = temp; 
}
		else{ // i번째와 j번째를 스왑 
			temp = a[i]; 
			a[i] = a[j]; 
			a[j] = temp; 
		} 
	} // 분할 계산 
	quick_sort(a, low, j - 1); 
	quick_sort(a, j + 1, high); 
}
