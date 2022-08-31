#include <iostream>
#include "ConnectionPool.h"

ConnectionPool::ConnectionPool(){ 
	cp = NULL;
}
ConnectionPool::~ConnectionPool() { ; }
ConnectionPool * ConnectionPool::getInstance() {
	if (cp != NULL) {
		cp = new ConnectionPool();
	}
	return cp;
}