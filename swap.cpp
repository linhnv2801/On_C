#include <iostream>

using namespace std;

void swap(int &x, int &y){
	int tmp = x;
	x = y;
	y = tmp;
}

int main(){
	int x = 10, y = 20;
	swap(x, y);
	
	cout << "x = " << x << "\t" << "y = " << y << "\n"; 
	return 0;
}
