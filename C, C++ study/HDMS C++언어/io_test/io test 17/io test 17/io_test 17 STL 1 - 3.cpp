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
	cout << "[vector 객체내의 데이터 정순 출력]" << endl;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
		*iter += 1;
	}
	cout << "[vector 객체내의 데이터 역순 출력]" << endl;
	iter = v.end();

	do {
		iter--;
		cout << *iter << endl;
	} while (iter != v.begin());

	iter = v.begin();

	cout << endl << "vector 객체 데이터의 임의 접근 출력 ]" << endl;
	unsigned int i;

	for (i = 0; i < v.size(); i++) {
		cout << iter[i] << endl;
	}

	cout << endl;
	cout << "[iterator의 변경 후 출력 ]" << endl;
	iter += 2;
	cout << *iter << endl << endl;

	cout << "[다른 iterator를 이용한 출력 ]" << endl;
	vector<int>::iterator iter2 = iter + 2;
	cout << *iter << endl;
	return 0;
}