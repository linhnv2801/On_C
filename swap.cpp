#include <iostream>
//#include <vector>

template <class T> swap(T& a, T& b){
	T tmp(a);
	a = b;
	b = tmp;
}

int main(){
	int x = 10, y = 20;
	swap(x, y);
	
	std::cout << "x = " << x << "\t" << "y = " << y << "\n"; 
	return 0;
}
