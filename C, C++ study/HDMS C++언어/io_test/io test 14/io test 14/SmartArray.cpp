#include "SmartArray.h"

bool SmartArray::put(int index, int val) {
	if (MyArray::put(index, val)) {
		if (val > max) {
			max = val;
		}
		return true;
	}
	else {
		return false;
	}
}
int SmartArray::getMax() {
	return max;
}
bool SmartArray::operator>(const SmartArray &br) {
	return max > br.max;
}