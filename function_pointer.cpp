#include <iostream>
int foo(int x)
{
    return x;
}

void print(int x){
	std::cout << x << "\n";
}
 
int main()
{
    int (*fcnPtr)(int) = foo; // assign fcnPtr to function foo
    (*fcnPtr)(5); // call function foo(5) through fcnPtr.
    
    void (*p) (int) = print;
    (*p)(6);
 
    return 0;
}
