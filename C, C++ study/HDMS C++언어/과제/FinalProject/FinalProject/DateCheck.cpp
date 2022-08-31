#include "DateCheck.h"

Check::Check(int date) {
	day = date % 100;
	month = (date % 10000) / 100;
	year = date / 10000;
	check = false;
}
void Check::realCheck(){
	int num;
	int calc_month[12] = { 31 , 28 , 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31 };
	num = leapCheck();
	if (num == 366){
		if (year >= 1900 && month == 2 && 0< day && day <= 29){
			check = true;
		}
		else if (year >= 1900 && 0 < month && month < 13 && 0 < day && day <= calc_month[month - 1]){
			check = true;
		}
		else{
			;
		}
	}
	else{
		if (year >= 1900 && 0 < month && month < 13 && 0 < day && day <= calc_month[month - 1]){
			check = true;
		}
	}
}
int Check::leapCheck(){
if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0){
				return 366;
			}
			else{
				return 365;
			}
		}
		else{
			return 366;
		}
	}
	else{
		return 365;
	}
}