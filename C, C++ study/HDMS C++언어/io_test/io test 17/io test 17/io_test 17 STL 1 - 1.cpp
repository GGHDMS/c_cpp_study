#include <iostream>
using namespace std;
#include <vector>
int main() {
	vector<int>v;
	unsigned int i;

	cout << "vector��ü ������ �߰� �� ���� ���� : " << v.size() << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "vector��ü ������ �߰� �� ���� ���� : " << v.size() << endl;
	cout << "vector ��ü�� ������ 5�� �߰� �� ���" << endl;

	for (i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	v.pop_back();
	v.pop_back();

	cout << "vector ��ü���� ������ 2�� ���� �� ���" << endl;
	for (i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}