#include <iostream>

using namespace std;
 
void func(int * a)
{
	std::cout << "STDIO: " << a << endl;
}
 
int main()
{
//	func(3);
	int x = 3, y = 5;
	int arr[10] = {1,2,3,4};
	int ar[5][5] = {1,2,3,4,5,6,7,8,9,10};
	int **p4 = ar;
	int &r4 = ar;
	int &r2 = arr[0];
	int *p3 = arr; 
	cout << p3[3] << endl;
	cout << arr[3] << endl;
	cout << (r2+3) << endl;
	int &r = x;
//	int &rr;
	int *pp;
	int *p = &r;
	int *& p2 = p;
	r = 4;
	r = y;
	*p = 6;
	*p2 = 7;
	cout << "x = " << x << endl;
	func(p);
	func(&r);
	cout << &r << endl;
	
	return 0;
}
