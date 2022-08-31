#pragma once
#include <cstring>

template <class Type>
Type max(Type &a, Type &b) {
	return (a > b) ? a : b;
}

template <>
const char* max(const char *&a, const char *&b) {
	if (strcmp(a, b) > 0) return a;
	else return b;
}
