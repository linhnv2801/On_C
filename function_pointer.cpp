#include <iostream>
// function prototypes
int foo();
double goo();
int hoo(int x);

int main()
{
	// function pointer assignments
	int (*fcnPtr1)() = foo; // okay
	//int (*fcnPtr2)() = goo; // wrong -- return types don't match!
	double (*fcnPtr4)() = goo; // okay
	//fcnPtr1 = hoo; // wrong -- fcnPtr1 has no parameters, but hoo() does
	int (*fcnPtr3)(int) = hoo; // okay

	return 0;
}
