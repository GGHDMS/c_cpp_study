#pragma once


class ConnectionPool
{
	static ConnectionPool *cp;
	ConnectionPool();
public:
	static ConnectionPool * getInstance();
	virtual ~ConnectionPool();
	//static void destroy();
};

