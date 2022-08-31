#include <iostream>
using namespace std;
#include <new>

int main() {
	int *ip;
	int num = 0;
	try {
		while (1)
		{
			ip = new int[1000000];
			++num;
			cout << num << "번 할당 성공" << endl;
		}
	}
	/*catch(bad_alloc &ex){
		cout << ex.what() << endl;
		cout << "할당불가" << endl;
	}*/
	catch (exception &ex) {
		cout << ex.what() << endl;
		cout << "할당불가" << endl;
	}
}