#include <iostream>
 
int foo() // code starts at memory address 0x002717f0
{
    return 5;
}
 
int main()
{
    std::cout << reinterpret_cast<void*>(foo); // Tell C++ to interpret function foo as a void pointer
 
    return 0;
}
