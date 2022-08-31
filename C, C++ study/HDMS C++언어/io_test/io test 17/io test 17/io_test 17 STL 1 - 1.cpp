#include <iostream>
using namespace std;
#include <vector>
int main() {
	vector<int>v;
	unsigned int i;

	cout << "vector객체 데이터 추가 전 원소 개수 : " << v.size() << endl;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "vector객체 데이터 추가 후 원소 개수 : " << v.size() << endl;
	cout << "vector 객체에 데이터 5개 추가 후 출력" << endl;

	for (i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	v.pop_back();
	v.pop_back();

	cout << "vector 객체에서 데이터 2개 삭제 후 출력" << endl;
	for (i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}