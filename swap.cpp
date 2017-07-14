#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y){
	x ^= y;
	y ^= x;
	x ^= y;
}

int main(){
	int x = 10, y = 20;
	std::swap(x, y);
	
	cout << "x = " << x << "\t" << "y = " << y << "\n"; 
	return 0;
}
