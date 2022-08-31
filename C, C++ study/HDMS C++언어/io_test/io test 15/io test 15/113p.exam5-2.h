#pragma once

template <typename Type>  // 형 매개변수는 Type 
class Temp{  
private:  
	Type num;  
public:  
	Temp(Type n);  // 생성자  
	void put(Type n);  // 값 저장  
	Type get();  // 값 확인 
}; 
 // 멤버함수 템플릿, 해당 클래스를 지정할 때 형 매개변수를 사용한다. 

template <typename Type> 
Temp<Type>::Temp(Type n) {
	num=n; 
} 

template <typename Type> 
void Temp<Type>::put(Type n) {
	num = n; 
} 

template <typename Type> 
Type Temp<Type>::get() {
	return num; 
}
