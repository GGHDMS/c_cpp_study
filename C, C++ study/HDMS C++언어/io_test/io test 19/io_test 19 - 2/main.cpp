#include <iostream>
using namespace std;
#include "ConnectionPool.h"

int main() {
	ConnectionPool *pool = ConnectionPool::getInstance();
	ConnectionPool *pool2 = ConnectionPool::getInstance();
	cout << pool << endl;
	cout << pool2 << endl;
	return 0;
}