#include <iostream>
#include <algorithm>
#include <vector>

template <class T> void swap(T& a, T& b){
	T tmp(a);
	a = b;
	b = tmp;
}

void print( int i){
	std::cout << i << "\t";
}

// Sum a vector of some type.
// Example:
// int total = sum({1,2,3,4,5});
template <typename T>
T sum(const std::vector<T>& vec) {
    T total = T();
    for (const T& x : vec) {
        total += x;
    }
    return total;
}

template <typename T>
T sum(const T x, T y){
	return (x + y);
}

int main(){
	std::vector<int> v(4,100);
	for_each(v.begin(), v.end(), print);
	std::cout << "\n";
	int total = sum(std::vector<int> (4,100));
	std::cout << total << "\n";
	std::cout << sum(3,4) << "\n";
	std::cout << sum(3.9,4.6) << "\n";
	
	return 0;
}
