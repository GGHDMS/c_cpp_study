#include <iostream>
using namespace std;
#include <vector>
int main(){
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	cout << "[vector ��ü���� ������ ���� ���]" << endl;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
		*iter += 1;
	}
	cout << "[vector ��ü���� ������ ���� ���]" << endl;
	iter = v.end();

	do {
		iter--;
		cout << *iter << endl;
	} while (iter != v.begin());

	iter = v.begin();

	cout << endl << "vector ��ü �������� ���� ���� ��� ]" << endl;
	unsigned int i;

	for (i = 0; i < v.size(); i++) {
		cout << iter[i] << endl;
	}

	cout << endl;
	cout << "[iterator�� ���� �� ��� ]" << endl;
	iter += 2;
	cout << *iter << endl << endl;

	cout << "[�ٸ� iterator�� �̿��� ��� ]" << endl;
	vector<int>::iterator iter2 = iter + 2;
	cout << *iter << endl;
	return 0;
}